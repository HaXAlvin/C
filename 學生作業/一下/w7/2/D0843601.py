dict1 = {'num': '編號0', 'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # 把角色資訊存在dictionary
dict2 = {'num': '編號1', 'name': '小火龍', 'type': 'fire', 'CP': 100}
dict3 = {'num': '編號2', 'name': '傑尼龜', 'type': 'water', 'CP': 100}
list = [dict1, dict2, dict3]  # 把dict存在list
fight1 = {}
fight2 = {}
num1 = 2
dict = 3
while 1:
    txt = int(input('選擇1.新增 2.對戰 3. 結束： '))
    if txt == 1:  # 若選擇新增角色
        name1 = input('輸入名字 : ')
        type1 = input('輸入屬性 : ')
        while 1:
            if type1 != 'fire' and type1 != 'water' and type1 != 'grass':  # 防呆
                print('輸入錯誤')
                type1 = input('輸入屬性 : ')
            else:
                break

        CP1 = int(input('輸入CP值 : '))
        while 1:
            if CP1 < 1 or CP1 > 999:
                print('輸入錯誤')
                CP1 = int(input('輸入CP值 : '))
            else:
                break
        print('新增完畢')
        dict4 = {'num': num1, 'name': name1, 'type': type1, 'CP': CP1}  # 將新角色存在dictionary
        list.append(dict4)  # 把新dict存到list
        dict = 4
    elif txt == 2:  # 若選擇戰鬥
        print(dict1['num'])  # 印出個角色資訊
        print('名字:', end='')
        print(dict1['name'])
        print('屬性:', end='')
        print(dict1['type'])
        print('CP值:', end='')
        print(dict1['CP'])
        print(dict2['num'])
        print('名字:', end='')
        print(dict2['name'])
        print('屬性:', end='')
        print(dict2['type'])
        print('CP值:', end='')
        print(dict2['CP'])
        print(dict3['num'])
        print('名字:', end='')
        print(dict3['name'])
        print('屬性:', end='')
        print(dict3['type'])
        print('CP值:', end='')
        print(dict3['CP'])
        if dict == 4:  # 若有新增角色則印出角色資訊
            print('編號3', end='\n')
            print('名字:', end='')
            print(dict4['name'])
            print('屬性:', end='')
            print(dict4['type'])
            print('CP值:', end='')
            print(dict4['CP'])
        while (1):
            first = int(input('選擇第一隻(輸入編號):'))  # 選擇第一位選手
            if first < 0 or first > dict:
                print('輸入錯誤')
            elif first == 0:
                fight1 = dict1
                break
            elif first == 1:
                fight1 = dict2
                break
            elif first == 2:
                fight1 = dict3
                break
            elif first == 3:
                fight1 = dict4
                break
        while 1:
            last = int(input('選擇第二隻(輸入編號):'))  # 選擇第二位選手
            if last < 0 or last > dict or last == first:
                print('輸入錯誤')
            elif last == 0:
                fight2 = dict1
                break
            elif last == 1:
                fight2 = dict2
                break
            elif last == 2:
                fight2 = dict3
                break
            elif last == 3:
                fight2 = dict4
                break
        if fight1['CP'] > fight2['CP']:  # 以下為獲勝之條件
            print(fight1['num'], fight1['name'], '勝利\n', sep=' ')  # 若選手一獲勝則印出以下
        elif fight2['CP'] > fight1['CP']:
            print(fight2['num'], fight2['name'], '勝利\n', sep=' ')  # 若選手二獲勝則印出以下
        elif fight1['CP'] == fight2['CP']:
            if fight1['type'] == 'water' and fight2['type'] == 'fire':
                print(fight1['num'], fight1['name'], '勝利\n', sep=' ')
            elif fight1['type'] == 'fire' and fight2['type'] == 'grass':
                print(fight1['num'], fight1['name'], '勝利\n', sep=' ')
            elif fight1['type'] == 'grass' and fight2['type'] == 'water':
                print(fight1['num'], fight1['name'], '勝利\n', sep=' ')
            elif fight2['type'] == 'water' and fight1['type'] == 'fire':
                print(fight2['num'], fight2['name'], '勝利\n', sep=' ')
            elif fight2['type'] == 'grass' and fight1['type'] == 'water':
                print(fight2['num'], fight2['name'], '勝利\n', sep=' ')
            elif fight2['type'] == 'fire' and fight1['type'] == 'grass':
                print(fight2['num'], fight2['name'], '勝利\n', sep=' ')
        else:  # 平手
            print('平手\n')

    elif txt == 3:  # 選擇結束
        break

    else:
        print('輸入錯誤')
