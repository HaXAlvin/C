import json


def change(input):
    list1 = list()
    defSickDate = "1998/01"
    dict1 = {"發病日": defSickDate}

    for i in range(len(input)):
        sickDate = input[i].get("發病日")  # 存最初的發病日期
        addr = input[i].get("居住縣市")  # 存縣市

        if defSickDate in sickDate:  # 如果發病日等於月份
            if addr in dict1:  # 縣市存在+1
                dict1[addr] += 1
            else:  # 縣市不存在，新增後=1
                dict1[addr] = 1
        else:
            defSickDate = sickDate[:7]  # 只存取到月份
            list1.append(dict1)  # 讀完的月份，寫進list
            del dict1  # 清空
            dict1 = {"發病日": defSickDate, addr: 1}  # 建下一個月的字典

    list1.append(dict1)
    return list1


if __name__ == "__main__":
    with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as out:
        people = json.load(out)

    list_return = change(people)
    with open("Result.json", "w", encoding='utf-8-sig') as out:
        json.dump(list_return, out, indent=4, ensure_ascii=False)
