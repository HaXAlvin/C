def find(A):  # 副函式
    OD = "1998/01"
    dict1 = {}
    l = []
    for i in range(len(A)):

        if A[i]['發病日'][0:7] == OD:
            if A[i]['居住縣市'] in dict1:  # dict已經有此縣市的紀錄
                dict1[A[i]['居住縣市']] += 1  # 記錄在＋1
            else:
                dict1[A[i]['居住縣市']] = 1  # dict沒有此縣市的紀錄
        else:
            l.append(dict1)  # 將此年月份資料記錄到list
            dict1 = {}  # 歸零
            OD = A[i]['發病日'][0:7]
            dict1['發病日'] = OD  # 更改年月
            dict1[A[i]['居住縣市']] = 1  # 第一筆資料
    l.append(dict1)  # 最後一筆資料
    # print(l)
    with open('Result.json', 'w', encoding='utf-8') as outfile:  # 寫檔
        json.dump(l, outfile, ensure_ascii=False, indent=4)


import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 讀檔
    Dengue_Daily = json.load(outfile)
find(Dengue_Daily)
