Bulbasaur = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # dict
Charmander = {'name': '小火龍', 'type': 'fire', 'CP': 100}
Squirtle = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
whole = [Bulbasaur, Charmander, Squirtle]  # list
num = 2  # how many
while True:
    option = int(input('1.新增 2.對戰 3.結束:'))  # 轉型輸入
    if option == 1:
        num += 1
        tmp = {}
        whole.append(tmp)  # 新增
        whole[num]['name'] = str(input('輸入名字:'))
        while True:
            whole[num]['type'] = str(input('輸入屬性:'))
            if whole[num]['type'] == 'fire' or whole[num]['type'] == 'water' or whole[num]['type'] == 'grass':
                break
            print('輸入錯誤')
        while True:
            whole[num]['CP'] = int(input('輸入CP值:'))  # 轉型
            if 1 < whole[num]['CP'] < 1000:
                break
            print('輸入錯誤')
        print('新增完畢')
    elif option == 2:
        for i in range(num + 1):  # 包頭不包尾
            print('編號%d' % i)
            print('名字:%s' % whole[i]['name'])
            print('屬性:%s' % whole[i]['type'])
            print('CP值:%d' % whole[i]['CP'])
        while True:
            first = int(input('選擇第一隻(輸入編號):'))
            if -1 < first < num + 1:  # 包頭不包尾
                break
            print('輸入錯誤')
        while True:
            second: int = int(input('選擇第二隻(輸入編號):'))
            if -1 < second < num + 1 and first != second:  # 包頭不包尾
                break
            print('輸入錯誤')
        if whole[first]['CP'] > whole[second]['CP']:
            print('編號%d %s 勝利' % (first, whole[first]['name']))
        elif whole[first]['CP'] < whole[second]['CP']:
            print('編號%d %s 勝利' % (second, whole[second]['name']))
        else:
            if whole[first]['type'] == 'water' and whole[second]['type'] == 'fire':
                print('編號%d %s 勝利' % (first, whole[first]['name']))
            elif whole[first]['type'] == 'fire' and whole[second]['type'] == 'grass':
                print('編號%d %s 勝利' % (first, whole[first]['name']))
            elif whole[first]['type'] == 'grass' and whole[second]['type'] == 'water':
                print('編號%d %s 勝利' % (first, whole[first]['name']))
            elif whole[second]['type'] == 'water' and whole[first]['type'] == 'fire':
                print('編號%d %s 勝利' % (second, whole[second]['name']))
            elif whole[second]['type'] == 'fire' and whole[first]['type'] == 'grass':
                print('編號%d %s 勝利' % (second, whole[second]['name']))
            elif whole[second]['type'] == 'grass' and whole[first]['type'] == 'water':
                print('編號%d %s 勝利' % (second, whole[second]['name']))
            else:
                print('平手')
    elif option == 3:
        break
    else:  # 防呆
        print('輸入錯誤')
