high = float(input('身高(cm):'))
weight = float(input('體重(kg):'))
print('bmi=', weight / ((high / 100) * (high / 100)))
bmi = weight / ((high / 100) * (high / 100))
if (bmi < 18.5):
    print('多吃一點')
elif 18.5 <= bmi < 24:
    print('體重正常')
elif (24 <= bmi < 27):
    print('有一點點過重')
elif (bmi >= 27):
    print('要多運動')
