import json
import collections

# 開檔讀入
with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    Dengue = json.load(outfile)

# 宣告
output = []
locatelist = []
temp = str
locatehaslist = []

# 一個一個取資料
for data_num in Dengue:

    # 下面利用split切開取其年月
    time = data_num['發病日']
    timelist = time.split('/')
    year = timelist[0]
    month = timelist[1]
    year_month = year + "/" + month

    # 時間不重複時結算
    if temp != year_month:
        temp = year_month
        #
        for i in locatelist:
            # 利用locatehaslist當黑名單使不重複
            if i not in locatehaslist:
                # 將用過的全部放入黑名單
                locatehaslist.append(i)
                # 利用collections計算出現次數的函數 將之放入
                newdengue[i] = collections.Counter(locatelist)[i]

        # 歸零
        locatelist = []
        locatehaslist = []
        # 新增dict
        newdengue = {'發病日': year_month}
        output.append(newdengue)
        # 新增dict
        locate = data_num['居住縣市']
        locatelist.append(locate)
        #
    # 時間重複
    else:
        locate = data_num['居住縣市']
        locatelist.append(locate)
# 因為最後會少一部分資料所以補一個
for i in locatelist:
    # 利用locatehaslist當黑名單使不重複
    if i not in locatehaslist:
        # 將用過的全部放入黑名單
        locatehaslist.append(i)
        # 利用collections計算出現次數的函數 將之放入
        newdengue[i] = collections.Counter(locatelist)[i]
# 開檔輸出
with open('Result.json', 'w') as outfile:
    json.dump(output, outfile)
