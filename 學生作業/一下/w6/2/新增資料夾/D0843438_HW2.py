height=float(input('身高(cm)：'))
weight=float(input('體重(kg)：'))
bmi=float(weight/(height/100)**2)
'''
輸入
'''
print('BMI = {}' .format(bmi))
'''
輸出
'''
if bmi<18.5:
    print('多吃一點')
if bmi>=18.5 and bmi <24:
    print('體重正常')
if bmi>=24 and bmi < 27:
    print('有一點點過重')
if bmi>=27:
    print('要多運動')
'''
輸出建議
'''