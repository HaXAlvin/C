import json  # 導入 json


def count(listj):  # 定義統計函式
    listnew = []  # 宣告一個list
    dictx = {'發病日': '1998/01'}  # 宣告一個dict
    for i in range(len(listj)):  # 走訪輸入的listj
        if dictx['發病日'] in listj[i]['發病日']:  # 如果dictx中的發病日的字串在listj中的dict中有
            if dictx.get(listj[i]['居住縣市']) is None:  # 如果在dict中沒有listj[i]['居住縣市']一樣的key
                dictx[listj[i]['居住縣市']] = 1  # 新增一個縣市的key並賦值1
            else:  # 有一樣的key(縣市)
                dictx[listj[i]['居住縣市']] = dictx[listj[i]['居住縣市']] + 1  # 該key的值+1
        else:  # lictj中的發病日月份改變
            listnew.append(dictx)  # 原本的dictx存入listnew
            del dictx  # 刪除原本的dictx
            dictx = {}  # 再宣告一個新的dictx
            temp = listj[i]['發病日'][:7]  # 將listj[i]['發病日']中的字串取前面7個賦值給temp
            dictx['發病日'] = temp  # temp賦值給新的dixtx['發病日']
            if dictx.get(listj[i]['居住縣市']) is None:  # 如果在dict中沒有listj[i]['居住縣市']一樣的key
                dictx[listj[i]['居住縣市']] = 1  # 新增一個縣市的key並賦值1
            else:  # 有一樣的key(縣市)
                dictx[listj[i]['居住縣市']] = dictx[listj[i]['居住縣市']] + 1  # 該key的值+1
    return listnew  # 回傳listnew


with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 讀入一個json檔
    Dengue = json.load(outfile)  # Dengue為讀出來的list
    data = count(Dengue)  # data為函釋回傳的list
with open(' Result.json', 'w') as outfile:  # 寫一個新的json檔
    json.dump(data, outfile, indent=4)  # 寫檔
