def output():
    result = list()
    for i in range(length):
        calender = data[i]['發病日'][:7]
        place = data[i]['居住縣市']
        num = len(result)
        flag = 0
        if i == 0:
            tmp = {'發病日': calender, place: 1}
            result.append(tmp)
        else:
            for j in range(num):
                if calender in result[j]['發病日']:
                    flag = 1
                    break
            if flag == 0:
                tmp = {'發病日': calender, place: 1}
                result.append(tmp)
            else:
                if place in result[j]:
                    result[j][place] += 1
                else:
                    result[j][place] = 1
    return result


import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    data = json.load(outfile)
    length = len(data)  # print('%d' % length)
result = output()

with open('Result.json', 'w', encoding='utf-8-sig') as outfile:
    json.dump(result, outfile, ensure_ascii=False, indent=4)
