import pandas as pd
import json


def statistics():
    data = pd.read_json('Dengue_Daily.json', encoding='utf-8-sig')  # 讀json
    result = [{'發病日': ''}]
    k = 0  # 年月index
    # 先將第一筆資料放入result
    result[0]['發病日'] = data['發病日'][0][0:7]
    # 新增新的dict
    result.append({'發病日': ''})
    for i in range(len(data)):
        # 若該日期已放入result裡
        if result[k]['發病日'][0:7] == data['發病日'][i][0:7]:
            # 若該縣市未放入dict
            if result[k].get(data['居住縣市'][i], -1) == -1:
                result[k][data['居住縣市'][i]] = 1  # 放入新的key(縣市)並宣告value = 1
            # 若該縣市已放入dict
            else:
                result[k][data['居住縣市'][i]] = result[k][data['居住縣市'][i]] + 1  # value++
        # 若該日期未放入result裡
        else:
            # 將該日期放入後一個已新增的dict
            result[k + 1]['發病日'] = data['發病日'][i][0:7]
            result.append({'發病日': ''})
            k = k + 1  # 遇到不同年月使result index+1(已排序情況下相同年月會在同一區)
            if result[k].get(data['居住縣市'][i], -1) == -1:
                result[k][data['居住縣市'][i]] = 1
            else:
                result[k][data['居住縣市'][i]] = result[k][data['居住縣市'][i]] + 1
    # 刪除最後的空白dict
    del result[k + 1]
    return result


outfile = open('Result.json', 'w', encoding='utf-8-sig')
json.dump(statistics(), outfile, ensure_ascii=False)
outfile.close()
