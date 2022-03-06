a = float(input('身高(cm)：'))     //輸入身高
b = float(input('體重(kg)：'))     //輸入體重
c = b/((a/100) **2)               //計算BMI
print('BMI = ', c)
if c < 18.5:
    print('多吃一點')
elif c >= 18.5 and c < 24:
    print('體重正常')
elif c >= 24 and c < 27:
    print('有一點點過重')
elif c >= 27:
    print('要多運動')

