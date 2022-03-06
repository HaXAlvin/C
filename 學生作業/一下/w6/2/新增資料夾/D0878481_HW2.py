hight=float(input('身高(cm):'))#使用者輸入
weight=float(input('體重(kg):'))#使用者輸入
meter=hight/100
BMI=weight/meter**2
if BMI<18.5:#若BMI小於18.5
    print('BMI=',BMI)
    print('多吃一點')
elif 18.5<=BMI<24:#若BMI大於等於18.5小於24
    print('BMI=',BMI)
    print('體重正常')
elif 24<=BMI<27:#若BMI大於等於24小於27
    print('BMI=',BMI)
    print('有一點點過重')
else:#其餘的BMI值
    print('BMI=',BMI)
    print('要多運動')