cho = int(input('Choice 1.Add 2.Battle 3.Over:'))  # 選擇功能
dict1 = {'name': 'Bulbasuar', 'type': 'grass', 'CP': 100}  # 妙蛙種子
dict2 = {'name': 'Charmander', 'type': 'fire', 'CP': 100}  # 小火龍
dict3 = {'name': 'Squirtle', 'type': 'water', 'CP': 100}  # 傑尼龜
list1 = [dict1, dict2, dict3]  # list1包住dict1, dict2, dict3
number = 3  # 新增角色從list1第3項開始新增
while True:
    if cho == 1:  # 選擇2
        name_add = input('Name:')  # 輸入名字
        type_add = input('Type:')  # 輸入屬性
        while type_add != 'water' and type_add != 'fire' and type_add != 'grass':  # 若輸入屬性不是水/火/草性
            print('Input error!')  # 顯示錯誤
            type_add = input('Type:')  # 輸入屬性
        cp_add = int(input('CP points:'))  # 輸入CP值
        while cp_add < 1 or cp_add > 999:  # 若輸入值在1~999外
            print('Input error!')  # 顯示錯誤
            cp_add = int(input('CP points:'))  # 輸入CP值
        dict0 = {'name': name_add, 'type': type_add, 'CP': cp_add}  # 新增一個dictionary
        list1.append(dict0)  # 將新dictionary加到list1後面
        print('Finish adding.')  # 顯示完成新增
        number = number + 1  # 計數+1
    elif cho == 2:  # 選擇2
        for i in range(number):  # 從第0項到第number項
            print('No.', i)  # 編號
            print('Name:', list1[i]['name'])  # 名字
            print('Type:', list1[i]['type'])  # 屬性
            print('CP points:', list1[i]['CP'])  # CP值
        bat1 = int(input('Choose the first character:'))  # 選擇角色1
        while bat1 < 0 or bat1 >= number:  # 若選擇超出可選範圍
            print('Input error!')  # 顯示錯誤
            bat1 = int(input('Choose the first character:'))  # 選擇角色1
        bat2 = int(input('Choose the second character:'))  # 選擇角色2
        while bat2 == bat1 or (bat2 < 0 or bat2 >= number):  # 若角色2與角色1重複或選擇超出可選範圍
            print('Input error!')  # 顯示錯誤
            bat2 = int(input('Choose the second character:'))  # 選擇角色2
        if list1[bat1]['CP'] > list1[bat2]['CP']:  # 角色1 CP值 > 角色2 CP值
            print('No.', bat1, list1[bat1]['name'], 'wins!')  # 顯示角色1勝利
        elif list1[bat1]['CP'] < list1[bat2]['CP']:  # 角色1 CP值 < 角色2 CP值
            print('No.', bat2, list1[bat2]['name'], 'wins!')  # 顯示角色2勝利
        else:  # 角色1 CP值 = 角色2 CP值
            if list1[bat1]['type'] == 'water' and list1[bat2]['type'] == 'fire':  # 若角色1是水性，角色2是火性
                print('No.', bat1, list1[bat1]['name'], 'wins!')  # 顯示角色1勝利
            elif list1[bat1]['type'] == 'fire' and list1[bat2]['type'] == 'grass':  # 若角色1是火性，角色2是草性
                print('No.', bat1, list1[bat1]['name'], 'wins!')  # 顯示角色1勝利
            elif list1[bat1]['type'] == 'grass' and list1[bat2]['type'] == 'water':  # 若角色1是草性，角色2是水性
                print('No.', bat1, list1[bat1]['name'], 'wins!')  # 顯示角色1勝利
            elif list1[bat2]['type'] == 'water' and list1[bat1]['type'] == 'fire':  # 若角色2是水性，角色1是火性
                print('No.', bat2, list1[bat2]['name'], 'wins!')  # 顯示角色2勝利
            elif list1[bat2]['type'] == 'fire' and list1[bat1]['type'] == 'grass':  # 若角色2是火性，角色1是草性
                print('No.', bat2, list1[bat2]['name'], 'wins!')  # 顯示角色2勝利
            elif list1[bat2]['type'] == 'grass' and list1[bat1]['type'] == 'water':  # 若角色2是草性，角色1是水性
                print('No.', bat2, list1[bat2]['name'], 'wins!')  # 顯示角色2勝利
    elif cho == 3:  # 選擇3
        break  # 跳出迴圈
    elif cho >= 4 or cho <= 0:  # 若選擇超出可選範圍
        print('Input error!')  # 顯示錯誤
    print('')  # 空一行
    cho = int(input('Choice 1.Add 2.Battle 3.Over:'))  # 選擇功能
