height = float(input("請輸入身高: "))
weight = float(input("請輸入體重: "))
bmi = float(weight / (height / 100) ** 2)
print('BMI = ', bmi)
if bmi < 18.5:
    print("多吃一點")
elif bmi >= 18.5 and bmi < 24:
    print("體重正常")
elif bmi >= 24 and bmi < 27:
    print("有一點點過重")
elif bmi >= 27:
    print("要多運動")
