# -*- coding: utf-8 -*-
"""
Spyder Editor
This is a temporary script file.
"""
dict1 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}
dict2 = {'name': '小火龍', 'type': 'fire', 'CP': 100}
dict3 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
list_pokemon = [dict1, dict2, dict3]
list_type = ['grass', 'water', 'fire']
sum = 3
while True:
    game_type = int(input('選擇1.新增2.對戰3.結束:'))
    if game_type == 1:  # 新增
        list_pokemon.append(dict())  # 加一個dict
        list_pokemon[sum]['name'] = (input('輸入名字:'))
        list_pokemon[sum]['type'] = (input('輸入屬性:'))
        while list_pokemon[sum]['type'] not in list_type:
            print('輸入錯誤')
            list_pokemon[sum]['type'] = (input('輸入屬性:'))
        list_pokemon[sum]['CP'] = int((input('輸入CP值:')))
        while list_pokemon[sum]['CP'] < 0 or list_pokemon[sum]['CP'] > 999:  # CP超過範圍
            print('輸入錯誤')
            list_pokemon[sum]['CP'] = int((input('輸入CP值:')))
        sum = sum + 1
    elif game_type == 2:
        flag = 0  # 0為平手 1為1贏 2為2贏
        for i in range(sum):
            print('編號:' + str(i))
            print('名字:' + list_pokemon[i]['name'])
            print('屬性:' + list_pokemon[i]['type'])
            print('CP值:', str(list_pokemon[i]['CP']))
        char1 = int(input('選擇第一隻(編號):'))
        while 0 > char1 or char1 > sum:
            print('輸入錯誤')
            char1 = int(input('選擇第一隻(編號):'))
        char2 = int(input('選擇第二隻(編號):'))
        while 0 > char2 or char2 > sum or char2 == char1:
            print('輸入錯誤')
            char2 = int(input('選擇第二隻(編號):'))
        char1_type = list_pokemon[char1]['type']  # 從list裡面找他的屬性
        char2_type = list_pokemon[char2]['type']  # 同上   #list_type=['fire','grass','water','fire']
        if list_pokemon[char1]['CP'] > list_pokemon[char2]['CP']:
            flag = 1
        if list_pokemon[char2]['CP'] > list_pokemon[char1]['CP']:
            flag = 2
        if list_pokemon[char1]['CP'] == list_pokemon[char2]['CP']:  # 平手的話用index判斷
            if list_type[list_type.index(char1_type)] == list_type[list_type.index(char2_type) - 1]:
                flag = 1  # 第一隻贏 備註 用加的會超出index範圍
            elif list_type[list_type.index(char1_type) - 1] == list_type[list_type.index(char2_type)]:
                flag = 2  # 第二隻贏
            elif list_type[list_type.index(char1_type)] == list_type[list_type.index(char2_type)]:
                flag = 0  # 平手
        if flag == 1:
            print('第一隻怪獸:' + '編號' + str(char1) + ' ' + list_pokemon[char1]['name'] + ' 獲勝')
        elif flag == 2:
            print('第二隻怪獸:' + '編號' + str(char2) + ' ' + list_pokemon[char2]['name'] + ' 獲勝')
        elif flag == 0:
            print('平手')
    elif game_type == 3:
        break
