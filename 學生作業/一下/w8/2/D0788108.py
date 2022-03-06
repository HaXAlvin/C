# -*- coding:utf-8 -*-
import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    jf = json.load(outfile)


def cal(f):
    # 把全部地區的數值存在一個dictionary裡
    All_place = {'台北市': 0, '新北市': 0, '桃園市': 0, '台中市': 0, '台南市': 0, '高雄市': 0, '新竹縣': 0, '苗栗縣': 0, '彰化縣': 0,
                 '南投縣': 0, '雲林縣': 0, '嘉義縣': 0, '屏東縣': 0, '花蓮縣': 0, '台東縣': 0,
                 '澎湖縣': 0, '金門縣': 0, '連江縣': 0, '新竹市': 0, '嘉義市': 0, '宜蘭縣': 0, '基隆市': 0}
    # 用來存最後回傳的data
    data = list()
    # 設定一開始的日期
    date = f[0].get('發病日')[:7]

    for i in f:
        # 當不相等時代表上一個用的已經結束了
        if date != i.get('發病日')[:7]:
            temp = {'發病日': date}
            for j in All_place:
                # 把所有value不是0的都丟到temp裡面
                if All_place.get(j):
                    temp.update({j: All_place.get(j)})

            data.append(temp)
            # 把值都歸零
            for j in All_place:
                All_place[j] = 0
            # 把date換成下個月
            date = i.get('發病日')[:7]

        All_place[i.get('居住縣市')] += 1
    temp = {'發病日': date}
    for j in All_place:
        if All_place.get(j):
            temp.update({j: All_place.get(j)})
    data.append(temp)
    return data


r = cal(jf)
with open('Result.json', 'w', encoding='utf-8') as file:
    # 不寫ensure_ascii會有編碼的問題
    json.dump(cal(jf), file, ensure_ascii=False, indent=4)
