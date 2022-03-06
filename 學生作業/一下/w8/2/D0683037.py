# -*- coding: utf-8 -*-
"""
Created on Mon May 18 10:57:47 2020

@author: user
"""

# -*- coding: utf-8 -*-
"""
Created on Mon May 18 10:18:55 2020

@author: user
"""


##副程式
def calculate(list):
    list = []
    dict = {}
    sortlist = []
    dict = {}
    for i in range(len(output)):
        dict["發病日"] = output[i]["發病日"][0:7]
        dict["居住縣市"] = output[i]["居住縣市"]
        list.append(dict)
        dict = {}

    # 建立每(個月個別的dict
    j = 0
    for i in range(len(list) - 1):
        if list[i]["發病日"] != list[i + 1]["發病日"]:
            dict["發病日"] = list[i]["發病日"]
            sortlist.append(dict)
            j += 1
        dict = {}

    dict['發病日'] = list[len(list) - 1]["發病日"]
    sortlist.append(dict)

    ###放入該月有發生病例的地區(key)
    j = 0
    for i in range(len(list) - 1):
        if sortlist[j]["發病日"] == list[i]["發病日"]:
            sortlist[j][str(list[i]["居住縣市"])] = 0
        if (sortlist[j]["發病日"] != list[i + 1]["發病日"]):
            j += 1

    ###插入對應key的value
    j = 0
    for i in range(len(list) - 1):
        if sortlist[j]["發病日"] == list[i]["發病日"]:
            sortlist[j][str(list[i]["居住縣市"])] += 1
        if (sortlist[j]["發病日"] != list[i + 1]["發病日"]):
            j += 1

    print(sortlist)
    length = 0

    with open('Result.json', 'w', encoding='utf-8-sig') as files:
        ##json.dump(sortlist,files,indent = 1,ensure_ascii=False)
        for i in range(len(sortlist)):
            dict = {}
            dict = sortlist[i]
            files.write(sortlist[i]["發病日"] + ' 有')
            del dict["發病日"]
            count = 0
            for j in dict.keys():
                length += 1
            for j in dict.keys():
                files.write(str(j) + str(dict[j]) + '位')
                if (count < length - 1):
                    files.write('、')
                count += 1
            length = 0
            files.write('\n')


###主程式
import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as outfile:
    output = json.load(outfile)

calculate(output)
