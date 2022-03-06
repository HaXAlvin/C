data1 = {'name': '妙蛙種子', 'type': 'grass', 'CP': 100}  # 3預設寶可夢數據
data2 = {'name': '小火龍', 'type': 'fire', 'CP': 100}
data3 = {'name': '傑尼龜', 'type': 'water', 'CP': 100}
data = [data1, data2, data3]  # 儲存數據的list
count = 3
while True:
    choose = int(input('1.新增 2.對戰 3.結束：'))  # 選擇功能
    if choose == 3:  # 結束
        break
    elif choose == 1:  # 新增
        temp = {'name': str(input('輸入名字：')), 'type': '0', 'CP': 0}  # 輸入名字
        while True:  # 輸入屬性(防呆)
            temp['type'] = str(input('輸入屬性：'))
            if (temp['type'] == 'fire') or (temp['type'] == 'water') or (temp['type'] == 'grass'):
                break  # 屬性規定
            print('輸入錯誤')
        while True:  # 輸入CP值(防呆)
            temp['CP'] = int(input('輸入CP值：'))
            if 1 <= temp['CP'] <= 999:
                break  # CP值規定
            print('輸入錯誤')
        data.append(temp)  # 將暫存的輸入存入設好的list
        count = count + 1  # 資料數加1
        print('新增完畢', end='\n\n')
    elif choose == 2:  # 對戰
        first = int()
        second = int()
        for i in range(count):  # 印出所有寶可夢數據
            print('編號', i, sep='')
            print('名字：', data[i]['name'], sep='')
            print('屬性：', data[i]['type'], sep='')
            print('CP值：', data[i]['CP'], sep='')
        while True:  # 選擇第一隻對戰寶可夢數據
            first = int(input('選擇第一隻(輸入編號)：'))
            if 0 <= first < count:
                break  # 選擇編號存在
            print('輸入錯誤')
        while True:  # 選擇第二隻對戰寶可夢數據
            second = int(input('選擇第二隻(輸入編號)：'))
            if (0 <= second < count) and (first != second):
                break  # 選擇編號存在且不重複
            print('輸入錯誤')
        f_data = data[first]
        s_data = data[second]
        if f_data['CP'] > s_data['CP']:  # 第一隻CP值大於第二隻CP值
            print('編號', first, sep='', end=' ')
            print(f_data['name'], '勝利', sep=' ', end='\n\n')
        elif s_data['CP'] > f_data['CP']:  # 第二隻CP值大於第一隻
            print('編號', second, sep='', end=' ')
            print(s_data['name'], '勝利', sep=' ', end='\n\n')
        else:  # CP值相等
            if (f_data['type'] == 'water' and s_data['type'] == 'fire') or (
                    f_data['type'] == 'fire' and s_data['type'] == 'grass') or (
                    f_data['type'] == 'grass' and s_data['type'] == 'water'):  # 第一隻屬性剋第二隻屬性
                print('編號', first, sep='', end=' ')
                print(f_data['name'], '勝利', sep=' ', end='\n\n')
            elif (s_data['type'] == 'water' and f_data['type'] == 'fire') or (
                    s_data['type'] == 'fire' and f_data['type'] == 'grass') or (
                    s_data['type'] == 'grass' and f_data['type'] == 'water'):  # 第二隻屬性剋第一隻屬性
                print('編號', second, sep='', end=' ')
                print(s_data['name'], '勝利', sep=' ', end='\n\n')
            else:  # 屬性相等
                print('平手', end='\n\n')
    else:  # 選擇功能防呆
        print('輸入錯誤', end='\n\n')
