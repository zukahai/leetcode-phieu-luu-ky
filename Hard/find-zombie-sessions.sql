SELECT
    session_id, user_id, 
    timestampdiff(minute, min(event_timestamp), max(event_timestamp))
    AS session_duration_minutes,
    SUM(CASE WHEN event_type = 'scroll' then 1 else 0 end) AS scroll_count
FROM app_events
GROUP BY session_id, user_id
HAVING
    timestampdiff(minute, min(event_timestamp), max(event_timestamp)) > 30 AND
    SUM(CASE WHEN event_type='scroll' then 1 else 0 end) >= 5 AND
    SUM(CASE WHEN event_type='click' then 1 else 0 end) / SUM(CASE WHEN event_type='scroll' then 1 else 0 end) < 0.20 AND
    SUM(CASE WHEN event_type='purchase' then 1 else 0 end) = 0
ORDER BY scroll_count DESC, session_id