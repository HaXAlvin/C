a = float(input('身高(cm):'))  # 輸入身高
b = float(input('體重(kg):'))  # 輸入體重
print('BMI=%f' % (b / (a / 100) ** 2))  # 算BMI
if (b / (a / 100) ** 2) < 18.5:  # BMI<18.5
    print('多吃一點')
elif 18.5 <= (b / (a / 100) ** 2) < 24:  # 18.5<=BMI<24
    print('體重正常')
elif 24 <= (b / (a / 100) ** 2) < 27:  # 24<=BMI<27
    print('有一點點過重')
else:  # BMI>27
    print('要多運動')
