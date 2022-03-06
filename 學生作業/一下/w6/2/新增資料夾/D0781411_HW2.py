# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

cm=float(input('請輸入身高(cm)'))
kg=float(input('請輸入體重(kg)'))
m=cm/100
BMI=kg/(m**2)
print(BMI)
if(BMI<18.5):
    print('多吃一點')
if(BMI>=18.5 and BMI<24):
    print('體重正常')
if(BMI>=24 and BMI<27):
    print('有一點點過重')
if(BMI>=27):
    print('要多運動')