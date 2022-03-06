import json


def jsonOpen(people):
    dictPlus = {}  # 先整理在這個dict
    for data in people:  # 用迴圈跑完整個資料
        if data['發病日'][:7] in dictPlus.keys():  # 先依照發病日期統計縣市
            dictPlus[data['發病日'][:7]].append(data['居住縣市'])  # 如果此發病日有在這字典新增這個縣市
        else:
            dictPlus[data['發病日'][:7]] = [data['居住縣市']]  # 如果沒有就新增縣市
    listA = []  # 存最終結果
    for key, val in dictPlus.items():
        dictA = {'發病日': key}  # 創建字典存整理完的
        for word in val:
            tmp = word  # 暫存存值
            intTmp = val.count(tmp)  # 找相同的縣市有幾個
            if tmp not in dictA.keys():  # 如果這縣市不再這字典
                dictA[tmp] = intTmp  # 新增這縣市跟值
            else:
                continue
        listA.append(dictA)  # 把字典加到最終list
    return listA  # 函式回傳


with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 開檔
    people = json.load(outfile)  # 取值

y = jsonOpen(people)  # 丟進函式

with open('Result.json', 'w', encoding='utf-8-sig') as outfile:  # 開檔
    json.dump(y, outfile, ensure_ascii=False, indent=4)  # 寫檔
