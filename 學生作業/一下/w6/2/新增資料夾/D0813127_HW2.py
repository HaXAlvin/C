a = float(input('身高(cm)'))
b = float(input('體重(kg)'))
# 輸入
bmi = b / (a / 100) ** 2
# bmi計算
print(bmi)
if bmi < 18.5:
    print('多吃一點')
elif 18.5 <= bmi < 24:
    print('體重正常')
elif 24 <= bmi < 27:
    print('有一點點過重')
elif bmi >= 27:
    print('要多運動')
