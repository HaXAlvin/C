height = float(input('身高(cm):'))/100#輸入體重
weight = float(input('體重(kg):'))#輸入身高
BMI = weight/height**2#計算BMI
print('BMI =',BMI)#印出BMI
#根據數值大小印出對應字串
if BMI <18.5:
    print('多吃一點')
elif 18.5<=BMI<24:
    print('體重正常')
elif 24<=BMI<27:
    print('有一點點過重')
else:
    print('要多運動')