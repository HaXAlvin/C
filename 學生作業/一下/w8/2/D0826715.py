import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    data = json.load(outfile)  # 開檔

datas = []
dates = ''
dict = {}

'''for i in data:
    print(i, '\n')'''

for i in data:  # 讀檔回圈
    if dates != i['發病日'][0:7]:
        if dict:
            datas.append(dict)
        dict = {}
        dates = i['發病日'][0:7]
        dict['發病日'] = dates
    if i['居住縣市'] in dict:  # 如果該地區有病發就+1否則就不動
        dict[i['居住縣市']] += 1
    else:
        dict[i['居住縣市']] = 1
datas.append(dict)  # 把讀到的資料加入dataslist裏

with open('Result.json', 'w') as outfile:  # 建檔
    json.dump(datas, outfile, indent=4)
