import json

with open('Dengue_Daily.json', 'r', encoding='utf-8-sig') as infile:
    file = json.load(infile)


def count():
    data = [{}]
    j = 0
    for i in file:
        if data[j].get('發病日') is None:
            data[j].update({'發病日': i['發病日'][0: 7]})
            data[j].update({i['居住縣市']: 1})
        elif i['發病日'][0: 7] == data[j].get('發病日'):
            if data[j].get(i['居住縣市']) is None:
                data[j].update({i['居住縣市']: 1})
            else:
                data[j].update({i['居住縣市']: data[j].get(i['居住縣市']) + 1})
        else:
            data.append({})
            j += 1
            data[j].update({'發病日': i['發病日'][0: 7]})
            data[j].update({i['居住縣市']: 1})
    return data


with open('Result.json', 'w', encoding='utf-8-sig') as outfile:
    json.dump(count(), outfile, ensure_ascii=False)
