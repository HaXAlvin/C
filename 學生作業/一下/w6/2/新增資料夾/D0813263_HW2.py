a = float(input('身高(cm):'))#轉浮點數
b = float(input('體重(kg):'))#轉浮點數
BMI = (b/((a*0.01)**2))#計算BMI
print('BMI = ',BMI)#印出BMI
if BMI < 18.5:
    print('多吃一點')
elif 18.5 <= BMI < 24:
    print('體重正常')
elif 24 <= BMI < 27:
    print('有一點點過重')
else:
    print('要多運動')