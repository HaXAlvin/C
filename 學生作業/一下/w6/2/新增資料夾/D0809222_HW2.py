#!/usr/bin/env python3

# Get input
height = float(input("身高(cm):"))
weight = float(input("體重(kg):"))
BMI = weight / (height / 100) ** 2
print("BMI = ", BMI)

# Print output
if (BMI < 18.5):
    print("多吃一點")
elif (BMI >= 18.5 and BMI < 24):
    print("體重正常")
elif (BMI >= 24 and BMI < 27):
    print("有一點點過重")
elif (BMI >= 27):
    print("要多運動")