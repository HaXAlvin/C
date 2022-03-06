print("身高(cm):")
height = eval(input())
print("體重(kg):")
weight = eval(input())
BMI = weight / ((height/100)*(height/100))
print("BMI = %f" % BMI)
if BMI < 18.5:
    print("多吃一點")
elif 18.5 <= BMI < 24:
    print("體重正常")
elif BMI >= 24 and BMI < 27:
    print("有一點點過重")
else:
    print("要多運動")

