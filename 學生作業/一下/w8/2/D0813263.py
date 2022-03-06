# 來自助教的程式碼
import json


def file(datas):
    resultDict = {}
    for data in datas:
        if data['發病日'][0:7] not in resultDict:  # 如果年月份不在Dict中，則加入
            resultDict[data['發病日'][0:7]] = {}
        if data['居住縣市'] not in resultDict[data['發病日'][0:7]]:  # 如果居住縣市沒有在年月份中出現過，則給值為0
            resultDict[data['發病日'][0:7]][data['居住縣市']] = 0
        resultDict[data['發病日'][0:7]][data['居住縣市']] += 1  # 如果居住縣市在該年月份出現過，則給值1
    resultList = []
    for month, countys in resultDict.items():  # 從Dict中取資料
        resultList.append({})  # 將Dict中的資料加到List後面
        resultList[-1]["發病日"] = month  # 取月份
        resultList[-1].update(countys)  # 取居住縣市
    return resultList  # 回傳資料


with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as f:  # 開檔讀檔Dengue_Daily.json
    l = json.loads(f.read())
r = file(l)
with open('Result.json', 'w', encoding='utf-8') as f:  # 寫Result.json檔
    json.dump(r, f, ensure_ascii=False, indent=4)
