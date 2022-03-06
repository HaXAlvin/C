import json

with open('Dengue_Daily_10.json', 'r', encoding='utf-8-sig') as outfile:
    lines = json.load(outfile)
i = int(0)
j = int()


def date(i):
    if i in range(len(lines)):
        return lines[i]['發病日'][0:7]
    return 'error'


def city(i):
    if i in range(len(lines)):
        return lines[i]['居住縣市']
    return 'error'


for i in range(len(lines)):
    list1 = [date(i), city(i)]
    print(list1[0])
    print(list1[1])
