def lun(list1):
    data = json.load(outfile)
    list1 = []
    date = set()  # 發病月份
    datelist = []  # 發病月份list
    for i in data:
        date.add(i['發病日'][0:7])  # 新增發病日期至set()
    datelist = sorted(list(date))  # 排序

    for j in range(len(datelist)):
        list1.append({'發病日': datelist[j]})  # 新增至list1

    for i in data:
        for j in range(len(datelist)):
            if i['發病日'][0:7] == datelist[j]:
                if i['居住縣市'] in list1[j]:  # 有相同縣市則加一
                    list1[j][i['居住縣市']] += 1
                else:  # 發病縣市第一次出現的情況
                    list1[j][i['居住縣市']] = 1
    return list1


import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    result = []
    result = lun(result)
with open('Result.json', 'w') as output:  # 寫檔
    json.dump(result, output, indent=4)
