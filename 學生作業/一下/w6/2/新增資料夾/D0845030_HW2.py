a = float(input('身高(cm):'))#輸入身高
b = float(input('體重(kg):'))#輸入體重
a = a/100#身高先除100
bmi = b/a ** 2#BMI計算
print('BMI = ',bmi)#印出BMI
if bmi < 18.5:#過輕的狀況
    print("多吃一點")
elif 18.5 <= bmi < 25:#正常的狀況
    print("體重正常")
elif 24 <= bmi < 27:#過重的狀況
    print("有一點點過重")
elif bmi >= 27:#超重的狀況
    print("要多運動")