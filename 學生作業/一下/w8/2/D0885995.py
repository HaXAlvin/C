def f(inp):
    lenn = len(inp)  # 長度
    out = []  # 結果的list
    d1 = {}  # 輸入的字典
    year2 = 1998  # 暫存年分
    mon2 = 1  # 暫存年分
    day2 = 0  # 暫存日子
    flag = 1  # 控制是否重複縣市的flag
    count = 0  # 判斷第幾個
    n = inp[0]["發病日"]  # 第一筆資料的發病日
    b = n.split('/')  # 第一筆資料的發病年月日
    d1 = {"發病日": str(b[0]) + '/' + str(b[1])}  # 加入第一筆資料的發病日
    out.append(d1)
    for i in range(0, lenn):  # 跑全部資料的迴圈
        n = inp[i]["發病日"]
        m = inp[i]["居住縣市"]
        p = inp[i]["確定病例數"]
        a = n.split('/')  # 將年月日分開
        print(a)
        year1 = int(a[0])  # 先存第一次年
        mon1 = int(a[1])  # 先存第一次月
        mon = a[1]  # 拿來列印用的月
        day1 = int(a[2])  # 先存第一次天
        d2 = {}
        if mon1 > mon2 or year1 > year2:  # 下個月或下一年
            d1 = {"發病日": str(year1) + '/' + str(mon)}
            out.append(d1)
            count += 1
            mon2 = mon1
        if mon1 <= mon2:  # 同一個月
            for k in range(count, count + 1):  # 重複縣市
                if out[k].get(m) is not None:  # 判斷是否重複縣市
                    flag = 0
                    d1[m] = int(d1[m]) + 1  # 重複加一
                    break
            if flag == 1:  # 沒有重複
                d1[m] = int(p)
            flag = 1
        year2 = year1  # 更新暫存
        mon2 = mon1  # 更新暫存
        day2 = day1  # 更新暫存
    with open('Result.json', 'w', encoding='utf-8-sig') as file:  # 輸出json
        json.dump(out, file, ensure_ascii=False, indent=4)


import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    inpu = json.load(outfile)
    f(inpu)
