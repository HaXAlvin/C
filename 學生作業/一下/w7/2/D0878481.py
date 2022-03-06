i = 0
list1 = ["妙蛙種子", "小火龍", "傑尼龜"]  # 建立名字清單
list2 = ["grass", "fire", "water"]  # 建立屬性清單
list3 = [100, 100, 100]  # 建立血量清單
while 1:
    num = int(input('選擇1.新增 2.對戰 3.結束:'))  # 選擇模式
    if num == 3:  # 結束
        break
    elif num == 1:  # 新增角色
        list1.append(input('輸入名字:'))  # 在名字清單新增
        while 1:  # 防呆
            list2.append(input('輸入屬性:'))  # 在屬性清單新增
            if not (list2[len(list2) - 1] == "water" or list2[len(list2) - 1] == "grass" or list2[len(list2) - 1] == "fire"):  # 不為三屬性其中一種
                list2.pop()  # 先刪除錯誤的
                print('輸入錯誤')
            else:
                break
        while 1:
            list3.append(input('輸入CP值:'))  # 在血量清單新增
            if int(list3[len(list3) - 1]) > 999 or int(list3[len(list3) - 1]) < 1:  # 新增超過999或小於1
                list3.pop()  # 先刪除錯誤
                print('輸入錯誤')
            else:
                print('新增完畢')
                break

    else:
        for i in range(len(list1)):  # 先印出角色資訊
            print('編號%d' % i)
            print('Name:%s' % list1[i])
            print('Type:%s' % list2[i])
            print('CP:%s' % list3[i])

        while 1:
            first = int(input('選擇第一隻(輸入編號):'))  # 選擇角色
            if first > len(list1) - 1:  # 防呆
                print('輸入錯誤')
                continue
            else:
                break
        while 1:
            second = int(input('選擇第二隻(輸入編號):'))  # 選擇角色
            if second > len(list1) - 1 or second == first:  # 不能與第一隻角色一樣
                print('輸入錯誤')
                continue
            else:
                break
        if int(list3[first]) > int(list3[second]):  # 血量大的一方獲勝
            print('編號%d %s 勝利' % (first, list1[first]))

        elif int(list3[first]) < int(list3[second]):  # 血量大的一方獲勝
            print('編號%d %s 勝利' % (second, list1[second]))
        else:  # 比屬性
            if list2[first] == "water":  # 第一為水屬性
                if list2[second] == "fire":
                    print('編號%d %s 勝利' % (first, list1[first]))
                elif list2[second] == "water":
                    print('平手')
                else:
                    print('編號%d %s 勝利' % (second, list1[second]))
            elif list2[first] == "fire":  # 第一為火屬性
                if list2[second] == "grass":
                    print('編號%d %s 勝利' % (first, list1[first]))
                elif list2[second] == "fire":
                    print('平手')
                else:
                    print('編號%d %s 勝利' % (second, list1[second]))

            else:  # 第一為草屬性
                if list2[second] == "water":
                    print('編號%d %s 勝利' % (first, list1[first]))
                elif list2[second] == "grass":
                    print('平手')
                else:
                    print('編號%d %s 勝利' % (second, list1[second]))
