#!/usr/bin/env python3

# 預設Pokes
pokes = [
    {'name': '妙蛙種子', 'type': 'grass', 'CP': 100},
    {'name': '小火龍', 'type': 'fire', 'CP': 100},
    {'name': '傑尼龜', 'type': 'water', 'CP': 100}
]
types = ['grass', 'fire', 'water']

# 顯示訊息用
_err = lambda: print('輸入錯誤')
_win = lambda poke: print(f"編號{poke} {pokes[poke]['name']} 勝利")


# 新增Poke
def add_data():
    data = {}
    data['name'] = input('輸入名字：')  # 名字
    while True:
        data['type'] = input('輸入屬性 (grass, fire, water)：')  # 屬性
        if data['type'] in types:
            break
        _err()
    while True:
        data['CP'] = int(input('輸入CP值 (1~999)：'))  # CP值
        if 0 < data['CP'] < 1000:
            break
        _err()
    pokes.append(data)  # 將新資料加入pokes
    print('新增完畢')


# 顯示Pokes並戰鬥
def battle():
    # 印出現有Pokes
    for i, poke in enumerate(pokes):  # 用enumerate class同時取得索引與資料
        print(f"編號{i}\n名字：{poke['name']}\n屬性：{poke['type']}\nCP值：{poke['CP']}\n")
    # 選擇上場Pokes
    while True:
        poke1 = int(input('選擇第一隻(輸入編號)：'))
        if 0 <= poke1 < len(pokes):
            break
        _err()
    while True:
        poke2 = int(input('選擇第二隻(輸入編號)：'))
        if 0 <= poke2 < len(pokes) and poke2 != poke1:
            break
        _err()
    # 戰鬥判斷
    if pokes[poke1]['CP'] > pokes[poke2]['CP']:
        _win(poke1)
    elif pokes[poke1]['CP'] < pokes[poke2]['CP']:
        _win(poke2)
    else:  # CP值相等，判斷屬性
        poke1_type = types.index(pokes[poke1]['type'])  # 將屬性轉換為其index以便使用<>判斷
        poke2_type = types.index(pokes[poke2]['type'])
        if poke1_type < poke2_type:
            _win(poke1) if (poke1_type == 0 and poke2_type == 2) else _win(poke2)
        elif poke1_type > poke2_type:
            _win(poke2) if (poke1_type == 2 and poke2_type == 0) else _win(poke1)
        else:  # CP值相等，屬性也相等，平手
            print('平手')


def main():
    while True:
        choice = int(input('選擇動作 (1.新增 2.對戰 3.結束)：'))
        if choice == 1:  # 新增
            add_data()
        elif choice == 2:  # 對戰
            battle()
        elif choice == 3:  # 離開
            return
        else:
            _err()
        print()


if __name__ == '__main__':
    main()
