h = float(input('身高(cm):'))
h /= 100  # 身高變數換成公尺
w = float(input('體重(kg):'))  # 體重
BMI = w / (h * h)  # 計算bmi
print("BMI=", BMI)  # 印出bmi
if BMI < 18.5:  # 一個一個判斷由最低標準開始
    print("多吃一點")
elif BMI < 24:
    print("體重正常")
elif BMI < 27:
    print("有一點點過重")
else:
    print("要多運動")
