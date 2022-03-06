name1 = ['妙蛙種子', '小火龍', '傑尼龜']
type1 = ['grass', 'fire', 'water']
cp1 = [100, 100, 100]
n = 3
while True:
    opt = int(input('選擇1.新增 2.對戰 3.結束:'))  # 選擇選項
    while opt < 1 or opt > 3:  # 輸入大於3或小於1輸入錯誤
        print('輸入錯誤!')
        opt = int(input('選擇1.新增 2.對戰 3.結束:'))  # 重新迴圈直到1<=opt<=3
    if opt == 1:  # 新增
        n += 1
        new_name = input('輸入名字:')  # 新增角色姓名
        new_type = input('輸入屬性:')  # 新增角色屬性
        while new_type != 'grass' and new_type != 'fire' and new_type != 'water':  # 屬性不為上述即重新迴圈
            print('輸入錯誤!')
            new_type = input('輸入屬性:')  # 重新迴圈直到屬性為上述其一
        new_cp = int(input('輸入CP值:'))  # 新增角色CP值
        while new_cp > 999 or new_cp < 1:  # CP值無介於1~999重新迴圈
            print('輸入錯誤!')
            new_cp = int(input('輸入CP值:'))  # 重新迴圈直到CP值介於1~999
        name1.append(new_name)  # 新增在name1最後
        type1.append(new_type)  # 新增在type1最後
        cp1.append(new_cp)  # 新增在cp1最後
        print('新增完畢')
    if opt == 2:  # 對戰
        for i in range(n):  # print出list中的所有東西 總共有n個角色
            print('編號 ', i, '\n', '名字: ', name1[i], '\n', '屬性: ', type1[i], '\n', 'CP值: ', cp1[i], sep='')
        atk1 = int(input('選擇第一隻(輸入編號):'))
        while atk1 > n - 1 or atk1 < 0:  # 對戰atk1不介於0~n-1，重新迴圈
            print('輸入錯誤!')
            atk1 = int(input('選擇第一隻(輸入編號):'))
        atk2 = int(input('選擇第二隻(輸入編號):'))
        while atk1 == atk2 or atk2 > n - 1 or atk2 < 0:  # 對戰角色重複及atk2不介於0~n-1，重新迴圈
            print('輸入錯誤!')
            atk2 = int(input('選擇第二隻(輸入編號):'))  # 重新迴圈直到對戰角色不重複
        if cp1[atk1] == cp1[atk2]:  # CP值一樣時 比較屬性g > w > f > g
            if (type1[atk1] == 'fire' and type1[atk2] == 'fire') or (
                    type1[atk1] == 'grass' and type1[atk2] == 'grass') or (
                    type1[atk1] == 'water' and type1[atk2] == 'water'):  # CP值,屬性皆相同
                print('平手')
            elif type1[atk1] == 'grass':
                if type1[atk2] == 'water':
                    print('編號', atk1, name1[atk1], '勝利')
                elif type1[atk2] == 'fire':
                    print('編號', atk2, name1[atk2], '勝利')
            elif type1[atk1] == 'water':
                if type1[atk2] == 'fire':
                    print('編號', atk1, name1[atk1], '勝利')
                elif type1[atk2] == 'grass':
                    print('編號', atk2, name1[atk2], '勝利')
            elif type1[atk1] == 'fire':
                if type1[atk2] == 'grass':
                    print('編號', atk1, name1[atk1], '勝利')
                elif type1[atk2] == 'water':
                    print('編號', atk2, name1[atk2], '勝利')
        elif cp1[atk1] > cp1[atk2]:  # 比較cp值 第一隻 > 第二隻
            print('編號', atk1, name1[atk1], '勝利')
        else:  # 比較cp值 第一隻 < 第二隻
            print('編號', atk2, name1[atk2], '勝利')
    if opt == 3:  # 結束
        break
