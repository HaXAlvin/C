dict1 = {'名字': '妙蛙種子', '屬性': 'grass', 'CP值': 100}  # 設定妙蛙種子
dict2 = {'名字': '小火龍', '屬性': 'fire', 'CP值': 100}  # 設定小火龍
dict3 = {'名字': '傑尼龜', '屬性': 'water', 'CP值': 100}  # 設定傑尼龜

list = []  # 新增list
list.append(dict1)
list.append(dict2)
list.append(dict3)  # 將御三家寫入list

# list = [dict1, dict2, dict3]

while True:
    print('選擇1.新增 2.對戰 3.結束 ：')
    x = int(input())  # 指令輸入
    if x == 1:
        dict = {}  # 新增新的寶可夢屬性
        dict['名字'] = input('輸入名字： ')
        dict['屬性'] = input('輸入屬性： ')
        dict['CP值'] = int(input('輸入CP值： '))
        list.append(dict)
        print('新增完畢')
    elif x == 2:
        for i in range(len(list)):  # 列出現有的寶可夢
            print(list[i])
        p = int(input('選擇第一隻(輸入編號)： '))  # 輸入編號1
        q = int(input('選擇第二隻(輸入編號)： '))  # 輸入編號2
        if list[p]['CP值'] > list[q]['CP值']:  # 比較CP值
            print(list[p]['名字'], '勝利')
        elif list[p]['CP值'] < list[q]['CP值']:
            print(list[q]['名字'], '勝利')
        elif list[p]['CP值'] == list[q]['CP值']:  # 比較屬性
            if list[p]['屬性'] == 'fire' and list[q]['屬性'] == 'grass':
                print(list[p]['名字'], '勝利')
            elif list[p]['屬性'] == 'fire' and list[q]['屬性'] == 'water':
                print(list[q]['名字'], '勝利')
            elif list[p]['屬性'] == 'fire' and list[q]['屬性'] == 'fire':
                print('平手')
            elif list[p]['屬性'] == 'grass' and list[q]['屬性'] == 'grass':
                print('平手')
            elif list[p]['屬性'] == 'grass' and list[q]['屬性'] == 'water':
                print(list[p]['名字'], '勝利')
            elif list[p]['屬性'] == 'grass' and list[q]['屬性'] == 'fire':
                print(list[q]['名字'], '勝利')
            elif list[p]['屬性'] == 'water' and list[q]['屬性'] == 'grass':
                print(list[q]['名字'], '勝利')
            elif list[p]['屬性'] == 'water' and list[q]['屬性'] == 'water':
                print('平手')
            elif list[p]['屬性'] == 'water' and list[q]['屬性'] == 'fire':
                print(list[p]['名字'], '勝利')
    elif x == 3:  # 終止程式
        break
    else:
        print('輸入錯誤')
