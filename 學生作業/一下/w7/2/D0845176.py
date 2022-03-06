# 預設三個角色
# 用dict存
ch1 = {'Name': '妙娃種子', 'type': 'grass', 'CP': 100}
ch2 = {'Name': '小火龍', 'type': 'fire', 'CP': 100}
ch3 = {'Name': '傑尼龜', 'type': 'water', 'CP': 100}
# 將dict存在list
list1 = [ch1, ch2, ch3]
num = 3  # 計算幾個角色
while True:
    opt = int(input('選擇1.新增 2.對戰 3.結束：'))  # 選擇功能
    if opt == 1:
        name = input('輸入名字：')
        ty = input('輸入屬性：')
        while ty != 'fire' and ty != 'grass' and ty != 'water':  # 防呆
            print('輸入錯誤')
            ty = input('輸入屬性：')
        cp = int(input('輸入CP值：'))
        while cp < 1 or cp > 999:  # 防呆
            print('輸入錯誤')
            cp = int(input('輸入CP值：'))
        num += 1  # 多一個角色
        new = {'Name': name, 'type': ty, 'CP': cp}  # 將暫存放入一個dict
        list1.append(new)  # 新增在list最後
        print('新增完畢')
        print('')  # 換行
    elif opt == 2:
        for i in range(0, num):  # 印出每一個角色
            print('編號', i)
            print('名字：', list1[i]["Name"])
            print('屬性：', list1[i]["type"])
            print('CP值：', list1[i]["CP"])
        play1 = int(input('選擇第一隻(輸入編號)：'))
        while play1 < 0 or play1 > num - 1:  # 防呆
            print('輸入錯誤')
            play1 = int(input('選擇第一隻(輸入編號)：'))
        play2 = int(input('選擇第二隻(輸入編號)：'))
        while play2 < 0 or play2 > num - 1 or play2 == play1:  # 防呆
            print('輸入錯誤')
            play2 = int(input('選擇第二隻(輸入編號)：'))
        if list1[play1]["CP"] > list1[play2]["CP"]:
            print(f'編號{play1} {list1[play1]["Name"]} 勝利')
        elif list1[play1]["CP"] < list1[play2]["CP"]:
            print(f'編號{play2} {list1[play2]["Name"]} 勝利')
        else:
            if list1[play1]["type"] == 'water':
                if list1[play2]["type"] == 'fire':
                    print(f'編號{play1} {list1[play1]["Name"]} 勝利')
                elif list1[play2]["type"] == 'grass':
                    print(f'編號{play2} {list1[play2]["Name"]} 勝利')
                else:
                    print('平平')
            elif list1[play1]["type"] == 'fire':
                if list1[play2]["type"] == 'grass':
                    print(f'編號{play1} {list1[play1]["Name"]} 勝利')
                elif list1[play2]["type"] == 'water':
                    print(f'編號{play2} {list1[play2]["Name"]} 勝利')
                else:
                    print('平平')
            elif list1[play1]["type"] == 'grass':
                if list1[play2]["type"] == 'water':
                    print(f'編號{play1} {list1[play1]["Name"]} 勝利')
                elif list1[play2]["type"] == 'fire':
                    print(f'編號{play2} {list1[play2]["Name"]} 勝利')
                else:
                    print('平平')
        print('')
    elif opt == 3:
        break
    else:  # 防呆
        print('輸入錯誤')
        print('')
