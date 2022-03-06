# 先在dict list 放入資料
pokemon1 = {'name': '妙蛙種子', 'type': 'grass', 'cp': 100}
pokemon2 = {'name': '小火龍', 'type': 'fire', 'cp': 100}
pokemon3 = {'name': '傑尼龜', 'type': 'water', 'cp': 100}
pokemonlist = [pokemon1, pokemon2, pokemon3]
# 宣告
choice = int
count = 3
while choice != 3:  # 輸入3跳出迴圈結束程式
    choice = int(input('選擇:1.新增2.對戰3.結束:'))
    if choice == 1:  # 新增
        newpokemon = {'name': input('輸入名字:')}
        # 檢測屬性是否正確
        type_wrong = True
        while type_wrong:
            newpokemon['type'] = input('輸入屬性:')
            if newpokemon['type'] == 'grass' or newpokemon['type'] == 'water' or newpokemon['type'] == 'fire':
                type_wrong = False
            else:
                print('輸入錯誤')
        # 檢測CP值是否正確
        cp_wrong = True
        while cp_wrong:
            newpokemon['cp'] = int(input('輸入CP值:'))
            if 1 <= newpokemon['cp'] <= 999:
                cp_wrong = False
            else:
                print('輸入錯誤')
        print('新增完畢', end='\n\n')
        # 把新的資料丟進去
        pokemonlist.append(newpokemon)
        count += 1
        # 結束
    elif choice == 2:  # 輸出並戰鬥
        # 輸出
        for i in range(count):
            print("編號", i, end='\n')
            print("名字:", pokemonlist[i]['name'], end='\n')
            print("屬性:", pokemonlist[i]['type'], end='\n')
            print("CP值:", pokemonlist[i]['cp'], end='\n')
        # 戰鬥

        while True:  # 判斷第一個是否正確
            first = int(input('輸入第一隻(輸入編號):'))
            if 0 > first or first >= count:
                print('輸入錯誤')
            else:
                break
        while True:  # 判斷第二個是否正確
            last = int(input('輸入第二隻(輸入編號):'))
            if (0 > last or last >= count) or first == last:
                print('輸入錯誤')
            else:
                break
        # 先比CP
        if pokemonlist[first]['cp'] > pokemonlist[last]['cp']:
            print('編號', first, pokemonlist[first]['name'], '勝利', end='\n\n')
        elif pokemonlist[last]['cp'] > pokemonlist[first]['cp']:
            print('編號', last, pokemonlist[last]['name'], '勝利', end='\n\n')
        # 一樣再來處理屬性
        else:
            if pokemonlist[first]['type'] == 'water' and pokemonlist[last]['type'] == 'fire':
                print('編號', first, pokemonlist[first]['name'], '勝利', end='\n\n')
            elif pokemonlist[first]['type'] == 'fire' and pokemonlist[last]['type'] == 'grass':
                print('編號', first, pokemonlist[first]['name'], '勝利', end='\n\n')
            elif pokemonlist[first]['type'] == 'grass' and pokemonlist[last]['type'] == 'water':
                print('編號', first, pokemonlist[first]['name'], '勝利', end='\n\n')
            elif pokemonlist[first]['type'] == 'fire' and pokemonlist[last]['type'] == 'water':
                print('編號', last, pokemonlist[last]['name'], '勝利', end='\n\n')
            elif pokemonlist[first]['type'] == 'water' and pokemonlist[last]['type'] == 'grass':
                print('編號', last, pokemonlist[last]['name'], '勝利', end='\n\n')
            elif pokemonlist[first]['type'] == 'grass' and pokemonlist[last]['type'] == 'fire':
                print('編號', last, pokemonlist[last]['name'], '勝利', end='\n\n')
            else:
                print('平手', end='\n\n')
    elif choice == 3:  # 結束
        break
    else:  # 報錯
        print("輸入錯誤")
