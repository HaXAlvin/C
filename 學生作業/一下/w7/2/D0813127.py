list1 = [{'name': '妙蛙種子', 'type': 'grass', 'CP': 100},
         {'name': '小火龍', 'type': 'fire', 'CP': 100},
         {'name': '傑尼龜', 'type': 'water', 'CP': 100}]
# 預設三隻
while True:
    sle = int(input('選擇1.新增 2.對戰 3.結束：'))
    if sle == 1:  # 新增
        new_name = input('輸入名字：')
        while True:
            new_type = input('輸入屬性：')
            if new_type == 'fire' or new_type == 'grass' or new_type == 'water':
                break
            print('輸入錯誤')  # 防呆
        while True:
            new_CP = int(input('輸入CP值：'))
            if 0 < new_CP < 1000:
                break
            print('輸入錯誤')  # 防呆
        list1.append({'name': new_name, 'type': new_type, 'CP': new_CP})
        # 將新增的寶可夢加到List1的最尾端
        print('新增完畢')
    elif sle == 2:
        for i in range(len(list1)):  # 印出所有的寶可夢
            print('編號{}' .format(i))
            print('名字：{}' .format(list1[i]['name']))
            print('屬性：{}' .format(list1[i]['type']))
            print('CP值：{}'.format(list1[i]['CP']))
        a1 = 0
        a2 = 0
        while True:
            a1 = int(input('選擇第一隻(輸入編號)：'))
            if 0 <= a1 < len(list1):
                break
            print('輸入錯誤')  # 防呆
        while True:
            a2 = int(input('選擇第二隻(輸入編號)：'))
            if 0 <= a2 < len(list1) and not(a2 == a1):
                break
            print('輸入錯誤')  # 防呆
        if list1[a1]['CP'] > list1[a2]['CP']:  # CP值判斷勝利
            print('編號{} {} 勝利' .format(a1, list1[a1]['name']))
        elif list1[a2]['CP'] > list1[a1]['CP']:
            print('編號{} {} 勝利' .format(a2, list1[a2]['name']))
        else:  # CP值相同改用屬性判斷勝利
            if (list1[a1]['type'] == 'fire' and list1[a2]['type'] == 'grass') or \
                    (list1[a1]['type'] == 'grass' and list1[a2]['type'] == 'water') or \
                    (list1[a1]['type'] == 'water' and list1[a2]['type'] == 'fire'):
                print('編號{} {} 勝利' .format(a1, list1[a1]['name']))
            elif (list1[a2]['type'] == 'fire' and list1[a1]['type'] == 'grass') or \
                    (list1[a2]['type'] == 'grass' and list1[a1]['type'] == 'water') or \
                    (list1[a2]['type'] == 'water' and list1[a1]['type'] == 'fire'):
                print('編號{} {} 勝利' .format(a2, list1[a2]['name']))
            else:
                print('平手')
        print('')
    elif sle == 3:
        break
    else:
        print('輸入錯誤')  # 防呆
        print('')
