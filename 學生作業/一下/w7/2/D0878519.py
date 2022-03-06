dict1 = {'Name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # 數據1
dict2 = {'Name': '小火龍', 'type': 'fire', 'CP': 100}  # 數據2
dict3 = {'Name': '傑尼龜', 'type': 'water', 'CP': 100}  # 數據3
dict4 = {'Name': 0, 'type': 0, 'CP': 0}  # 新增數據最初
list1 = [dict1, dict2, dict3]  # 儲存數據
create = int(0)  # 判斷有無新增
while True:
    x = int(input('選擇1.新增 2.對戰 3.結束:'))
    if x > 3 or x < 0:  # 判斷輸入
        print('輸入錯誤')
        continue
    if x == 1:  # 新增
        list1.append(dict4)
        dict4['Name'] = input('輸入名字:')
        while True:
            dict4['type'] = input('輸入屬性:')  # 屬性判斷
            if dict4['type'] != 'fire' and dict4['type'] != 'water' and dict4['type'] != 'grass':
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            dict4['CP'] = int(input('輸入CP值:'))  # CP值判斷
            if dict4['CP'] > 999 or dict4['CP'] < 1:
                print('輸入錯誤')
                continue
            else:
                print('新增完畢')
                break
        create = 1
    elif x == 2:  # 對戰
        i = int(0)  # 印出預設
        print('編號{}'.format(i))
        print('名字:{}'.format(list1[i]['Name']))
        print('屬性:{}'.format(list1[i]['type']))
        print('CP值:{}'.format(list1[i]['CP']))
        i += 1
        print('編號{}'.format(i))
        print('名字:{}'.format(list1[i]['Name']))
        print('屬性:{}'.format(list1[i]['type']))
        print('CP值:{}'.format(list1[i]['CP']))
        i += 1
        print('編號{}'.format(i))
        print('名字:{}'.format(list1[i]['Name']))
        print('屬性:{}'.format(list1[i]['type']))
        print('CP值:{}'.format(list1[i]['CP']))
        i += 1
        if create == 1:  # 印出新增的
            print('編號{}'.format(i))
            print('名字:{}'.format(list1[i]['Name']))
            print('屬性:{}'.format(list1[i]['type']))
            print('CP值:{}'.format(list1[i]['CP']))
            while True:
                fight1 = int(input('選擇第一隻(輸入編號):'))
                if fight1 > 3 or fight1 < 0:  # 對戰編號判斷
                    print('輸入錯誤')
                    continue
                else:
                    break
            while True:
                fight2 = int(input('選擇第二隻(輸入編號):'))
                if fight2 > 3 or fight2 < 0 or fight1 == fight2:  # 對戰編號判斷
                    print('輸入錯誤')
                    continue
                else:
                    break
            if fight1 == 0 and fight2 == 1:
                print('編號1: 小火龍 勝利')
            if fight1 == 0 and fight2 == 2:
                print('編號0: 妙蛙種子 勝利')
            if fight1 == 1 and fight2 == 0:
                print('編號1: 小火龍 勝利')
            if fight1 == 1 and fight2 == 2:
                print('編號2: 傑尼龜 勝利')
            if fight1 == 2 and fight2 == 0:
                print('編號0: 妙蛙種子 勝利')
            if fight1 == 2 and fight2 == 1:
                print('編號2 傑尼龜 勝利')
            if fight1 == 0 and fight2 == 3:
                if dict4['type'] == 'fire' and dict4['CP'] == 100 or dict4['CP'] > 100:
                    print('編號3: {} 勝利'.format(dict4['Name']))
                else:
                    print('編號0 妙蛙種子 勝利')
            if fight1 == 3 and fight2 == 0:
                if dict4['type'] == 'fire' and dict4['CP'] == 100 or dict4['CP'] > 100:
                    print('編號3: {} 勝利'.format(dict4['Name']))
                else:
                    print('編號0 妙蛙種子 勝利')
            if fight1 == 3 and fight2 == 1:
                if dict4['type'] == 'water' and dict4['CP'] == 100 or dict4['CP'] > 100:
                    print('編號3: {} 勝利'.format(dict4['Name']))
                else:
                    print('編號1 小火龍 勝利')
            if fight1 == 3 and fight2 == 2:
                if dict4['type'] == 'grass' and dict4['CP'] == 100 or dict4['CP'] > 100:
                    print('編號3: {} 勝利'.format(dict4['Name']))
                else:
                    print('編號2 傑尼龜 勝利')
            continue
        while True:
            fight1 = int(input('選擇第一隻(輸入編號):'))  # 對戰編號判斷
            if fight1 > 2 or fight1 < 0:
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            fight2 = int(input('選擇第二隻(輸入編號):'))  # 對戰編號判斷
            if fight2 > 2 or fight2 < 0 or fight1 == fight2:
                print('輸入錯誤')
                continue
            else:
                break
        if fight1 == 0 and fight2 == 1:
            print('編號1: 小火龍 勝利')
        if fight1 == 0 and fight2 == 2:
            print('編號0: 妙蛙種子 勝利')
        if fight1 == 1 and fight2 == 0:
            print('編號1: 小火龍 勝利')
        if fight1 == 1 and fight2 == 2:
            print('編號2: 傑尼龜 勝利')
        if fight1 == 2 and fight2 == 0:
            print('編號0: 妙蛙種子 勝利')
        if fight1 == 2 and fight2 == 1:
            print('編號2 傑尼龜 勝利')
    elif x == 3:  # 結束
        break
