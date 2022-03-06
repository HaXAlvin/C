dict0 = {'NO': 0, '名字': '妙蛙種子', '屬性': 'grass', 'CP值': 100}
dict1 = {'NO': 1, '名字': '小火龍', '屬性': 'fire', 'CP值': 100}
dict2 = {'NO': 2, '名字': '傑尼龜', '屬性': 'water', 'CP值': 100}
list = [dict0, dict1, dict2]  # 存入list
num = 100
for i in range(num):
    print("1.新增 2.對戰 3.結束：")
    a = int(input(''))  # 選擇新增、對戰、結束
    if a == 1:
        b = input('輸入名字:')
        list.append(b)
        c = input('輸入屬性:')
        while True:  # 非grass、fire、water重新輸入
            if c == 'grass':
                break
            elif c == 'fire':
                break
            elif c == 'water':
                break
            else:
                c = input('重新輸入屬性:')
        list.append(c)
        d = int(input('輸入CP值:'))
        while True:  # 小於1或大於999重新輸入
            if d < 1 or d > 999:
                d = int(input('重新輸入CP值'))
            else:
                break
        list.append(d)
    elif a == 2:
        '''NO=4
        for i in range(NO+1):#印出
            print('編號',list[i]['NO'])
            print('名字:',list[i]['名字'])
            print('屬性:',list[i]['姓名'])
            print('CP值:',list[i]['CP值'])
        e=int(input("選擇第一隻(輸入編號):"))
        f=int(input("選擇第一隻(輸入編號):"))
        if f==e:    
            f=int(input("選擇第一隻(輸入編號):"))#重新輸入'''
        print(list)
    elif a == 3:  # 結束程式
        break
    else:
        print('輸入錯誤')
