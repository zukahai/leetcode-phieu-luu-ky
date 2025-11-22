import pandas as pd

def analyze_organization_hierarchy(df: pd.DataFrame) -> pd.DataFrame:
    def traverseGraph(mgr: int, lev: int) -> None:
        levl[mgr] = lev
        for emp in grph[mgr]:
            traverseGraph(emp, lev + 1)
            team[mgr] += team[emp] + 1
            bdgt[mgr] += bdgt[emp]
        return

    grph = defaultdict(list)
    levl, team, bdgt = defaultdict(int), defaultdict(int), defaultdict(int)
    boss = df.loc[df.manager_id.isna(), "employee_id"].values[0]
    for mgr, emp, sal in zip(df.manager_id, df.employee_id, df.salary):
        grph[mgr].append(emp)
        bdgt[emp] = sal
    
    traverseGraph(boss, 1)

    df['level'] = df.employee_id.apply(lambda x: levl[x])
    df['team_size' ] = df.employee_id.apply(lambda x: team[x])
    df['budget ' ] = df.employee_id.apply(lambda x: bdgt[x])

    return df.sort_values(['level', 'budget', 'employee_name'], ascending = [1, 0, 1]).iloc[:, [0, 1, 5, 6, 7]]