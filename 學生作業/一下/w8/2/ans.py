import json

with open('ans.json', 'r', encoding='utf-8-sig') as f:
    ans = json.load(f, strict=False)

with open('Result.json', 'r', encoding='utf-8-sig') as f:
    res = json.load(f, strict=False)

if ans != res:
    print('error')
else:
    print('yes')
