import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as f:
    j_dict = json.load(f, strict=False)  # 將json load為dict


def classification():
    t = j_dict[0]['發病日'][6]  # 日期十位數
    t2 = j_dict[0]['發病日'][5]  # 日期個位數
    temp = 0
    str2 = j_dict[0]['發病日']
    l_dict = {"發病日": str2[0:7]}  # 日期的變數dict
    list = [l_dict]
    for i in range(len(j_dict)):  # 跑全部讀近來檔案的次數
        if j_dict[i]['發病日'][6] == t and t2 == j_dict[i]['發病日'][5]:
            s = j_dict[i]['居住縣市']
            if s in l_dict:  # 如果有相同名稱重複
                temp = 1
            if temp == 1:  # 這裡就會增加那縣市的數量
                count = l_dict[s]
                l_dict[s] = count + 1
                temp = 0
            else:  # 否則就增加 1 dict
                l_dict["%s" % j_dict[i]['居住縣市']] = 1
        else:
            t = j_dict[i]['發病日'][6]  # 月份十位數
            t2 = j_dict[i]['發病日'][5]  # 月份個位數
            str2 = j_dict[i]['發病日']
            l_dict = {"發病日": str2[0:7]}  # 日期
            list.append(l_dict)  # 如果發病日的月份換過了就擴展再重新計算下個月份
    return list


# j_list = []
j_list = classification()
with open('Result.json', 'w', encoding='utf-8-sig') as outfile:
    json.dump(j_list, outfile, ensure_ascii=False, separators=(',\n', ': '))  # 轉成json 設定不是 ascii
