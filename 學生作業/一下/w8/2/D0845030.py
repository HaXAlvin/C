import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:  # 讀json
    statistic = json.load(outfile)


def function():  # 函式
    list = []
    data = {}
    for i in range(len(statistic)):
        if i == 0:
            temp = statistic[0]["發病日"][0:7]  # 紀錄1998/01
            data["發病日"] = statistic[0]["發病日"][0:7]
            data[statistic[0]["居住縣市"]] = 1  # 計算人數
        elif statistic[i]["發病日"][0:7] == temp:  # 如果發病日為紀錄的日期
            if statistic[i]["居住縣市"] in data:  # 如果dict中已經有這個城市
                data[statistic[i]["居住縣市"]] += 1  # 城市感染人數加一
            else:  # 如果dict中尚未紀錄此城市
                data[statistic[i].get("居住縣市")] = 1  # 城市感染人數起始為一
        elif statistic[i]["發病日"][0:7] != temp:
            list.append(data)  # 新增空間
            temp = statistic[i]["發病日"][0:7]
            data = {"發病日": statistic[i]["發病日"][0:7], statistic[i]["居住縣市"]: 1}  # 清空dict

        if i == len(statistic) - 1:  # 最後一個月份
            list.append(data)
    return list


with open('Result.json', 'w') as outfile:  # 寫json
    json.dump(function(), outfile, indent=4)
