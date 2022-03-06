poke1 = {'name': '妙娃種子', 'type': 'grass', 'CP': int(100)}
poke2 = {'name': '小火龍', 'type': 'fire', 'CP': int(100)}
poke3 = {'name': '傑尼龜', 'type': 'water', 'CP': int(100)}  # 先設置3個dict來儲存題目要求的三個寶可夢
poke = [poke1, poke2, poke3]  # 將所有的寶可夢用成一個list
while 1:
    choose = int(input('選擇:1.新增 2.對戰 3.結束:'))
    if choose < 1 or choose > 3:
        print('輸入錯誤')
        continue  # 防呆
    elif choose == 1:
        add = {}  # 設新增的寶可夢為dict格式
        poke.append(add)  # 新增至list尾端
        add['name'] = input('輸入名子:')  # 輸入名子
        while 1:
            add['type'] = input('輸入屬性:')  # 輸入屬性
            if add['type'] != 'grass' and add['type'] != 'fire' and add['type'] != 'water':
                print('輸入錯誤')
                continue
            else:
                break  # 防呆
        while 1:
            add['CP'] = int(input('輸入CP值:'))
            if add['CP'] < 1 or add['CP'] > 999:
                print('輸入錯誤')
                continue
            else:
                break  # 防呆
        print('新增完畢')
    elif choose == 2:
        count = 0
        for i in range(len(poke)):
            print('編號', count)
            print('名子', poke[count]['name'])
            print('屬性:', poke[count]['type'])
            print('CP值:', poke[count]['CP'])
            count += 1  # 用count紀錄寶可夢的數量跑出所有的寶可夢
        while 1:
            pk1 = int(input('選擇第一隻(輸入編號):'))  # 設置pk1為第一隻參賽者
            if pk1 < 0 or pk1 > len(poke) - 1:
                print('輸入錯誤')
                continue
            else:
                break  # 防呆
        while 1:
            pk2 = int(input('選擇第二隻(輸入編號):'))  # 設置pk2為第二隻參賽者
            if pk2 < 0 or pk2 > len(poke) - 1 or pk1 == pk2:
                print('輸入錯誤')
                continue
            else:
                break  # 防呆
        if poke[pk1]['CP'] > poke[pk2]['CP']:
            print('編號', pk1, poke[pk1]['name'], '勝利')  # 如果pk1的CP值較高 則pk1獲勝
        elif poke[pk1]['CP'] == poke[pk2]['CP']:
            if ((poke[pk1]['type'] == 'water' and poke[pk2]['type'] == 'fire') or (
                    poke[pk1]['type'] == 'fire' and poke[pk2]['type'] == 'grass') or (
                    poke[pk1]['type'] == 'grass' and poke[pk2]['type'] == 'water')):
                print('編號', pk1, poke[pk1]['name'], '勝利')
            elif ((poke[pk1]['type'] == 'water' and poke[pk2]['type'] == 'water') or (
                    poke[pk1]['type'] == 'fire' and poke[pk2]['type'] == 'fire') or (
                          poke[pk1]['type'] == 'grass' and poke[pk2]['type'] == 'grass')):
                print('平手')  # 若CP值與屬性皆相同 則平手
            else:
                print('編號', pk2, poke[pk2]['name'], '勝利')  # 如果能力值相同 則以屬性剋性為依據
        else:
            print('編號', pk2, poke[pk2]['name'], '勝利')  # 剩下的情況皆為pk2獲勝
    elif choose == 3:
        break  # 結束迴圈也結束程式
