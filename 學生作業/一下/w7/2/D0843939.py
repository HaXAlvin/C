# 設定變數
dic0 = {'num': '編號0', 'name': '妙蛙種子', 'type': 'grass', 'CP': 100}
dic1 = {'num': '編號1', 'name': '小火龍', 'type': 'fire', 'CP': 100}
dic2 = {'num': '編號2', 'name': '傑尼龜', 'type': 'water', 'CP': 100}
dic3 = {'num': '編號3'}
list = [dic0, dic1, dic2, dic3]
flag = 0
fight1 = {}
fight2 = {}
win = 0
# 程式開始迴圈
while True:
    choose = input('選擇1.新增 2.對戰 3.結束：')
    # 選擇1新增
    if choose == '1':
        dic3['name'] = str(input('輸入名字：'))
        while True:
            element = str(input('輸入屬性：'))
            if element == 'grass' or element == 'fire' or element == 'water':
                dic3['type'] = element
                break
            else:
                print('輸入錯誤')  # 防呆
        while True:
            cp = int(input('輸入CP值：'))
            if cp >= 1 and cp <= 999:
                dic3['CP'] = cp
                break
            else:
                print('輸入錯誤')  # 防呆
        flag = 1
        print('新增完畢\n')
    # 選擇2戰鬥
    elif choose == '2':
        # 列出當前寶可夢數值
        print('編號0\n名字：妙蛙種子\n屬性：grass\nCP值：100\n'
              '編號1\n名字：小火龍\n屬性：fire\nCP值：100\n'
              '編號2\n名字：傑尼龜\n屬性: water\nCP值：100')
        if flag == 1:
            print('編號3')
            print('名字：', dic3['name'])
            print('屬性：', dic3['type'])
            print('CP值：', dic3['CP'])
        # 選擇第一隻寶可夢
        while True:
            pick1 = int(input('選擇第一隻(輸入編號)：'))
            if flag == 0:
                if pick1 < 0 or pick1 > 2:
                    print('輸入錯誤')  # 防呆
                elif pick1 == 0:
                    fight1 = dic0
                    break
                elif pick1 == 1:
                    fight1 = dic1
                    break
                elif pick1 == 2:
                    fight1 = dic2
                    break
            if flag == 1:
                if pick1 < 0 or pick1 > 3:
                    print('輸入錯誤')  # 防呆
                elif pick1 == 0:
                    fight1 = dic0
                    break
                elif pick1 == 1:
                    fight1 = dic1
                    break
                elif pick1 == 2:
                    fight1 = dic2
                    break
                elif pick1 == 3:
                    fight1 = dic3
                    break
        # 選擇第二隻寶可夢
        while True:
            pick2 = int(input('選擇第二隻(輸入編號)：'))
            if flag == 0:
                if pick2 < 0 or pick2 > 2:
                    print('輸入錯誤')  # 防呆
                elif pick2 == pick1:
                    print('輸入錯誤')  # 防呆
                elif pick2 == 0:
                    fight2 = dic0
                    break
                elif pick2 == 1:
                    fight2 = dic1
                    break
                elif pick2 == 2:
                    fight2 = dic2
                    break
            elif flag == 1:
                if pick2 < 0 or pick2 > 3:
                    print('輸入錯誤')  # 防呆
                elif pick2 == pick1:
                    print('輸入錯誤')  # 防呆
                elif pick2 == 0:
                    fight2 = dic0
                    break
                elif pick2 == 1:
                    fight2 = dic1
                    break
                elif pick2 == 2:
                    fight2 = dic2
                    break
                elif pick2 == 3:
                    fight2 = dic3
                    break
        # 戰鬥判定，cp值先
        if fight1['CP'] > fight2['CP']:
            win = 1
        elif fight1['CP'] < fight2['CP']:
            win = 2
        # cp值相同，判斷屬性
        elif fight1['CP'] == fight2['CP']:
            if fight1['type'] == 'water' and fight2['type'] == 'fire':
                win = 1
            elif fight1['type'] == 'fire' and fight2['type'] == 'grass':
                win = 1
            elif fight1['type'] == 'grass' and fight2['type'] == 'water':
                win = 1
            elif fight2['type'] == 'water' and fight1['type'] == 'fire':
                win = 2
            elif fight2['type'] == 'fire' and fight1['type'] == 'grass':
                win = 2
            elif fight2['type'] == 'grass' and fight1['type'] == 'water':
                win = 2
        # 輸出勝利的寶可夢
        if win == 1:
            print(fight1['num'], end=' ')
            print(fight1['name'], end=' ')
            print('勝利\n')
        elif win == 2:
            print(fight2['num'], end=' ')
            print(fight2['name'], end=' ')
            print('勝利\n')
        elif win == 0:
            print('平手')
        win = 0
    # 選擇3結束
    elif choose == '3':
        break
    # 防呆
    else:
        print('輸入錯誤\n')
