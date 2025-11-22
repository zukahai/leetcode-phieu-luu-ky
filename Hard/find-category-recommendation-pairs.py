import pandas as pd

def find_category_recommendation_pairs(product_purchases: pd.DataFrame, product_info: pd.DataFrame) -> pd.DataFrame:
    df = product_purchases[["user_id", "product_id"]].merge(product_info[["product_id", "category"]], how = "left", on = "product_id")
    df = df.merge(df, on = "user_id").iloc[:, [0, 2, 4]].drop_duplicates().rename(columns= {"category_x": "category1", "category_y": "category2"})
    df = df[df["category1"] < df["category2"]].groupby(["category1", "category2"]).count().reset_index().rename(columns = {"user_id" : "customer_count"})
    return df[df["customer_count"] >= 3].sort_values(by = ["customer_count", "category1", "category2"], ascending = [0, 1, 1])
    