dict_a = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # 預設的三個角色
dict_b = {'name': '小火龍', 'type': 'fire', 'CP': 100}
dict_c = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
listTotal = [dict_a, dict_b, dict_c]  # 設一個list存dict
count = 3  # 目前角色數量
while True:
    userInput = int(input('1.新增 2.對戰 3.結束：'))  # 功能選擇
    if userInput == 3:  # 結束
        break
    elif userInput == 1:  # 新增
        dict_tmp = dict(name=input('輸入名字:'))  # 設置暫存存新增數據
        while True:
            dict_tmp['type'] = input('輸入屬性:')  # 屬入屬性+防呆
            if dict_tmp['type'] != 'grass' and dict_tmp['type'] != 'fire' and dict_tmp['type'] != 'water':
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            dict_tmp['CP'] = int(input('輸入CP值:'))  # 屬入CP值+防呆
            if dict_tmp['CP'] < 1 or dict_tmp['CP'] > 999:
                print('輸入錯誤')
                continue
            else:
                break
        print(dict_tmp)
        listTotal.append(dict_tmp)  # 將暫存加入list
        count = count + 1  # 新增角色數量
        print('新增完畢\n')
    elif userInput == 2:  # 對戰
        for i in range(count):
            print('編號', i, '\n名字:', listTotal[i]['name'], '\n屬性:', listTotal[i]['type'], '\nCP值:', listTotal[i]['CP'],
                  sep='')  # 印出角色
        while True:
            a = int(input('選擇第一隻(輸入編號):'))  # 輸入第一隻對戰角+防呆
            if a > len(listTotal) - 1:
                print('輸入錯誤!')
            else:
                break
        while True:
            b = int(input('選擇第二隻(輸入編號):'))  # 輸入第二隻對戰角+防呆
            if a == b:
                print('輸入錯誤!')
            elif b > len(listTotal) - 1:
                print('輸入錯誤!')
            else:
                break
        if listTotal[a]['CP'] > listTotal[b]['CP']:  # 判斷勝負
            print('編號', a, ' ', listTotal[a]['name'], ' 勝利\n', sep='')
        elif listTotal[a]['CP'] < listTotal[b]['CP']:
            print('編號', b, ' ', listTotal[b]['name'], ' 勝利\n', sep='')
        else:
            if listTotal[a]['type'] == 'water':
                if listTotal[b]['type'] == 'fire':
                    print('編號', a, ' ', listTotal[a]['name'], ' 勝利\n', sep='')
                elif listTotal[b]['type'] == 'water':
                    print('平手!')
                elif listTotal[b]['type'] == 'grass':
                    print('編號', b, ' ', listTotal[b]['name'], ' 勝利\n', sep='')
            if listTotal[a]['type'] == 'fire':
                if listTotal[b]['type'] == 'grass':
                    print('編號', a, ' ', listTotal[a]['name'], ' 勝利\n', sep='')
                elif listTotal[b]['type'] == 'fire':
                    print('平手!')
                elif listTotal[b]['type'] == 'water':
                    print('編號', b, ' ', listTotal[b]['name'], ' 勝利\n', sep='')
            if listTotal[a]['type'] == 'grass':
                if listTotal[b]['type'] == 'water':
                    print('編號', a, ' ', listTotal[a]['name'], ' 勝利\n', sep='')
                elif listTotal[b]['type'] == 'grass':
                    print('平手!')
                elif listTotal[b]['type'] == 'fire':
                    print('編號', b, ' ', listTotal[b]['name'], ' 勝利\n', sep='')
    else:  # 防呆
        print('輸入錯誤!\n')
