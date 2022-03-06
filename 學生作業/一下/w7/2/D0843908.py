list = [0, 1, 2, 3, 4, 5, 6, 7, 8]
dict = {0: '妙蛙種子', 1: 'grass', 2: 100, 3: '小火龍', 4: 'fire', 5: 100, 6: '傑尼龜', 7: 'water', 8: 100}
while True:
    whattodo = int(input('選擇1.新增 2.對戰 3.結束:'))
    # 新增角色
    if whattodo == 1:
        # 變更list的長度
        for i in range(3):
            print(list)
            list.append(len(list))
        dict[len(list) - 3] = input('輸入名字:')
        while True:
            dict[len(list) - 2] = input('輸入屬性:')
            if dict[len(list) - 2] != 'fire' and dict[len(list) - 2] != 'water' and dict[(len(list) - 2)] != 'grass':
                print('輸入錯誤')
                continue
            else:
                break
        while True:
            dict[len(list) - 1] = int(input('輸入CP值:'))
            if 1 <= dict[len(list) - 1] <= 999:
                break
            else:
                print('輸入錯誤')
                continue
        print('新增完畢')
    # 戰鬥
    if whattodo == 2:
        # 印出角色資訊
        for i in range(int(len(list) / 3)):
            print('編號', i)
            print('名字:', dict[list[0 + 3 * i]])
            print('屬性:', dict[list[1 + 3 * i]])
            print('CP值', dict[list[2 + 3 * i]])
        # 輸入角色1
        while True:
            num1 = int(input('選擇第一隻(輸入編號):'))
            if 0 <= num1 < (len(list) / 3):
                num1_name = dict[0 + 3 * num1]
                num1_type = dict[1 + 3 * num1]
                num1_CP = dict[2 + 3 * num1]
                break
            else:
                print('輸入錯誤')
                continue
        # 輸入角色2
        while True:
            num2 = int(input('選擇第二隻(輸入編號):'))
            if 0 <= num2 < (len(list) / 3) and num2 != num1:
                num2_name = dict[0 + 3 * num2]
                num2_type = dict[1 + 3 * num2]
                num2_CP = dict[2 + 3 * num2]
                break
            else:
                print('輸入錯誤')
                continue
        # 先判斷CP決勝負
        if num1_CP > num2_CP:
            print('編號', num1, num1_name, '勝利')
        if num2_CP > num1_CP:
            print('編號', num2, num2_name, '勝利')
        # 若CP相同 判斷屬性
        if num1_CP == num2_CP:
            if num1_type == 'fire' and num2_type == 'grass':
                print('編號', num1, num1_name, '勝利')
            if num1_type == 'water' and num2_type == 'fire':
                print('編號', num1, num1_name, '勝利')
            if num1_type == 'grass' and num2_type == 'water':
                print('編號', num1, num1_name, '勝利')
            if num2_type == 'fire' and num1_type == 'grass':
                print('編號', num2, num2_name, '勝利')
            if num2_type == 'water' and num1_type == 'fire':
                print('編號', num2, num2_name, '勝利')
            if num2_type == 'grass' and num1_type == 'water':
                print('編號', num2, num2_name, '勝利')
            # 若屬性相同 平手
            if num1_type == num2_type:
                print('平手')
    # 程式結束
    if whattodo == 3:
        break
