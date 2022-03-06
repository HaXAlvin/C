class StartGame:  # 開始新遊戲，預設pokemon
    def __init__(self):
        self.list1 = [
            {"name": "妙蛙種子", "type": "grass", "CP": 100, "inv": "fire"},
            {"name": "小火龍", "type": "fire", "CP": 100, "inv": "water"},
            {"name": "傑尼龜", "type": "water", "CP": 100, "inv": "grass"}
        ]


class AddNewPoke:  # 新增寶可夢
    def __init__(self):
        self.a_name = input("輸入名字: ")

        while True:  # 判斷屬性輸入格式
            self.a_type = input("輸入屬性: ")
            if self.a_type == "grass" or self.a_type == "fire" or self.a_type == "water":
                # 判斷相剋屬性
                if self.a_type == "grass":
                    self.a_inv = "fire"
                elif self.a_type == "fire":
                    self.a_inv = "water"
                else:
                    self.a_inv = "grass"
                break
            else:
                print("輸入錯誤")

        while True:  # 判斷CP值輸入格式
            self.a_cp = int(input("輸入CP值: "))
            if 1 <= self.a_cp <= 999:
                break
            else:
                print("輸入錯誤")

        # 新增pokemon加入list1
        newGame.list1.append({"name": self.a_name, "type": self.a_type, "CP": self.a_cp, "inv": self.a_inv})


def Fight():
    printAll()

    while True:
        mon1 = int(input("選擇第一隻(輸入編號):"))
        if 0 <= mon1 <= len(newGame.list1) - 1:  # 編號範圍內
            break
        else:
            print("輸入錯誤")

    while True:
        mon2 = int(input("選擇第二隻(輸入編號):"))
        if 0 <= mon2 <= len(newGame.list1) - 1 and mon2 != mon1:  # 不可重選
            break
        else:
            print("輸入錯誤")

    while True:
        # mon1 CP > mon2 CP
        if newGame.list1[mon1].get("CP") > newGame.list1[mon2].get("CP"):
            printWin(mon1)
            break
        # mon1 CP < mon2 CP
        elif newGame.list1[mon1].get("CP") < newGame.list1[mon2].get("CP"):
            printWin(mon2)
            break
        # mon1 CP = mon2 CP
        else:
            # mon1 type > mon2 type
            if newGame.list1[mon1].get("type") == newGame.list1[mon2].get("inv"):
                printWin(mon1)
                break
            # mon1 type < mon2 type
            elif newGame.list1[mon1].get("inv") == newGame.list1[mon2].get("type"):
                printWin(mon2)
                break
            # mon1 type = mon2 type
            else:
                print("平手")
                print("")
                break


def printWin(mon):
    print("編號{} {} 勝利".format(mon, newGame.list1[mon].get("name")))
    print("")


def printAll():  # 印出所有pokemon資料
    for i in range(len(newGame.list1)):
        print("編號" + str(i))
        print("名字:" + newGame.list1[i].get("name"))
        print("屬性:" + newGame.list1[i].get("type"))
        print("CP值:" + str(newGame.list1[i].get("CP")))


newGame = StartGame()
while True:
    choose = int(input("選擇 1.新增 2.對戰 3.結束 : "))
    if choose == 1:
        AddNewPoke()
    elif choose == 2:
        Fight()
        pass
    elif choose == 3:
        break
    else:
        print("輸入錯誤")
