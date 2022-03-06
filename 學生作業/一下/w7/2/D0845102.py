dict0 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}
dict1 = {'name': '小火龍', 'type': 'fire', 'CP': 100}
dict2 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
dict3 = {'name': 'unknown', 'type': 'unknown', 'CP': 0}
list1 = [dict0, dict1, dict2, dict3]
while True:
    option = int(input('選擇1.新增 2.對戰 3.結束:'))
    if option == 1:  # 選項1
        list1[3]['name'] = (input('輸入名字:'))  # 輸入名字
        while True:  # 檢察屬性
            list1[3]['type'] = (input('輸入屬性:'))
            if list1[3]['type'] == 'fire':
                break
            elif list1[3]['type'] == 'water':
                break
            elif list1[3]['type'] == 'grass':
                break
            else:
                print('輸入錯誤')
        while True:  # 檢查CP
            list1[3]['CP'] = (int(input('輸入CP:')))
            if list1[3]['CP'] < 1:
                print('輸入錯誤')
            elif list1[3]['CP'] > 999:
                print('輸入錯誤')
            else:
                break
        print('新增完畢')
    elif option == 2:
        # list[0]['Name']
        print('編號0\nName:{}\ntype:{}\nCP:{}'.format(list1[0]['name'], list1[0]['type'], list1[0]['CP']))  # 印出資料
        print('編號1\nName:{}\ntype:{}\nCP:{}'.format(list1[1]['name'], list1[1]['type'], list1[1]['CP']))
        print('編號2\nName:{}\ntype:{}\nCP:{}'.format(list1[2]['name'], list1[2]['type'], list1[2]['CP']))
        if list1[3]['name'] != 'unknown':
            print(
                '編號3\nName:{}\ntype:{}\nCP:{}'.format(list1[3]['name'], list1[3]['type'], list1[3]['CP']))  # 檢查是否有新增角色
        while True:
            first_battle = int(input('選擇第一隻(輸入編號:)'))
            if list1[3]['name'] != 'unknown':  # 檢查角色存在
                if first_battle > 4:
                    print('輸入錯誤')
                elif first_battle < 0:
                    print('輸入錯誤')
                else:
                    break
            elif list1[3]['name'] == 'unknown':  # 檢查角色存在
                if first_battle > 3:
                    print('輸入錯誤')
                elif first_battle < 0:
                    print('輸入錯誤')
                else:
                    break
        while True:
            sec_battle = int(input('選擇第二隻(輸入編號:)'))
            if list1[3]['name'] != 'unknown':  # 檢查角色存在
                if sec_battle > 3:
                    print('輸入錯誤')
                elif sec_battle < 0:
                    print('輸入錯誤')
                elif sec_battle == first_battle:
                    print('輸入錯誤')
                else:
                    break
            elif list1[3]['name'] == 'unknown':  # 檢查角色存在
                if sec_battle > 2:
                    print('輸入錯誤')
                elif sec_battle < 0:
                    print('輸入錯誤')
                elif sec_battle == first_battle:
                    print('輸入錯誤')
                else:
                    break
        if first_battle == 0:  # 代入各項數值
            num1 = list1[0]['CP']
            name1 = list1[0]['name']
            type1 = list1[0]['type']
        elif first_battle == 1:
            num1 = list1[1]['CP']
            name1 = list1[1]['name']
            type1 = list1[1]['type']
        elif first_battle == 2:
            num1 = list1[2]['CP']
            name1 = list1[2]['name']
            type1 = list1[2]['type']
        else:
            num1 = list1[3]['CP']
            name1 = list1[3]['name']
            type1 = list1[3]['type']
        if sec_battle == 0:  # 代入各項數值
            num2 = list1[0]['CP']
            name2 = list1[0]['name']
            type2 = list1[0]['type']
        elif sec_battle == 1:
            num2 = list1[1]['CP']
            name2 = list1[1]['name']
            type2 = list1[1]['type']
        elif sec_battle == 2:
            num2 = list1[2]['CP']
            name2 = list1[2]['name']
            type2 = list1[2]['type']
        else:
            num2 = list1[3]['CP']
            name2 = list1[3]['name']
            type2 = list1[3]['type']
        if num1 > num2:  # 判斷勝利_CP值
            print('編號{} {} 勝利\n'.format(first_battle, name1))
        elif num2 > num1:  # 判斷勝利_CP值
            print('編號{} {} 勝利\n'.format(sec_battle, name2))
        else:
            if (type1 == 'fire') and (type2 == 'grass'):  # 判斷勝利_
                print('編號{} {} 勝利\n'.format(first_battle, name1))
            elif (type1 == 'water') and (type2 == 'fire'):
                print('編號{} {} 勝利\n'.format(first_battle, name1))
            elif (type1 == 'grass') and (type2 == 'water'):
                print('編號{} {} 勝利\n'.format(first_battle, name1))
            elif type1 == type2:
                print('平手')
            else:
                print('編號{} {} 勝利\n'.format(sec_battle, name2))
    elif option == 3:  # 結束程式
        break
    else:
        print('輸入錯誤')  # 回到開頭
