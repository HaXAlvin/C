list_pokemon = [{'name': '妙蛙種子', 'type': 'grass', 'cp': 100},
                {'name': '小火龍', 'type': 'fire', 'cp': 100},
                {'name': '傑尼龜', 'type': 'water', 'cp': 100}]  # 存放神奇寶貝資訊
type_strenth = {'water': 3, 'fire': 2, 'grass': 1}  # 屬性相剋關係


def add_pokemon():  # 新增神奇寶貝函式
    Name = input('輸入名字:')
    while 1:
        Type = input('輸入屬性:')
        if Type != 'grass' and Type != 'fire' and Type != 'water':  # 輸入錯誤繼續迴圈
            print('輸入錯誤')
        else:  # 輸入正確跳離迴圈
            break
    while 1:
        cp = int(input('輸入CP值:'))
        if cp > 999 or cp < 1:  # 輸入錯誤繼續迴圈
            print('輸入錯誤')
        else:  # 輸入正確跳離迴圈
            break
    list_pokemon.append({'name': Name, 'type': Type, 'cp': cp})  # 將得到的神奇寶貝資訊以dict放到list後
    print('新增完畢')


def battle():  # 戰鬥函式
    for i in range(len(list_pokemon)):  # 印出當前所有神奇寶貝
        print('編號 {}'.format(i))
        print('名字: {}'.format(list_pokemon[i]['name']))
        print('屬性: {}'.format(list_pokemon[i]['type']))
        print('CP值: {}'.format(list_pokemon[i]['cp']))
    while 1:
        # 輸入第一隻
        first = int(input('選擇第一隻(輸入編號):'))
        if first > len(list_pokemon) - 1 or first < 0:
            print('輸入錯誤')
        else:
            break
    while 1:
        # 輸入第二隻
        second = int(input('選擇第二隻(輸入編號):'))
        if second > len(list_pokemon) - 1 or second < 0 or second == first:
            print('輸入錯誤')
        else:
            break
    # cp大於或小於對手就直接印出勝利者
    if list_pokemon[first]['cp'] > list_pokemon[second]['cp']:
        print('編號{} {} 勝利'.format(first, list_pokemon[first]['name']))
    elif list_pokemon[first]['cp'] < list_pokemon[second]['cp']:
        print('編號{} {} 勝利'.format(second, list_pokemon[second]['name']))
    # cp相等再判斷屬性相剋
    elif list_pokemon[first]['cp'] == list_pokemon[second]['cp']:
        # water與glass例外判斷
        if list_pokemon[first]['type'] == 'grass' and list_pokemon[second]['type'] == 'water':
            print('編號{} {} 勝利'.format(first, list_pokemon[first]['name']))
        elif list_pokemon[first]['type'] == 'water' and list_pokemon[second]['type'] == 'grass':
            print('編號{} {} 勝利'.format(second, list_pokemon[second]['name']))
        # 使用屬性相剋list判斷勝者
        elif type_strenth[list_pokemon[first]['type']] > type_strenth[list_pokemon[second]['type']]:
            print('編號{} {} 勝利'.format(first, list_pokemon[first]['name']))
        elif type_strenth[list_pokemon[first]['type']] < type_strenth[list_pokemon[second]['type']]:
            print('編號{} {} 勝利'.format(second, list_pokemon[second]['name']))
        else:
            print('平手')


def main():
    while 1:
        mode = int(input('選擇1.新增 2.對戰 3.結束:'))
        if mode == 1:
            add_pokemon()
        elif mode == 2:
            battle()
        elif mode == 3:
            return 0
        else:
            print('輸入錯誤')
            continue


main()
