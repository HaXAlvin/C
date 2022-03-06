dict = [{0: 0, 'name': "妙花種子", 'type': "grass", 'CP': 100},
        {1: 1, 'name': "小火龍", 'type': "fire", 'CP': 100},
        {2: 2, 'name': "傑尼龜", 'type': "water", 'CP': 100},
        {3: 3, 'name': "", 'type': "", 'CP': 0}]  # 宣告4個字典,前三個是預設,第四個當作使用者輸入
while True:
    n = int(input("選擇1.新增 2.對戰 3.結束:"))
    if n == 3:
        break
    elif n == 1:  # 新增
        dict[3]['name'] = (input("輸入名字 : "))
        while True:
            dict[3]['type'] = (input("輸入屬性 : "))
            if dict[3]['type'] in ('grass', 'water', 'fire'):  # 判斷有沒有屬性錯誤 錯誤就重新輸入
                break
            else:
                print("輸入錯誤", end='')
        while True:
            dict[3]['CP'] = (int(input("輸入CP值 : ")))
            if 1 <= dict[3]['CP'] <= 999:  # 判斷有沒有介於1~999 錯誤就重新輸入
                break
            else:
                print("輸入錯誤", end='')
        print("新增完畢", end="")
    elif n == 2:  # 對戰模式
        print("編號0"
              "\n" + "名字 : " + dict[0]['name'] +
              "\n" + "屬性 : " + dict[0]['type'] +
              "\n" + "CP值 : " + '%d' % dict[0]['CP'])
        print("編號1"
              "\n" + "名字 : " + dict[1]['name'] +
              "\n" + "屬性 : " + dict[1]['type'] +
              "\n" + "CP值 : " + '%d' % dict[1]['CP'])
        print("編號2"
              "\n" + "名字 : " + dict[2]['name'] +
              "\n" + "屬性 : " + dict[2]['type'] +
              "\n" + "CP值 : " + '%d' % dict[2]['CP'])  # 25~36為輸出基本預設角色
        if dict[3]['CP'] == 0:  # 如果第4個角色的CP值為0時，代表沒被新增過，就不用輸出
            print('', end='')
        else:
            print("編號3"
                  "\n" + "名字 : " + dict[3]['name'] +
                  "\n" + "屬性 : " + dict[3]['type'] +
                  "\n" + "CP值 : " + '%d' % dict[3]['CP'])
        role1 = -1
        while True:
            if role1 == -1:  # 判斷角色1有沒有被輸入過
                role1 = int(input('選擇第一隻(輸入編號) : '))
            if (dict[3]['CP'] == 0 and 0 <= role1 <= 2) or (dict[3]['CP'] != 0 and 0 <= role1 <= 3):  # 輸入成功 進入第二個輸入
                role2 = int(input('選擇第二隻(輸入編號) : '))
                if (dict[3]['CP'] == 0 and 0 <= role2 <= 2 and role1 != role2) or (
                        dict[3]['CP'] != 0 and 0 <= role2 <= 3 and role1 != role2):  # 判斷選擇角色有沒有輸入不符合 或有沒有輸入重複 重複就重新輸入
                    if dict[role1]['CP'] > dict[role2]['CP']:
                        print("編號%d " % role1 + dict[role1]['name'] + " 勝利")
                        break
                    elif dict[role1]['CP'] == dict[role2]['CP']:  # 當CP值相等就判斷屬性
                        if (dict[role1]['type'] == 'fire' and dict[role2]['type'] == 'grass') or (
                                dict[role1]['type'] == 'water' and dict[role2]['type'] == 'fire') or (
                                dict[role1]['type'] == 'grass' and dict[role2]['type'] == 'water'):  # 角色1屬性較強
                            print("編號%d " % role1 + dict[role1]['name'] + " 勝利")
                        elif (dict[role1]['type'] == 'fire' and dict[role2]['type'] == 'fire') or (
                                dict[role1]['type'] == 'water' and dict[role2]['type'] == 'water') or (
                                dict[role1]['type'] == 'grass' and dict[role2]['type'] == 'grass'):  # 角色屬性都相等 所以平手
                            print("平手")
                        else:  # 如果以上判斷都不符合就角色二贏
                            print("編號%d " % role2 + dict[role2]['name'] + " 勝利")
                    else:
                        print("編號%d " % role2 + dict[role2]['name'] + " 勝利")
                    break
                else:
                    print("輸入錯誤")
                    continue
            else:
                print("輸入錯誤")
                role1 = -1
                continue
    else:
        print("輸入錯誤")
