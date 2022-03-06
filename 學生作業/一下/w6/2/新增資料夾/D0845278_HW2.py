height = float(input('身高:'))  # 輸入身高
weight = float(input('體重:'))  # 輸入體重
height = height / 100  # 單位轉換
BMI = float(weight / (height ** 2))  # 運算BMI
print('BMI = ' + str(BMI))  # 印出BMI
if BMI < 18.5:  # 比較後印出
    print('多吃一點')
elif BMI < 24.0:
    print('體重正常')
elif BMI < 27:
    print('有一點點重')
else:
    print('要多運動')
