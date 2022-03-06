import json
import pandas as pd
from collections import Counter


# Modify the date fromat to year/month
def modifyJsonDate():
    # Open json from directory
    file = open('Dengue_Daily.json', 'r', encoding='utf-8-sig')
    cases = json.load(file)

    # Remove day from date
    for case in cases:
        case['發病日'] = case['發病日'][0: 7]

    file = open('Dengue_Daily.json', 'w', encoding='utf-8-sig')
    json.dump(cases, file)
    file.close()


# Dict the city name
def count_city(x):
    return dict(Counter(x))


def groupDataByPanda():
    # Open modified json from directory
    file = open('Dengue_Daily.json', 'r', encoding='utf-8-sig')
    df = pd.read_json(file)

    grouped_data = df.groupby('發病日').agg({
        '居住縣市': [('count', count_city)],
    })

    # Group data and modify DataFrame
    grouped_data.columns = grouped_data.columns.droplevel()
    grouped_data.reset_index(inplace=True)
    data = grouped_data.to_dict('records')
    final_list = [dict({"發病日": x["發病日"]}, **x["count"]) for x in data]

    print(final_list)

    # Return Result.json to directory
    with open(r'Result.json', 'w', encoding='utf-8-sig') as outfile:
        json.dump(final_list, outfile, ensure_ascii=False)


modifyJsonDate()
groupDataByPanda()
