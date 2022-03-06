def function(digit):
    tem = {}
    for i in digit:
        day = '/'.join(i['發病日'].split('/')[:2])
        city = i['居住縣市']
        if day in tem.keys():
            if city in tem[day].keys():
                tem[day][city] += 1
            else:
                tem[day][city] = 1
        else:
            tem[day] = {city: 1}
    list1 = []
    for x in tem.items():
        dict1 = {'發病日': x[0]}
        dict1.update(x[1])
        list1.append(dict1)
    return list1


'''
定義一個名叫function的函式(傳入digit)
先宣告tem的空dict
用for迴圈去跑digit
宣告day(digit裡的'發病日'先以 / 作split 在使 年 月 日 變成 年 月 最後 在年月中間加入 / )
宣告city為digit裡的'居住縣市'
如果day在tem中keys裡的話
再去討論兩種情況
如果city在tem的key(名為day)裡的key中，使tem[day][city]的value值再加1
否則使tem[day][city]的value值為1
如果day不在tem中keys裡的話
則使tem中新建一個key和value,舉例:{ '1998/01' : { "屏東縣": 2.....} } 
再用一個for迴圈使以上的資料改變儲存方式，存入list1,舉例:list1=[{'發病日': '1998/01', '屏東縣': 2,....}, {'發病日': '1998/02', '台南市': 1, ....}...],
在函式最後回傳list1
'''
import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as infile:
    # 開檔(模式為讀)
    digit = json.load(infile)
    # 用digit存取檔案內的資料
    digit_finsh = function(digit)
    # digit傳入function的函式，用digit_finsh存取
with open('Result.json', 'w', encoding='utf-8-sig') as outfile:
    # 開檔(模式為寫)
    json.dump(digit_finsh, outfile, indent=4, ensure_ascii=False)
