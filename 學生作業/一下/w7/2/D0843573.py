# 每個寶可夢數據是 1 個 dict
character1 = {'Name': '妙蛙種子', 'type': 'grass', 'CP': 100}
character2 = {'Name': '小火龍', 'type': 'fire', 'CP': 100}
character3 = {'Name': '傑尼龜', 'type': 'water', 'CP': 100}
# 會用 1 個 list 儲存所有的寶可夢數據
list = [character1, character2, character3]
while True:
    num1 = int(input('1.新增 2.對戰 3.結束:'))
    # 防呆
    if num1 != 1 and num1 != 2 and num1 != 3:
        print('輸入錯誤')
    # 新增
    elif num1 == 1:
        # 宣告一個空dict供使用者輸入數值
        character = {}
        # 新增在list的最後
        list.append(character)
        character['Name'] = input('輸入名字:')
        while True:
            character['type'] = input('輸入屬性:')
            # 防呆
            if (character['type'] != 'grass') and (character['type'] != 'water') and (character['type'] != 'fire'):
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            character['CP'] = int(input('輸入CP值: '))
            # 防呆
            if (character['CP'] < 1) or (character['CP'] > 999):
                print('輸入錯誤')
                continue
            else:
                print('新增完畢')
                break
    # 對戰
    elif num1 == 2:
        # 列出所有 list 中的寶可夢資料(需編號)
        for i in range(len(list)):
            print('編號', i, sep='')
            print('名字:', list[i]['Name'], sep='')
            print('屬性:', list[i]['type'], sep='')
            print('CP值:', list[i]['CP'], sep='')
        while True:
            num2 = int(input('選擇第一隻(輸入編號):'))
            # 防呆
            if num2 < 0 or num2 > len(list) - 1:
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            num3 = int(input('選擇第二隻(輸入編號):'))
            # 防呆
            if num3 < 0 or num3 > len(list) - 1:
                print('輸入錯誤')
                continue
            # 防呆
            elif num2 == num3:
                print('輸入錯誤')
                continue
            else:
                break
        # 分別討論各種可能的輸贏情況
        if list[num2]['CP'] > list[num3]['CP']:
            print('編號', num2, sep='', end=' ')
            print(list[num2]['Name'], '勝利', sep=' ')
            print('')
        elif list[num2]['CP'] < list[num3]['CP']:
            print('編號', num3, sep='', end=' ')
            print(list[num3]['Name'], '勝利', sep=' ')
            print('')
        elif list[num2]['CP'] == list[num3]['CP']:
            if list[num2]['type'] == 'grass' and list[num3]['type'] == 'water':
                print('編號', num2, sep='', end=' ')
                print(list[num2]['Name'], '勝利', sep=' ')
                print('')
            elif list[num2]['type'] == 'water' and list[num3]['type'] == 'fire':
                print('編號', num2, sep='', end=' ')
                print(list[num2]['Name'], '勝利', sep=' ')
                print('')
            elif list[num2]['type'] == 'fire' and list[num3]['type'] == 'grass':
                print('編號', num2, sep='', end=' ')
                print(list[num2]['Name'], '勝利', sep=' ')
                print('')
            elif list[num2]['type'] == list[num3]['type']:
                print('平手')
                print('')
            else:
                print('編號', num3, sep='', end=' ')
                print(list[num3]['Name'], '勝利', sep=' ')
                print('')
    elif num1 == 3:
        break
