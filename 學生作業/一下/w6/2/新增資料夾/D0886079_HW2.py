# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
h = int(input('身高(cm):'))
w = int(input('體重(kg):'))
bmi = w / ( (h / 100) ** 2 )#BMI算式
print('BMI = ', bmi)
if bmi < 18.5:
    print('多吃一點')
elif 18.5 <= bmi < 24:
    print('體重正常')
elif 24 <= bmi < 27:
    print('有一點點過重')
else:
    print('要多運動')