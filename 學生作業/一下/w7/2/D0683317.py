poki0 = {'name': '妙蛙種子', 'type': 'grass', 'cp': 100}
poki1 = {'name': '小火龍', 'type': 'fire', 'cp': 100}
poki2 = {'name': '傑尼龜', 'type': 'water', 'cp': 100}
pokilist = [poki0['name'], poki0['type'], poki0['cp'], poki1['name'], poki1['type'], poki1['cp'], poki2['name'],
            poki2['type'], poki2['cp']]

check = 3  # 記錄寶可夢數量

while True:
    order = input('選擇1.新增 2.對戰 3.結束: ')

    if order == '1':  # 新增list資料
        new = input('輸入名字:')
        pokilist.append(new)
        while True:
            new = input('輸入屬性:')
            if new != 'fire' and new != 'water' and new != 'grass':  # 輸入錯誤判斷
                print('輸入錯誤')
            else:
                pokilist.append(new)
                break
        while True:
            new = int(input('輸入CP值:'))  # 輸入錯誤判斷
            if new > 999 or new < 1:
                print('輸入錯誤')
            else:
                pokilist.append(new)  # 新增list資料
                break
        print('新增完畢')
        check += 1  # 增加寶可夢數量

    elif order == '2':  # 對戰
        for i in range(check):  # 印出寶可夢資料
            print('編號', i)
            print('名字:', pokilist[i * 3])
            print('屬性:', pokilist[i * 3 + 1])
            print('CP值:', pokilist[i * 3 + 2])

        end = 1
        while end != 0:
            select1 = int(input('選擇第一隻(輸入編號):'))
            for i in range(check):  # 找出對應寶可夢資料
                if select1 == i:
                    selectCp1 = pokilist[i * 3 + 2]
                    end = 0
            if end != 0:
                print("輸入錯誤")

        end = 1
        while end != 0:
            select2 = int(input('選擇第二隻(輸入編號):'))
            for i in range(check):  # 找出對應寶可夢資料
                if select2 == i and select2 != select1:
                    selectCp2 = pokilist[i * 3 + 2]
                    end = 0
            if end != 0:
                print("輸入錯誤")

        if selectCp1 > selectCp2:  # 比較寶可夢cp值和屬性
            print('編號:', select1, pokilist[select1 * 3], '勝利')
        elif selectCp1 < selectCp2:
            print('編號:', select2, pokilist[select2 * 3], '勝利')
        else:
            if pokilist[select1 * 3 + 1] == pokilist[select2 * 3 + 1]:
                print('平手')
            elif pokilist[select1 * 3 + 1] == 'water' and pokilist[select2 * 3 + 1] == 'fire':
                print('編號:', select1, pokilist[select1 * 3], '勝利')
            elif pokilist[select1 * 3 + 1] == 'water' and pokilist[select2 * 3 + 1] == 'grass':
                print('編號:', select2, pokilist[select2 * 3], '勝利')
            elif pokilist[select1 * 3 + 1] == 'fire' and pokilist[select2 * 3 + 1] == 'water':
                print('編號:', select2, pokilist[select2 * 3], '勝利')
            elif pokilist[select1 * 3 + 1] == 'fire' and pokilist[select2 * 3 + 1] == 'grass':
                print('編號:', select1, pokilist[select1 * 3], '勝利')
            elif pokilist[select1 * 3 + 1] == 'grass' and pokilist[select2 * 3 + 1] == 'water':
                print('編號:', select1, pokilist[select1 * 3], '勝利')
            elif pokilist[select1 * 3 + 1] == 'grass' and pokilist[select2 * 3 + 1] == 'fire':
                print('編號:', select2, pokilist[select2 * 3], '勝利')

    elif order == '3':  # 結束程式
        break
    else:  # 輸入判斷
        print('輸入錯誤')
