a = input('身高(cm)：')#輸入身高a
b = input('體重(kg)：')#輸入體重b
a=float(a)#把a的型態轉成float
b=float(b)#把b的型態轉成float
c=b / ((a/100)**2)#C為BMI計算值
print('BMI = ',c)
if c < 18.5:#如果C小於18.5
    print('多吃一點')
elif (c>=18.5) and (c<24):#如果C大於等於18.5,且小於24
    print('體重正常')
elif (c>=24) and (c<27):#如果C大於等於24,且小於27
    print('有一點點過重')
elif c>=27:#如果C大於等於27
    print('要多運動')