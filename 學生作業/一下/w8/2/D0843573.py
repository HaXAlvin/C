# 讀json
import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as file:
    variable = json.load(file)


# 撰寫一個副程式來統計此檔案的內容
def function():
    # 新增一個空list
    listt = []
    # 新增一個空dict
    dictt = {}
    # 判斷日期
    month = '1998/01'
    for i in range(len(variable)):
        # 從一月開始
        if variable[i]['發病日'][0:7] == month:
            dictt['發病日'] = month
            # 若城市在此月份已經出現過，再加一
            if variable[i]['居住縣市'] in dictt:
                dictt[variable[i]['居住縣市']] = dictt[variable[i]['居住縣市']] + 1
            # 新增沒有出現過的城市
            else:
                dictt[variable[i]['居住縣市']] = 1
        # 跳至下一個月份
        elif variable[i]['發病日'][0:7] != month:
            # 新增dict
            listt.append(dictt)
            # 清空dict
            dictt = {}
            # 更新month的值
            month = variable[i]['發病日'][0:7]
            # 存到dict
            dictt['發病日'] = month
            # 城市在此月份已經出現過，再加一
            if variable[i]['居住縣市'] in dictt:
                dictt[variable[i]['居住縣市']] = dictt[variable[i]['居住縣市']] + 1
            # 新增沒有的城市
            else:
                dictt[variable[i]['居住縣市']] = 1
        # 處理十月的情況
        if i == len(variable) - 1:
            listt.append(dictt)
    # 回傳值
    return listt


# 寫json
with open('Result.json', 'w') as outfile:
    json.dump(function(), outfile, indent=4)
