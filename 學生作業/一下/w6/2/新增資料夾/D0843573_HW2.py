a=float(input('身高(cm):')) #輸入身高
b=float(input('體重(kg):')) #輸入體重
BMI=b/((a/100) ** 2) #換算公分成公尺，求出BMI值
print('BMI=',BMI) #印出BMI
if BMI<18.5: #求BMI範圍
    print("多吃一點")
elif BMI>=18.5 and BMI<24: #求BMI範圍
    print("體重正常")
elif BMI>=24 and BMI<27: #求BMI範圍
    print("有一點點過重")
elif BMI>=27: #求BMI範圍
    print("要多運動")