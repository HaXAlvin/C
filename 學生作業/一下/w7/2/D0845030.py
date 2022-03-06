poke1 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # 妙蛙種子的資料
poke2 = {'name': '小火龍', 'type': 'fire', 'CP': 100}  # 小火龍的資料
poke3 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}  # 傑尼龜的資料
list1 = [poke1, poke2, poke3]  # 用list儲存上列資料
count = 3  # 用來計算新增幾次神奇寶貝
while True:
    choice = int(input('選擇1.新增2.對戰3.結束:'))
    if choice == 1:
        count += 1  # 每次新增count加一
        newpoke = dict()  # 新的儲存空間
        list1.append(newpoke)  # list新增空間
        newpoke['name'] = input('輸入名字:')
        newpoke['type'] = input('輸入屬性:')
        while newpoke['type'] != 'grass' and newpoke['type'] != 'fire' and newpoke['type'] != 'water':  # 防呆
            print('輸入錯誤')
            newpoke['type'] = input('輸入屬性:')
        newpoke['CP'] = int(input('輸入CP值:'))
        while newpoke['CP'] < 1 or newpoke['CP'] > 999:  # 防呆
            print('輸入錯誤')
            newpoke['CP'] = int(input('輸入CP值:'))
        print('新增完畢')
    elif choice == 2:
        tmp = 0
        for i in range(count):  # 依序印出神奇寶貝
            print('編號', tmp)
            print('名字:', list1[tmp]['name'])
            print('屬性:', list1[tmp]['type'])
            print('CP值:', list1[tmp]['CP'])
            tmp += 1
        choose1 = int(input('選擇第一隻(輸入編號):'))  # 選擇
        while 0 > choose1 or choose1 > count - 1:  # 防呆
            print('輸入錯誤')
            choose1 = int(input('選擇第一隻(輸入編號):'))
        choose2 = int(input('選擇第二隻(輸入編號):'))  # 選擇
        while 0 > choose2 or choose2 > count - 1 or choose2 == choose1:  # 防呆
            print('輸入錯誤')
            choose2 = int(input('選擇第二隻(輸入編號):'))
        if list1[choose1]['CP'] > list1[choose2]['CP']:  # 選擇1cp值大於選擇2
            print('編號', choose1, list1[choose1]['name'], '勝利')
        elif list1[choose1]['CP'] < list1[choose2]['CP']:  # 選擇1cp值小於選擇2
            print('編號', choose2, list1[choose2]['name'], '勝利')
        elif list1[choose1]['CP'] == list1[choose2]['CP']:  # cp值相同
            if list1[choose1]['type'] == 'grass' and list1[choose2]['type'] == 'fire':  # 草屬vs火屬
                print('編號', choose2, list1[choose2]['name'], '勝利')
            elif list1[choose1]['type'] == 'grass' and list1[choose2]['type'] == 'water':  # 草屬vs水屬
                print('編號', choose1, list1[choose1]['name'], '勝利')
            elif list1[choose1]['type'] == 'fire' and list1[choose2]['type'] == 'water':  # 火屬vs水屬
                print('編號', choose2, list1[choose2]['name'], '勝利')
            elif list1[choose1]['type'] == 'fire' and list1[choose2]['type'] == 'grass':  # 火屬vs草屬
                print('編號', choose1, list1[choose1]['name'], '勝利')
            elif list1[choose1]['type'] == 'water' and list1[choose2]['type'] == 'fire':  # 水屬vs火屬
                print('編號', choose1, list1[choose1]['name'], '勝利')
            elif list1[choose1]['type'] == 'water' and list1[choose2]['type'] == 'grass':  # 水屬vs草屬
                print('編號', choose2, list1[choose2]['name'], '勝利')
    elif choice == 3:  # 結束
        break
    else:  # 防呆
        print('輸入錯誤')
