import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 開檔
    dataList = json.load(outfile)  # 建一個list存讀進來的資料


def answer(dataList):  # 副程式
    resultList = []  # 建一個list來存資料
    date = '1998/01'  # 設第一個日期
    dict_new = dict()  # 把dataList的居住縣市的value存到resultList的dict裡的key
    for i in range(len(dataList)-1):  # 用for去跑每個list, i是一個dict
        if dataList[i]['發病日'][:7] == dataList[i + 1]['發病日'][:7]:  # 判斷日期是否重複
            dict_new['發病日'] = date
            if dataList[i]['居住縣市'] not in dict_new:  # 判斷dict_new是否存過此資料
                dict_new[dataList[i]['居住縣市']] = 1  # 將資料存進去
            else:
                dict_new[dataList[i]['居住縣市']] += 1  # 資料重複
            date = dataList[i]['發病日'][:7]  # 設一個暫存存日期
        else:
            resultList.append(dict_new)
            dict_new = dict()  # 把dataList的居住縣市的value存到resultList的dict裡的key
            date = dataList[i]['發病日'][:7]  # 設一個暫存存日期
            dict_new['發病日'] = date
            if dataList[i]['居住縣市'] not in dict_new:  # 判斷dict_new是否存過此資料
                dict_new[dataList[i]['居住縣市']] = 1  # 將資料存進去
            else:
                dict_new[dataList[i]['居住縣市']] += 1  # 資料重複
    resultList.append(dict_new)
    return resultList  # 回傳函示


l = answer(dataList)  # 設一個l來接dataList
with open('Result.json', 'w', encoding='utf-8-sig') as outfile:  # 寫檔
    json.dump(l, outfile, ensure_ascii=False, indent=4)
