dic = {'名字': '妙蛙種子', '屬性': 'grass', 'CP': 100}
dic1 = {'名字': '小火龍', '屬性': 'fire', 'CP': 100}
dic2 = {'名字': '傑尼龜', '屬性': 'water', 'CP': 100}
# 運用dict去存取一隻的名字、屬性、CP
list3 = [dic, dic1, dic2]
# 運用list3去存取所有的數值
while True:
    count = int(input("選擇(1.新增/2.對戰/3.結束):"))
    # 印出選擇(1.新增/2.對戰/3.結束):且讓使用者輸入
    if count == 1:
        dictem = {}
        list3.append(dictem)
        dictem['名字'] = input('名字:')
        while True:
            btem = input('屬性(fire/water/grass):')
            btem = btem.lower()
            if (btem != 'fire') and (btem != 'grass') and (btem != 'water'):
                print('輸入錯誤 請重新輸入')
            else:
                break
        dictem['屬性'] = btem
        while True:
            c = int(input('CP(1~999):'))
            if (c < 1) or (c > 999):
                print('輸入錯誤 請重新輸入')
            else:
                break
        dictem['CP'] = c
    # 如果count等於1，則跑以上的事
    # 宣告一個dictem為空的
    # 在list3的最後增加一個dictem
    # dictem內為使用者新增的數值
    # 宣告a，且印出名字:，使新增的名字存到dictem內
    # 宣告b，印出屬性(fire/water/grass):
    # 如果b不為fire和grass和water，則印出輸入錯誤 請重新輸入，讓使用者重新輸入b的值，直到b的值符合條件，最後將使新增的屬性存到dictem內
    # 宣告c，印出CP(1~999):
    # 如果c的值不在1~999之內，則印出輸入錯誤 請重新輸入，讓使用者重新輸入c的值，直到c的值符合條件，最後將使新增的CP存到dictem內
    elif count == 2:
        for index, pokemon in enumerate(list3):
            print('編號', index)
            for key, value in pokemon.items():
                print(key, value, sep=':')
        while True:
            fightone = int(input('輸入第一隻(輸入編號):'))
            if (fightone < 0) or (fightone > (len(list3) - 1)):
                print('輸入錯誤 請重新輸入')
            else:
                break
        while True:
            fighttwo = int(input('輸入第二隻(輸入編號):'))
            if (fighttwo < 0) or (fighttwo > (len(list3) - 1)):
                print('輸入錯誤 請重新輸入')
            elif fighttwo == fightone:
                print('輸入重複 請重新輸入')
            else:
                break
        listtem1 = list(list3[fightone].values())
        listtem2 = list(list3[fighttwo].values())
        if (listtem1[2]) > (listtem2[2]):
            print('編號', format(fightone), listtem1[0], 'won!!')
        elif (listtem1[2]) < (listtem2[2]):
            print('編號', format(fighttwo), listtem2[0], 'won!!')
        else:
            typetem1 = listtem1[1].lower()
            typetem2 = listtem2[1].lower()
            if (((typetem1 == 'water') and (typetem2 == 'fire')) or (
                    (typetem1 == 'fire') and (typetem2 == 'grass')) or (
                    (typetem1 == 'grass') and (typetem2 == 'water'))):
                print('編號', format(fightone), listtem1[0], 'won!!')
            elif (((typetem1 == 'fire') and (typetem2 == 'water')) or (
                    (typetem1 == 'grass') and (typetem2 == 'fire')) or (
                          (typetem1 == 'water') and (typetem2 == 'grass'))):
                print('編號', format(fighttwo), listtem2[0], 'won!!')
            else:
                print('平局')
    # 如果count等於2，則跑以上的事
    # 運用兩個for迴圈去印出每一隻的數值
    # 接著就要進入選角的地方
    # 運用while迴圈去跑
    # 宣告fightone，且印出輸入第一隻(輸入編號):，fightone的值小於0或是超過現有的數量，則印出輸入錯誤 請重新輸入，直到符合條件
    # 宣告fighttwo，且印出輸入第二隻(輸入編號):，fighttwo的值小於0或是超過現有的數量或是和fightone的值相同，則印出輸入錯誤 請重新輸入，直到符合條件
    # 宣告listtem1和listtem2去存取第一隻和第二隻的資料
    # 如果第一隻的CP(listtem1內的第2個物件)大於第二隻(listtem2內的第2個物件)，則第一隻贏；反之第二隻的CP大於第一隻，則第一隻贏；如果CP相同，則去比較屬性(listtem1和listtem2內的第1個物件)
    elif count == 3:
        print('game end~~')
        break
    # 如果count等於3，則跑以上的事
    # 印出game end~~，且結束while的迴圈
    else:
        print("輸入錯誤")
    # 否則 印出輸入錯誤
