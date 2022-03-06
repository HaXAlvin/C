def statistics(data: list):  # 統整資料的函式
    datanum = int(len(data))  # 檔案總共幾筆資料
    redata = list()  # 統整後儲存的list
    tmp = dict()  # 暫存的dict
    for i in range(datanum):  # 從第一筆資料跑到最後一筆
        date = data[i]['發病日'][:7]  # 日期
        s = data[i]['居住縣市']  # 居住地
        count = int((len(redata)))  # 統整後的list有幾筆資料
        if count == 0:  # 統整後第一筆資料
            tmp = {'發病日': date, s: 1}
            redata.append(tmp)
        else:
            count = count - 1
            if date == redata[count]['發病日']:  # 該筆日期已新增在統整list
                if s in redata[count]:  # 該居住地已新增在統整list
                    redata[count][s] += 1  # 所以直接數量+1
                else:  # 該居住地尚未新增
                    redata[count][s] = 1  # 新增該居住地為key
            else:  # 該日期尚未新增
                tmp = {'發病日': date, s: 1}  # 在統整的list裡新增一個dict
                redata.append(tmp)
    return redata


import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 讀取欲統整數據
    data: list = json.load(outfile)
redata = statistics(data)  # 呼叫函式統整
with open('Result.json', 'w', encoding='utf-8-sig') as outfile:  # 輸出統整後的資料為json檔
    json.dump(redata, outfile, ensure_ascii=False, indent=4)
