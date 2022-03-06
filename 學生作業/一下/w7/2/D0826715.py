pokemonlist = [  # pokemon list
    {'Name': "妙蛙種子", 'Type': "grass", 'CP': 100},
    {'Name': "小火龍", 'Type': "fire", 'CP': 100},
    {'Name': "傑尼龜", 'Type': "water", 'CP': 100}
]
while True:  # loop for all
    choose = input('選擇1.新增 2.對戰 3.結束：')
    if choose == '1':  # add new character
        New = {"Name": input("输入名字:")}
        typ = input("输入属性('fire', 'water', 'grass'):")
        while typ != 'fire' and typ != 'water' and typ != 'grass':
            print('輸入錯誤')
            typ = input("输入属性('fire', 'water', 'grass'):")
        else:
            New["type"] = typ
        number = int(input("输入CP值(1~999):"))
        while number > 999 or number < 1:
            print('輸入錯誤')
            number = int(input("输入CP值(1~999):"))
        else:
            New["CP"] = number
        pokemonlist.append(New)  # add into pokemonlist
        print("新增完畢")
        continue
    if choose == '2':  # choose battle
        for i in range(len(pokemonlist)):  # print out all pokemons
            print('No.%d' % i)
            for i, j in pokemonlist[i].items():
                print(i, ":", j)
        while True:  # input 1st atk pokemon
            first = int(input('選擇第一隻(輸入編號):'))
            if first < 0 or first > len(pokemonlist) - 1:
                print('輸入錯誤')
                continue
            break
        while True:  # input 2nd atk pokemon
            second = int(input('選擇第二隻(輸入編號):'))
            if second == first:
                print('輸入錯誤')
                continue
            if second < 0 or second > len(pokemonlist) - 1:
                print('輸入錯誤')
                continue
            break
        if pokemonlist[first]["CP"] > pokemonlist[second]["CP"]:  # if 1st atk pokemon's cp > 2nd atk pokemon's cp
            print('No.{} {} won\n'.format(first, pokemonlist[first]["Name"]))
        if pokemonlist[first]["CP"] < pokemonlist[second]["CP"]:  # if 2nd atk pokemon's cp > 1st atk pokemon's cp
            print('No.{} {} won\n'.format(second, pokemonlist[second]["Name"]))
        if pokemonlist[first]["CP"] == pokemonlist[second]["CP"]:  # if 2nd atk pokemon's cp = 1st atk pokemon's cp
            if pokemonlist[first]["Type"] == 'grass' and pokemonlist[second]["Type"] == 'fire':
                print('No.{} {} won\n'.format(second, pokemonlist[second]["Name"]))
            elif pokemonlist[first]["Type"] == 'fire' and pokemonlist[second]["Type"] == 'grass':
                print('No.{} {} won\n'.format(first, pokemonlist[first]["Name"]))
            elif pokemonlist[first]["Type"] == 'fire' and pokemonlist[second]["Type"] == 'water':
                print('No.{} {} won\n'.format(second, pokemonlist[second]["Name"]))
            elif pokemonlist[first]["Type"] == 'water' and pokemonlist[second]["Type"] == 'fire':
                print('No.{} {} won\n'.format(first, pokemonlist[first]["Name"]))
            elif pokemonlist[first]["Type"] == 'grass' and pokemonlist[second]["Type"] == 'water':
                print('No.{} {} won\n'.format(first, pokemonlist[first]["Name"]))
            elif pokemonlist[first]["Type"] == 'water' and pokemonlist[second]["Type"] == 'grass':
                print('No.{} {} won\n'.format(second, pokemonlist[second]["Name"]))
    if choose == '3':  # end
        break
    if choose > '3' or choose < '1':  # avoid enter wrong input
        print('輸入錯誤\n')
        continue
