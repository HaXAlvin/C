import json


def add_up(data):  # 統計資料
    result = []  # 預設一存取資料
    for i in range(len(data)):  # 走訪全部資料
        if i == 0:  # 當為第一筆資料
            stand = data[0].get('發病日')[0:7]  # 將比對資料更新
            temp = {'發病日': stand, data[0].get('居住縣市'): 1}  # 設一個暫存dict，增一個發病日

        elif data[i].get('發病日')[0:7] == stand:  # 往後將比對發病日與stand是否相同
            if data[i].get('居住縣市') in temp:  # 檢查temp key()有沒有相同居住縣市
                temp[data[i].get('居住縣市')] += 1  # 若有則原本人數加一
            else:
                temp[data[i].get('居住縣市')] = 1  # 沒有則新增key且人數為1
        else:  # 若不為前兩個條件
            result.append(temp)  # 先將temp加進list裡
            stand = data[i].get('發病日')[0:7]  # 更新stand
            temp = {'發病日': stand, data[i].get('居住縣市'): 1}  # 新增key且將新發病日期傳入

        if i == len(data) - 1:  # 若為最後一筆資料
            result.append(temp)  # 新增進list
    return result  # 回傳


with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 開檔
    info = json.load(outfile)
    newinfo = add_up(info)
    with open('Result.json', 'w') as op:  # 寫成json
        json.dump(newinfo, op,indent=len(newinfo))
