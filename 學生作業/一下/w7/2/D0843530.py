pokemon = [  # 初始化
    {'Name': '妙蛙種子', 'type': 'grass', 'CP': 100},
    {'Name': '小火龍', 'type': 'fire', 'CP': 100},
    {'Name': '傑尼龜', 'type': 'water', 'CP': 100}]
while True:
    chose = int(input('1.新增 2.對戰 3.結束:'))  # 輸入選項
    if chose == 1:  # 新增
        name = input('輸入名字:')
        while True:
            Typee = input('輸入屬性:')
            if Typee == 'grass' or Typee == 'water' or Typee == 'fire':  # 判斷屬性有沒有打錯
                break
            else:
                print('輸入錯誤')
        while True:
            cp = input('輸入CP值:')  # 判斷CP有沒有超出範圍
            if 1 <= int(cp) <= 999:
                break
            else:
                print('輸入錯誤')
        a = {'Name': name, 'type': Typee, 'CP': int(cp)}
        pokemon.append(a)  # 加在list後面
        print('新增完畢')
    elif chose == 2:  # 對戰
        for i in range(len(pokemon)):  # 印出所有現有堡可夢
            print('編號' + str(i))
            print('名字:' + pokemon[i]["Name"])
            print('屬性:' + pokemon[i]["type"])
            print('CP值:' + str(pokemon[i]["CP"]))
        while True:
            one = int(input('選擇第一隻(輸入編號):'))  # 判斷有沒有那個編號
            if one >= len(pokemon):
                print('輸入錯誤')
            else:
                break
        while True:
            two = int(input('選擇第二隻(輸入編號):'))  # 判斷有沒有那個編號及重複
            if two >= len(pokemon) or two == one:
                print('輸入錯誤')
            else:
                break
        if pokemon[one]["CP"] > pokemon[two]["CP"]:  # 輸贏阿
            win = one
        elif pokemon[one]["CP"] == pokemon[two]["CP"]:
            if pokemon[one]["type"] == 'water':
                if pokemon[two]["type"] == 'fire':
                    win = one
                elif pokemon[two]["type"] == 'grass':
                    win = two
                else:
                    win = 0
            elif pokemon[one]["type"] == 'fire':
                if pokemon[two]["type"] == 'grass':
                    win = one
                elif pokemon[two]["type"] == 'water':
                    win = two
                else:
                    win = 0
            else:
                if pokemon[two]["type"] == 'water':
                    win = one
                elif pokemon[two]["type"] == 'fire':
                    win = two
                else:
                    win = 0
        if win == 0:
            print('平手' + '\n')
        else:
            print('編號' + str(win), pokemon[win]["Name"], '勝利' + '\n')

    elif chose == 3:  # 結束程式
        break
    else:  # 123你也會打錯 防呆
        print("輸入錯誤" + '\n')
