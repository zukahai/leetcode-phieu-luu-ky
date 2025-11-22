import pandas as pd

def find_study_spiral_pattern(students: pd.DataFrame, study_sessions: pd.DataFrame) -> pd.DataFrame:
    ss = study_sessions.copy()
    ss['session_date'] = pd.to_datetime(ss['session_date'])
    ss['hours_studied'] = pd.to_numeric(ss['hours_studied'])

    ssc = ss.groupby(['student_id', 'subject']).size().reset_index(name='cnt')
    s_stats = ssc.groupby('student_id').agg(subject_count=('subject', 'nunique'), min_cnt=('cnt', 'min')).reset_index()

    ids1 = set(s_stats[(s_stats['subject_count'] > 2) & (s_stats['min_cnt'] > 1)]['student_id'].tolist())
    
    ss_sorted = ss.sort_values(['student_id', 'session_date'])
    ss_sorted['prev_date'] = ss_sorted.groupby('student_id')['session_date'].shift(1)
    ss_sorted['day_gap'] = (ss_sorted['session_date'] - ss_sorted['prev_date']).dt.days

    max_gap = ss_sorted.groupby('student_id')['day_gap'].max().fillna(0).reset_index()
    ids2 = set(max_gap[max_gap['day_gap'] < 3]['student_id'].tolist())
    qual_ids = ids1 & ids2

    if not qual_ids:
        return pd.DataFrame(columns=['student_id', 'student_name', 'major', 'cycle_length', 'total_study_hours'])

    res = ss[ss['student_id'].isin(qual_ids)].groupby('student_id').agg(cycle_length=('subject', 'nunique'), total_study_hours=('hours_studied', 'sum')).reset_index()
    res = res.merge(students[['student_id', 'student_name', 'major']], on='student_id', how='left')

    if len(res) <= 1:
        return pd.DataFrame(columns=['student_id', 'student_name', 'major', 'cycle_length', 'total_study_hours'])

    res = res[['student_id', 'student_name', 'major', 'cycle_length', 'total_study_hours']].sort_values(['cycle_length', 'total_study_hours'], ascending=[False, False]).reset_index(drop=True)
    
    return res