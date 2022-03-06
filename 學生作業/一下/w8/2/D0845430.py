import json  # 讀取json檔
with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    cases = json.load(outfile)


def data_cases(list0, list1):  # 用來統計數據的函式
    list2 = []  # 統計用的list
    dict_data = {}  # 一個發病年月一個dict
    for i in range(len(list0)):  # 先統計年月
        if list0[i] != list0[i-1]:  # 若年月沒和上一項重複
            dict_data['Onset date'] = list0[i]  # 新增一個key後再把年月附給這個key
    for i in range(len(list1)):  # 再統計縣市病例數
        for k in range(len(dict_data)):  # 檢查是否有重複
            if list1[i] != list1[k]:  # 若縣市沒和前面某一項重複
                dict_data[list1[k]] = 1  # 新增一個key後再把縣市附給這個key
            else:  # 若縣市和某一項重複
                dict_data[list1[i]] = dict_data[list1[i]] + 1  # 在重複的縣市key上+1
    list2.append(dict_data)  # 新增dict_data到list2
    return list2  # 回傳list2


list_date = []  # 用來存取年月
list_loc = []  # 用來存取地點
for i in range(len(cases)):
    date = cases[i]['發病日']  # 先取出發病日
    date = date[0:7]  # 再取出發病日的年份加月份
    list_date.append(date)  # 新增到list_date
    loc = cases[i]['居住縣市']  # 取出居住縣市
    list_loc.append(loc)  # 新增到list_loc
list_total = data_cases(list_date, list_loc)  # 將list_date和list_loc傳入data_cases函式
with open('Result.json', 'w') as outfile:  # 將回傳值輸出成Result.json
    for i in range(len(list_total)):
        json.dump(list_total, outfile, indent=len(list_total[i]))
