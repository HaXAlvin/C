char0 = {'num': '編號0', 'name': '妙蛙種子', 'type': 'grass', 'CP': 100}
char1 = {'num': '編號1', 'name': '小火龍', 'type': 'fire', 'CP': 100}
char2 = {'num': '編號2', 'name': '傑尼龜', 'type': 'water', 'CP': 100}
char3 = {'num': '編號3'}
charlist = [char0, char1, char2, char3]
char = 2
battle1 = {}
battle2 = {}
battle = 0
while True:  # 系統迴圈
    system = int(input('選擇1.新增 2.對戰 3.結束：'))
    if system == 1:  # 新增
        char3['name'] = str(input('輸入名字：'))
        while True:  # 防呆
            typeset = str(input('輸入屬性:'))
            if typeset == 'water' or typeset == 'fire' or typeset == 'grass':
                char3['type'] = typeset
                break
            else:
                print('輸入錯誤')
        while True:  # 防呆
            CPset = int(input('輸入CP值:'))
            if CPset > 0 and CPset < 1000:
                char3['CP'] = CPset
                break
            else:
                print('輸入錯誤')
        char = 3
        print('新增完畢\n')
    elif system == 2:  # 戰鬥
        print('編號0\nName: 妙蛙種子\nType: grass\nCP: 100')
        print('編號1\nName: 小火龍\nType: fire\nCP: 100')
        print('編號2\nName: 傑尼龜\nType: water\nCP: 100')
        if char == 3:
            print('編號3\nName:', char3['name'])
            print('Type:', char3['type'])
            print('CP:', char3['CP'])
        while True:  # 防呆
            first = int(input('選擇第一隻(輸入編號):'))
            if first < 0 or first > char:
                print('輸入錯誤')
            elif first == 0:
                battle1 = char0
                break
            elif first == 1:
                battle1 = char1
                break
            elif first == 2:
                battle1 = char2
                break
            elif first == 3:
                battle1 = char3
                break
        while True:  # 防呆
            second = int(input('選擇第二隻(輸入編號):'))
            if second < 0 or second > char or second == first:
                print('輸入錯誤')
            elif second == 0:
                battle2 = char0
                break
            elif second == 1:
                battle2 = char1
                break
            elif second == 2:
                battle2 = char2
                break
            elif second == 3:
                battle2 = char3
                break
        if battle1['CP'] > battle2['CP']:
            battle = 1
        elif battle2['CP'] > battle1['CP']:
            battle = -1
        elif battle1['CP'] == battle2['CP']:
            if battle1['type'] == 'water' and battle2['type'] == 'fire':
                battle = 1
            elif battle1['type'] == 'fire' and battle2['type'] == 'grass':
                battle = 1
            elif battle1['type'] == 'grass' and battle2['type'] == 'water':
                battle = 1
            elif battle1['type'] == 'water' and battle2['type'] == 'grass':
                battle = -1
            elif battle1['type'] == 'grass' and battle2['type'] == 'fire':
                battle = -1
            elif battle1['type'] == 'fire' and battle2['type'] == 'water':
                battle = -1
        if battle == 1:
            print(battle1['num'], end=' ')
            print(battle1['name'], end=' ')
            print('勝利\n')
        elif battle == -1:
            print(battle2['num'], end=' ')
            print(battle2['name'], end=' ')
            print('勝利\n')
        elif battle == 0:
            print('平手\n')
        battle = 0
    elif system == 3:  # 結束
        break
    else:
        print('輸入錯誤')
