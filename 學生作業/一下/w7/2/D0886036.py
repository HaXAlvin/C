a = 3  # 跑對戰編號
b = 0  # 設flag有沒有創新角色
f1 = 0  # 跑對戰編號
f2 = 1  # 跑對戰編號
f3 = 2  # 跑對戰編號
fire = 'fire'
water = 'water'
grass = 'grass'
while True:  # 無限迴圈
    list = ['妙蛙種子', 'grass', '100', '小火龍', 'fire', 100, '傑尼龜', 'water', 100]  # 所有數據
    dict1 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}
    dict2 = {'name': '小火龍', 'type': 'fire', 'CP': 100}
    dict3 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
    i = int(input('選擇1.新增 2.對戰 3.結束:'))
    if i != 1 and i != 2 and i != 3:  # 一開始輸入錯誤時
        print('輸入錯誤')
        continue
    elif i == 3:  # 輸入3結束
        break
    elif i == 1:  # 輸入1新增
        n = str(input('輸入名字:'))
        t = str(input('輸入屬性:'))
        if t != 'grass' and t != 'fire' and t != 'water':
            print('輸入錯誤')
            continue
        c = int(input('輸入CP值:'))
        print('新增完畢')
        a = 4  # 對戰編碼多跑新增
        b = 1  # 創立新角 flag變1
        list.append(n)  # 新增到list
        list.append(t)
        list.append(c)
    elif i == 2:  # 輸入2對戰
        for j in range(a):  # print數據
            print('編號', j, ':')
            print('名字:', list[f1])
            print('屬性:', list[f2])
            print('CP值:', list[f3])
            f1 = f1 + 3
            f2 = f2 + 3
            f3 = f3 + 3
        if b == 0:  # 沒有創立新角時
            c1 = int(input('選擇第一隻(輸入編號):'))  # 輸入第一隻
            if c1 != 0 and c1 != 1 and c1 != 2:
                print('輸入錯誤')
                continue
            if c1 == 0 or c1 == 1 or c1 == 2:
                c2 = int(input('選擇第二隻(輸入編號):'))  # 輸入第二隻
                if c2 != 0 and c2 != 1 and c2 != 2:
                    print('輸入錯誤')
                    continue
                elif c1 == 0 and c2 == 0:
                    print('輸入錯誤')
                    continue
                elif c1 == 1 and c2 == 1:
                    print('輸入錯誤')
                    continue
                elif c1 == 2 and c2 == 2:
                    print('輸入錯誤')
                    continue
            if c1 == 0 and c2 == 1:
                print('編號 1 小火龍  勝利')
                continue
            if c1 == 1 and c2 == 0:
                print('編號 1 小火龍  勝利')
                continue
            if c1 == 1 and c2 == 2:
                print('編號 2 傑尼龜  勝利')
                continue
            if c1 == 2 and c2 == 1:
                print('編號 2 傑尼龜  勝利')
                continue
            if c1 == 2 and c2 == 0:
                print('編號 0 妙蛙種子  勝利')
                continue
            if c1 == 0 and c2 == 2:
                print('編號 0 妙蛙種子  勝利')
                continue
        if b == 1:  # 有創立新角時
            c1 = int(input('選擇第一隻(輸入編號):'))  # 輸入第一隻
            if c1 != 0 and c1 != 1 and c1 != 2:
                print('輸入錯誤')
                continue
            if c1 == 0 or c1 == 1 or c1 == 2:
                c2 = int(input('選擇第二隻(輸入編號):'))  # 輸入第二隻
                if c2 != 0 and c2 != 1 and c2 != 2:
                    print('輸入錯誤')
                    continue
                elif c1 == 0 and c2 == 0:
                    print('輸入錯誤')
                    continue
                elif c1 == 1 and c2 == 1:
                    print('輸入錯誤')
                    continue
                elif c1 == 2 and c2 == 2:
                    print('輸入錯誤')
                    continue
                elif c1 == 3 and c2 == 3:
                    print('輸入錯誤')
                    continue
            if c1 == 0 and c2 == 1:
                print('編號 1 小火龍  勝利')
                continue
            if c1 == 1 and c2 == 0:
                print('編號 1 小火龍  勝利')
                continue
            if c1 == 1 and c2 == 2:
                print('編號 2 傑尼龜  勝利')
                continue
            if c1 == 2 and c2 == 1:
                print('編號 2 傑尼龜  勝利')
                continue
            if c1 == 2 and c2 == 0:
                print('編號 0 妙蛙種子  勝利')
                continue
            if c1 == 0 and c2 == 2:
                print('編號 0 妙蛙種子  勝利')
                continue
            if c1 == 0 and c2 == 3:
                if list[2] == list[11]:
                    if list[10] == grass:
                        print('平手')
                        continue
                    elif list[10] == fire:
                        print('編號 3', list[9], '勝利')
                        continue
                    elif list[10] == water:
                        print('編號 0 妙蛙種子  勝利')
                        continue
                elif list[11] > list[2]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[2]:
                    print('編號 0 妙蛙種子  勝利')
                    continue
            if c1 == 3 and c2 == 0:
                if list[2] == list[11]:
                    if list[10] == grass:
                        print('平手')
                        continue
                    elif list[10] == fire:
                        print('編號 3', list[9], '勝利')
                        continue
                    elif list[10] == water:
                        print('編號 0 妙蛙種子  勝利')
                        continue
                elif list[11] > list[2]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[2]:
                    print('編號 0 妙蛙種子  勝利')
                    continue
            if c1 == 1 and c2 == 3:
                if list[5] == list[11]:
                    if list[10] == grass:
                        print('編號 1 小火龍  勝利')
                        continue
                    elif list[10] == fire:
                        print('平手')
                        continue
                    elif list[10] == water:
                        print('編號 3', list[9], '勝利')
                        continue
                elif list[11] > list[5]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[5]:
                    print('編號 1 小火龍  勝利')
                    continue
            if c1 == 3 and c2 == 1:
                if list[5] == list[11]:
                    if list[10] == grass:
                        print('編號 1 小火龍  勝利')
                        continue
                    elif list[10] == fire:
                        print('平手')
                        continue
                    elif list[10] == water:
                        print('編號 3', list[9], '勝利')
                        continue
                elif list[11] > list[5]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[5]:
                    print('編號 1 小火龍  勝利')
                    continue
            if c1 == 2 and c2 == 3:
                if list[8] == list[11]:
                    if list[10] == grass:
                        print('編號 3', list[9], '勝利')
                        continue
                    elif list[10] == fire:
                        print('編號 2 傑尼龜  勝利')
                        continue
                    elif list[10] == water:
                        print('平手')
                        continue
                elif list[11] > list[8]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[8]:
                    print('編號 2 傑尼龜  勝利')
                    continue
            if c1 == 3 and c2 == 2:
                if list[8] == list[11]:
                    if list[10] == grass:
                        print('編號 3', list[9], '勝利')
                        continue
                    elif list[10] == fire:
                        print('編號 2 傑尼龜  勝利')
                        continue
                    elif list[10] == "water":
                        print('平手')
                        continue
                elif list[11] > list[8]:
                    print('編號 3', list[9], '勝利')
                    continue
                elif list[11] < list[8]:
                    print('編號 2 傑尼龜  勝利')
                    continue
