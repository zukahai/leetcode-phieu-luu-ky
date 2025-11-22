import pandas as pd

def capitalize_content(user_content: pd.DataFrame) -> pd.DataFrame:
    user_content["converted_text"] = user_content["content_text"].apply(format_text)
    user_content.rename(columns={"content_text": "original_text"}, inplace=True)
    return user_content
def convert(word):
    return word[0].upper() + word[1:].lower()
def solve_word(word):
    return "-".join([convert(w) for w in word.split("-")])
def format_text(text):
    return " ".join([solve_word(w) for w in text.split(" ")])