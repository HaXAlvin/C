a = float(input("身高(cm):"))  # 印出身高(cm): 、 再輸入a的值
b = float(input("體重(kg):"))  # 印出體重(kg): 、 再輸入b的值
a = a / 100  # 使a的值除100
BMI = b / (a ** 2)  # 算出BMI的值
print(BMI)  # 印出BMI
if BMI < 18.5:
    print("多吃一點")  # 如果BMI小於18.5 、 印出多吃一點
elif 18.5 <= BMI < 24:
    print('體重正常')  # 否則如果BMI小於24大於等於18.5 、 印出體重正常
elif 24 <= BMI < 27:
    print('有一點點過重')  # 否則如果BMI小於27大於等於24 、 印出有一點點過重
else:
    print('要多運動')  # 否則印出要多運動
