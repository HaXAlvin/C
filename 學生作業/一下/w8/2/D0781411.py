# -*- coding: utf-8 -*-
"""
Created on Mon May 18 17:37:31 2020

@author: USER
"""
import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig')as outfile:
    Dengue = json.load(outfile)


def statistics(Dengue):
    j = 0
    All_Onset_Month = []  # 大家發病的月份(有重複)(ex;1998/10) (list)
    Onset_Month = []  # 有發病的月份(沒有重複) (list)
    Time_Place = []  # 最後輸出的東西 (list)
    for i in range(len(Dengue)):
        All_Onset_Month.append(Dengue[i]['發病日'][0:7])  # 先把大家的發病月份抓出來
    Onset_Month = [All_Onset_Month[0]]  # 先丟一個東西進去 方便下面判斷
    for i in range(len(Dengue)):
        if Onset_Month[j] != All_Onset_Month[i] and Onset_Month[j - 1] != All_Onset_Month[i]:
            Onset_Month.append(All_Onset_Month[i])  # 如果出現目前記錄的"有發病的月份"中沒出現的就新增他
            j = j + 1
    for i in range(len(Onset_Month)):
        Time_Place.append(dict({'發病日': Onset_Month[i]}))  # append一個發病日
        for j in range(len(All_Onset_Month)):  # 逐個檢查
            if Onset_Month[i] == All_Onset_Month[j]:
                if Dengue[j]['居住縣市'] in Time_Place[i]:  # 如果裡面有出現過這個縣市了 key值+1
                    Time_Place[i][Dengue[j]['居住縣市']] = Time_Place[i][Dengue[j]['居住縣市']] + 1
                if Dengue[j]['居住縣市'] not in Time_Place[i]:  # 如果裡面沒有出現過這個縣市 就新增 key值=1
                    Time_Place[i][Dengue[j]['居住縣市']] = 1
    return Time_Place  # 回傳list


with open('Result.json', 'w') as outfile:
    json.dump(statistics(Dengue), outfile, indent=4)
