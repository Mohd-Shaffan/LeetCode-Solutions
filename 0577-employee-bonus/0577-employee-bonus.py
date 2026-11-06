import pandas as pd

def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    s=pd.merge(employee,bonus,on="empId",how="left")
    return s[(s.bonus<1000) | (s.bonus.isna())][['name','bonus']]
    