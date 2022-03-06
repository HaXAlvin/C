# -*- coding: utf-8 -*-
"""
Created on Tue May 19 20:16:13 2020

@author: aszx4
"""
import json

i = 0
djc = dict()
dj = list()
with open('Dengue_Daily_10.json', 'r', encoding='utf-8-sig') as f:
    tw = json.load(f)
for case in tw:
    # print(case.get('發病日'))
    djc[case.get('發病日')] = int(case.get('確定病例數'))
    if dj['發病日'] == djc['發病日']:
        i += 1
    else:
        i = 0
    dj[case.get('發病日')] = i

    print(dj)

# print(tw)
# print(tw.get('發病日'))
