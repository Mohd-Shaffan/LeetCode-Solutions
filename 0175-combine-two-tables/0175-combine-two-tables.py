import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    s=pd.merge(person,address,on="personId",how="left")
    return s[['firstName','lastName','city','state']]