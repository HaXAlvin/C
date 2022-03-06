a = input('身高(cm):')#輸入身高
a = float(a)#轉換浮點數型態
b = input('體重(kg):')#輸入體重
b = float(b)#轉換浮點數型態
c = b/(a/100)**2#計算BMI
print('BMI=',c)#印BMI值
if c < 18.5:#小於18.5印
       print('多吃一點')
elif 18.5 <= c < 24:#大於等於18.5小於24印
       print('體重正常')
elif 24 <= c < 27:#大於等於24小於27印
       print('有一點點過重')
else:#大於27印
       print('要多運動')