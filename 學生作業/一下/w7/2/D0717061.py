dict1 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # dict紀錄寶可夢的資料
dict2 = {'name': '小火龍', 'type': 'fire', 'CP': 100}
dict3 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
list = [dict1, dict2, dict3]  # list儲存所有dict
x = 3  # 現有dict數量
while 1:
    num = int(input('選擇1.新增 2.對戰 3.結束：'))  # 輸入選擇
    if num == 1:  # 選擇新增
        x = x + 1  # 數量+1
        dictx = {'name': input('輸入名字：')}  # 宣告空dict
        while 1:
            dictx['type'] = input('輸入屬性：')  # 輸入屬性
            if dictx['type'] != 'water' and dictx['type'] != 'fire' and dictx['type'] != 'grass':  # 輸入三種屬性以外
                print('輸入錯誤')
            if dictx['type'] == 'water' or dictx['type'] == 'fire' or dictx['type'] == 'grass':  # 輸入正確
                break
        while 1:
            dictx['CP'] = int(input('輸入CP值：'))  # 輸入CP值
            if dictx['CP'] < 1 or dictx['CP'] > 999:  # 輸入CP值不在範圍內
                print('輸入錯誤')
            if 1 <= dictx['CP'] <= 999:  # 輸入正確
                break
        list.append(dictx)  # 新增dixtx到list
        print('新增完畢')
        print()  # 空一行
    if num == 2:  # 選擇對戰
        for i in range(len(list)):  # 迴圈印出每一個list裡的dict
            print('編號', i, sep='')
            print('名字：', list[i]['name'], sep='')
            print('屬性：', list[i]['type'], sep='')
            print('CP值：', list[i]['CP'], sep='')
        while 1:
            one = int(input('選擇第一隻(輸入編號)：'))  # 輸入第一隻編號
            if one > x - 1:  # 輸入為範圍外
                print('輸入錯誤')
            else:
                break
        while 1:
            two = int(input('選擇第二隻(輸入編號)：'))  # 輸入第二隻編號
            if two > x - 1:  # 輸入為範圍外
                print('輸入錯誤')
            elif two == one:  # 輸入與第一隻編號相同
                print('輸入錯誤')
            else:
                break
        if list[one]['CP'] > list[two]['CP']:  # 判斷CP值
            print('編號', one, ' ', list[one]['name'], ' ', '勝利', sep='')
        elif list[one]['CP'] < list[two]['CP']:
            print('編號', two, ' ', list[two]['name'], ' ', '勝利', sep='')
        elif list[one]['CP'] == list[two]['CP']:  # CP值相同
            if list[one]['type'] == 'water' and list[two]['type'] == 'fire':  # 判斷屬性
                print('編號', one, ' ', list[one]['name'], ' ', '勝利', sep='')
            elif list[one]['type'] == 'fire' and list[two]['type'] == 'grass':
                print('編號', one, ' ', list[one]['name'], ' ', '勝利', sep='')
            elif list[one]['type'] == 'grass' and list[two]['type'] == 'water':
                print('編號', one, ' ', list[one]['name'], ' ', '勝利', sep='')
            elif list[two]['type'] == 'water' and list[one]['type'] == 'fire':
                print('編號', two, ' ', list[two]['name'], ' ', '勝利', sep='')
            elif list[two]['type'] == 'fire' and list[one]['type'] == 'grass':
                print('編號', two, ' ', list[two]['name'], ' ', '勝利', sep='')
            elif list[two]['type'] == 'grass' and list[one]['type'] == 'water':
                print('編號', two, ' ', list[two]['name'], ' ', '勝利', sep='')
            else:
                print('平手')
        print()  # 空一行
    if num != 1 and num != 2 and num != 3:  # 選擇超出範圍
        print('輸入錯誤')
        print()  # 空一行
    if num == 3:  # 選擇結束程式
        exit()  # 結束程式
