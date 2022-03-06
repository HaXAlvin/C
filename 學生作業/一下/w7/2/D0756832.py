list1 = [{"Name": "妙花種子", "type": "grass", "CP": "100"},
         {"Name": "小火龍", "type": "fire", "CP": "100"},
         {"Name": "傑尼龜", "type": "water", "CP": "100"}]
# print(list1[0].get("Name"))->妙花種子
# 記得有幾個
count_1 = 3
while True:
    choose = int(input("選擇1.新增 2.對戰 3.結束:"))
    if choose == 1:
        name = input("輸入名字:")
        while True:
            attribute = input("輸入屬性:")
            if attribute != "fire" and attribute != "grass" and attribute != "water":
                print("輸入錯誤")
            else:
                break
        while True:
            cp_value = int(input("輸入CP值:"))
            if cp_value > 999 or cp_value < 1:
                print("輸入錯誤")
            else:
                break
        print("新增完畢")
        count_1 += 1
        list1.append({"Name": name, "type": attribute, "CP": cp_value})
        # print(list1)
        # print(count_1)
    elif choose == 2:
        for i in range(count_1):
            # int->str
            b = str(i)
            # int->str
            cp = str(list1[i].get("CP"))
            print("編號" + b)
            print("名字:" + list1[i].get("Name"))
            print("屬性:" + list1[i].get("type"))
            print("CP值:" + cp)
        while True:
            player_one = int(input("選擇第一隻(輸入編號):"))
            # int->str
            temp_1 = str(player_one)
            if player_one >= count_1 or player_one < 0:
                print("輸入錯誤")
            else:
                break
        while True:
            player_two = int(input("選擇第二隻(輸入編號):"))
            # int->str
            temp_2 = str(player_two)
            if player_two >= count_1 or player_two == player_one or player_two < 0:
                print("輸入錯誤")
            else:
                break
        if list1[player_one].get("CP") == list1[player_two].get("CP"):
            if (list1[player_one].get("type") == "grass" and list1[player_two].get("type") == "water") or (
                    list1[player_one].get("type") == "water" and list1[player_two].get("type") == "fire") or (
                    list1[player_one].get("type") == "fire" and list1[player_two].get("type") == "grass"):
                print("編號" + temp_1 + " " + list1[player_one].get("Name") + " 勝利")
            elif (list1[player_two].get("type") == "grass" and list1[player_one].get("type") == "water") or (
                    list1[player_two].get("type") == "fire" and list1[player_one].get("type") == "grass") or (
                    list1[player_two].get("type") == "water" and list1[player_one].get("type") == "fire"):
                print("編號" + temp_2 + " " + list1[player_two].get("Name") + " 勝利")
            else:
                print("平手")

        elif int(list1[player_one].get("CP")) > int(list1[player_two].get("CP")):
            print("編號" + temp_1 + " " + list1[player_one].get("Name") + " 勝利")
        elif int(list1[player_two].get("CP")) > int(list1[player_one].get("CP")):
            print("編號" + temp_2 + " " + list1[player_two].get("Name") + " 勝利")

    elif choose == 3:
        break
    else:
        print("輸入錯誤")
