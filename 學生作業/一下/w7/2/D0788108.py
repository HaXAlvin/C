# weak 裝克制它的屬性

All_Pokemon = [
    {"name": "妙蛙種子", "type": "grass", "CP": 100, 'weak': 'fire'},
    {"name": "小火龍", "type": "fire", "CP": 100, 'weak': 'water'},
    {"name": "傑尼龜", "type": "water", "CP": 100, 'weak': 'grass'}
]


def print_detail():
    count = 0
    for i in All_Pokemon:
        print(f"編號{count}")
        print(f"名字:{i.get('name')}")
        print(f"屬性:{i.get('type')}")
        print(f"CP值:{i.get('CP')}")
        count += 1


def fight(all_Pokemon):
    first_attack = int(input('選擇輸入第一隻(輸入編號): '))
    while first_attack < 0 or first_attack >= len(All_Pokemon):
        print('輸入錯誤')
        first_attack = int(input('選擇輸入第一隻(輸入編號): '))
    second_attack = int(input('選擇輸入第二隻(輸入編號): '))
    while second_attack < 0 or second_attack >= len(All_Pokemon) or second_attack == first_attack:
        print('輸入錯誤')
        second_attack = int(input('選擇輸入第一隻(輸入編號): '))
    cp_equal = all_Pokemon[first_attack].get('CP') == all_Pokemon[second_attack].get('CP')
    # 先cp值得大小如果一樣在用weak去判斷是不是相剋的
    if all_Pokemon[first_attack].get('CP') > all_Pokemon[second_attack].get('CP') or (
            cp_equal and all_Pokemon[first_attack].get('type') == all_Pokemon[second_attack].get('weak')):
        print(f'編號{first_attack} {all_Pokemon[first_attack].get("name")} 獲勝')
    elif all_Pokemon[first_attack].get('CP') < all_Pokemon[second_attack].get('CP') or (
            cp_equal and all_Pokemon[first_attack].get('weak') == all_Pokemon[second_attack].get('type')):
        print(f'編號{second_attack} {all_Pokemon[second_attack].get("name")} 獲勝')
    else:
        print('平手')


if __name__ == '__main__':
    while True:
        choose = int(input("選擇 1.新增 2.對戰 3.結束 : "))
        if choose == 1:
            name = input("輸入名字: ")
            t = input("輸入屬性: ")
            while t != 'fire' and t != 'water' and t != 'grass':
                print("輸入錯誤")
                t = input("輸入屬性: ")
            if t == 'fire':
                weak = 'water'
            elif t == 'water':
                weak = 'grass'
            else:
                weak = 'fire'
            cp = int(input("輸入CP值:"))
            while cp <= 0 or cp >= 1000:
                print("輸入錯誤")
                cp = int(input("輸入CP值:"))
            All_Pokemon.append({'name': name, 'type': t, 'CP': cp, 'weak': weak})
            print("新增完畢")
        elif choose == 2:
            print_detail()
            fight(All_Pokemon)
        elif choose == 3:
            break
        else:
            print("輸入錯誤")
