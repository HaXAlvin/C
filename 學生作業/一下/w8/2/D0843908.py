#!/usr/bin/env python
# coding: utf-8

# In[228]:


import pandas as pd
import json

# 開檔
file = open('Dengue_Daily.json', 'r', encoding='utf-8-sig')
content = pd.read_json(file)
df = pd.DataFrame(content)


# 將年月日轉為年月
def YearMonth(ymd):
    list1 = ymd.split('/')
    return '/'.join([list1[0], list1[1]])


# 建立list與定義初始狀態
diction = {'發病日': '1998/01'}
list = [diction]


# append一個新的dict到list的函式
def count(ymd, city):
    dict = {'發病日': YearMonth(ymd)}
    if dict.get(city) is None:
        dict.update({city: 1})
    else:
        dict[city] += 1
    return dict


# 第j個月
j = 0

for i in range(len(df)):
    day = df.iloc[i, 0]  # 某年某月
    city = df.iloc[i, 5]  # 某縣市
    ymd = YearMonth(day)  # 呼叫函式
    if ymd == list[j]['發病日']:  # 若年月和dict中的年月相同
        if list[j].get(city) is not None:  # 若縣市存在
            list[j][city] += 1  # 病例數+1
        else:
            list[j][city] = 1  # 建立一個key
    else:  # 若
        j += 1
        list.append(count(day, city))
# 寫檔
with open('Result.json', 'w') as outfile:
    json.dump(list, outfile, indent=4)

# In[1]:


# In[ ]:
