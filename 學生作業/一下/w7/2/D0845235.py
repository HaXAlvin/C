dict0 = {'name': '妙蛙種子', 'type': 'grass', 'Cp': 100}
dict1 = {'name': '小火龍', 'type': 'fire', 'Cp': 100}
dict2 = {'name': '傑尼龜', 'type': 'water', 'Cp': 100}
list = [dict0, dict1, dict2]  # 建立一個列表
count = 2  # 計時器
num = 0  # 編號
while True:
    choice = int(input('選擇: 1.新增 2.對戰 3.結束:'))  # 輸入選擇1,2,3
    if choice < 1 or choice > 3:  # 選擇輸入錯誤
        print('輸入錯誤，請重新輸入\n')
        continue  # 跳出本次迴圈，繼續下一圈
    if choice == 1:  # 新增
        dict_add = {'name': input('輸入名字:'), 'type': input('輸入屬性:')}  # 輸入新增角色的名字與屬性
        while dict_add['type'] != 'fire' and dict_add['type'] != 'water' and dict_add['type'] != 'grass':  # 新增角色的屬性錯誤
            print("輸入屬性錯誤，請重新輸入")
            dict_add['type'] = input('輸入屬性:')  # 重新輸入屬性
        dict_add['Cp'] = int(input('輸入Cp值:'))  # 輸入新增角色的Cp值
        while dict_add['Cp'] < 1 or dict_add['Cp'] > 999:  # 新增角色的Cp值錯誤
            print('輸入Cp值錯誤，請重新輸入')
            dict_add['Cp'] = int(input('輸入Cp值:'))  # 重新輸入Cp值
        print('新增完畢')
        list.append(dict_add)  # 將新增角色的數據貼在list的最後
        count += 1  # 計算新增到第幾個角色
    elif choice == 2:  # 對戰
        for i in range(count):  # 用迴圈印出所有角色的數據
            print('編號', i, sep='')
            print('名字:', list[i]['name'], sep='')
            print("屬性:", list[i]['type'], sep='')
            print("Cp值:", list[i]['Cp'], sep='')
        first = int(input('選擇第一隻(輸入編號):'))
        while first < 0 or first > count:  # 第一隻的編號輸入錯誤
            print('輸入錯誤，請重新輸入')
            first = int(input('選擇第一隻(輸入編號):'))  # 重新輸入第一隻的編號
        last = int(input('選擇第二隻(輸入編號):'))
        while last < 0 or last > count:  # 第二隻的編號輸入錯誤
            print('輸入錯誤，請重新輸入')
            last = int(input('選擇第二隻(輸入編號):'))  # 重新輸入第二隻的編號
        while first == last:  # 輸入第一隻與第二隻的編號重複
            print('輸入角色重複，請重新輸入')
            last = int(input('選擇第二隻(輸入編號):'))
        if list[first]['Cp'] > list[last]['Cp']:  # 第一隻寶可夢的Cp值大於第二隻寶可夢
            print('編號', first, ' 名字', list[first]['name'], ' 勝利\n', sep='')
        elif list[last]['Cp'] > list[first]['Cp']:  # 第二隻寶可夢的Cp值大於第一隻寶可夢
            print('編號', last, ' 名字', list[last]['name'], ' 勝利\n', sep='')
        elif list[first]['Cp'] == list[last]['Cp']:  # 兩隻寶可夢Cp值一樣大，則判斷屬性
            if list[first]['type'] == 'water' and list[last]['type'] == 'fire':  # 水剋火
                print('編號', first, ' 名字', list[first]['name'], ' 勝利\n', sep='')
            elif list[first]['type'] == 'fire' and list[last]['type'] == 'grass':  # 火剋草
                print('編號', first, ' 名字', list[first]['name'], ' 勝利\n', sep='')
            elif list[first]['type'] == 'grass' and list[last]['type'] == 'water':  # 草剋水
                print('編號', first, ' 名字', list[first]['name'], ' 勝利\n', sep='')
            elif list[last]['type'] == 'water' and list[first]['type'] == 'fire':  # 水剋火
                print('編號', last, ' 名字', list[last]['name'], ' 勝利\n', sep='')
            elif list[last]['type'] == 'fire' and list[first]['type'] == 'grass':  # 火剋草
                print('編號', last, ' 名字', list[last]['name'], ' 勝利\n', sep='')
            elif list[last]['type'] == 'grass' and list[first]['type'] == 'water':  # 草剋水
                print('編號', last, ' 名字', list[last]['name'], ' 勝利\n', sep='')
    elif choice == 3:  # 結束
        break
