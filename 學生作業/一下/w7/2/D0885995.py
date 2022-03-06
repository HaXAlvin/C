count = 3  # 計算有幾個角色
total = [{"name": "妙蛙種子", "type": "grass", "CP": 100},
         {"name": "小火龍", "type": "fire", "CP": 100},
         {"name": "傑尼龜", "type": "water", "CP": 100}]  # 預設角色數
while 1:
    flag2 = 0  # 判斷新增時是否要再次輸入姓名
    flag3 = 0  # 判斷戰鬥時是否要輸入編號2
    flag4 = 0  # 判斷戰鬥時是否再輸入編號1
    flag5 = 0  # 判斷戰鬥時是否要印出數值
    flag6 = 0  # 判斷戰鬥時是否編號輸入成功
    n = int(input("選擇1.新增 2.對戰 3.結束:"))
    if n == 1:  # 新增
        indict = {}
        while 1:
            flag = 0  # 判斷是否輸入成功
            if flag2 == 0:  # 判斷是否要輸入名字
                indict["name"] = input("輸入名字:")
            indict["type"] = input("輸入屬性:")
            if indict["type"] in "grass" or indict["type"] in "water" or indict["type"] in "fire":  # 判斷屬性是否正確
                flag = 0
            else:
                flag += 1
                flag2 += 1
            if flag != 0:  # 輸入錯誤
                print("輸入錯誤")
            elif flag == 0:  # 輸入正確
                indict["CP"] = int(input("輸入CP值:"))
                total.append(indict)
                print("新增完畢")
                count += 1
                break

    elif n == 2:  # 戰鬥
        while 1:
            if flag5 == 0:  # 判斷是否要列印數值
                for i in range(0, count):
                    print("編號", end='')
                    print(i)
                    print("名字", end=':')
                    print(total[i]["name"])
                    print("屬性", end=':')
                    print(total[i]["type"])
                    print("CP值", end=':')
                    print(total[i]["CP"])
            flag5 = 1
            if flag4 == 0:  # 判斷是否可以輸入編號1
                num1 = int(input("選擇第一隻(輸入編號):"))
                num2 = 0
            if num1 >= count:  # 判斷是否編號1是否輸入錯誤
                print("輸入錯誤")
                flag3 += 1
            elif num1 < count:
                flag3 = 0
            if flag3 == 0:  # 判斷是否可以輸入編號2
                num2 = int(input("選擇第二隻(輸入編號):"))
                flag4 = 1
            if num1 == num2 or num2 >= count:  # 判斷是否編號1是否輸入錯誤
                print("輸入錯誤")
            elif num2 < count and flag4 == 1:
                flag6 = 1
                flag3 = 1
                break
        if flag6 == 1:  # 判斷是否可以進入CP判斷
            if total[num1]["CP"] > total[num2]["CP"]:  # num1>num2
                print("編號", end='')
                print(num1, end=' ')
                print(total[num1]["name"], end=' ')
                print("勝利")
                print()
            elif total[num1]["CP"] < total[num2]["CP"]:  # num1<num2
                print("編號", end='')
                print(num2, end=' ')
                print(total[num2]["name"], end=' ')
                print("勝利")
                print()
            elif total[num1]["CP"] == total[num2]["CP"]:  # num1==num2
                if (total[num1]["type"] in "grass" and total[num2]["type"] in "water") or (
                        total[num1]["type"] in "water" and total[num2]["type"] in "fire") or (
                        total[num1]["type"] in "fire" and total[num2]["type"] in "grass"):  # 判斷屬性
                    print("編號", end='')
                    print(num1, end=' ')
                    print(total[num1]["name"], end=' ')
                    print("勝利")
                    print()
                elif (total[num2]["type"] in "grass" and total[num1]["type"] in "water") or (
                        total[num2]["type"] in "water" and total[num1]["type"] in "fire") or (
                        total[num2]["type"] in "fire" and total[num1]["type"] in "grass"):  # 判斷屬性
                    print("編號", end='')
                    print(num2, end=' ')
                    print(total[num2]["name"], end=' ')
                    print("勝利")
                    print()
                else:
                    print("平手")
                    print()
    elif n == 3:  # 結束
        break
    else:
        print("輸入錯誤")
