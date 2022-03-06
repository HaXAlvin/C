import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    Dengue_Daily = json.load(outfile)


def f1(file):
    # 放進一個dic=city
    data_temp = list()
    city = {'台北市': 0, '新北市': 0, '桃園市': 0, '台中市': 0, '台南市': 0, '高雄市': 0, '新竹縣': 0, '苗栗縣': 0, '彰化縣': 0, '南投縣': 0,
            '雲林縣': 0, '嘉義縣': 0, '屏東縣': 0, '花蓮縣': 0, '台東縣': 0, '澎湖縣': 0, '金門縣': 0, '連江縣': 0, '新竹市': 0, '嘉義市': 0,
            '宜蘭縣': 0, '基隆市': 0}
    # date是拿了第一筆資料的第一個dic中前7個數字
    date = file[0].get('發病日')[:7]
    # 直接讀入這檔案 直到這檔案德最後
    for i in Dengue_Daily:
        # 如果date!=n月，代表上個月的已經拿光了
        if date != i.get('發病日')[:7]:
            # 放入i月
            temp_date = {'發病日': date}
            for j in city:
                if city.get(j) != 0:
                    # 將這city裡的人數取出update近temp_date
                    temp_date.update({j: city.get(j)})
                # 再將下個dic放進data_temp 直到city裡的城市都結算
            data_temp.append(temp_date)
            for m in city:
                # 將city淨空 要換下個月了
                city[m] = 0
            # next month
            date = i.get('發病日')[:7]
        # city換下一個城市
        city[i.get('居住縣市')] += 1
    return data_temp


with open('Result.json', 'w', encoding='utf8') as file:
    json.dump(f1(Dengue_Daily), file, ensure_ascii=False, indent=4)
# 有引用此網站某些資訊 https://blog.gtwang.org/programming/python-csv-file-reading-and-writing-tutorial/
