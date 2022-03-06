import json

with open('./Dengue_Daily.json', 'r', encoding='utf-8-sig') as file:
    content = json.load(file)  # 開檔
    file.close()


def calculat():
    global content  # 引入全域變數
    data = {}  # 設置一個dict存取發病日期與居住縣市人數
    list1 = []  # 設置一個list來存取所有的dict
    flag = '1998/01'  # 設flag為最一開始的發病日
    for i in content:
        if i['發病日'][0:7] == flag:  # 取前7個就不會取到日且若與前一個資料發病日相同者繼續跑這個dict
            data['發病日'] = flag
            if i['居住縣市'] in data:
                data[i['居住縣市']] += 1  # 若再dict裡有相同的居住縣市 則+1
            else:
                data[i['居住縣市']] = 1  # 若沒有 則=1
            flag = i['發病日'][0:7]
        elif i['發病日'][0:7] != flag:  # 與前一筆資料發病日不同者
            list1.append(data)  # 新增在list尾端
            data = {}  # 將dict清空
            flag = i['發病日'][0:7]  # flag改成新的發病日
            data['發病日'] = flag  # 將發病日存進data
            if i['居住縣市'] in data:
                data[i['居住縣市']] += 1
            else:
                data[i['居住縣市']] = 1
    list1.append(data)  # 最後月份新增
    return list1  # 回傳list1


with open('Result.json', 'w') as outfile:  # 將檔案輸出成json
    json.dump(calculat(), outfile, indent=4)  # 輸出資料list1 且縮排=4
