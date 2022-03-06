import json


def infor(daily):
    final = []  # 用list存最後輸出
    oldday = '1998/01'  # 設定初始日期去判斷
    tmp = {'發病日': '1998/01'}  # 裡面有字 是輸出格式要求的 懂嗎
    for i in range(len(daily)):  # 一筆一筆分析資料啦
        if daily[i]['發病日'][0:7] == oldday:  # 年月一樣 就新增在同一個dict 阿這個[0:7]就是取年月就好懂不懂
            if daily[i]['居住縣市'] in tmp:
                tmp[daily[i]['居住縣市']] += 1
            else:
                tmp[daily[i]['居住縣市']] = 1
        else:  # 年月不一樣 就 清空dict
            final.append(tmp)
            tmp = {}
            oldday = daily[i]['發病日'][0:7]
            tmp['發病日'] = daily[i]['發病日'][0:7]  # 題目要求啦
            tmp[daily[i]['居住縣市']] = 1

    final.append(tmp)
    return final


with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as f:  # 開檔
    daily = json.load(f)
a = infor(daily)
with open('Result.json', 'w', encoding='utf-8') as f:  # 寫檔 結束一切
    json.dump(a, f, ensure_ascii=False, indent=4)
