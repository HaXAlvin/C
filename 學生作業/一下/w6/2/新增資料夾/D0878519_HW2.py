cm=float(input('身高(cm):'))#輸入身高
m=cm/100#公分轉公尺
kg=float(input('體重(kg):'))#輸入體重
bmi=kg/(m**2)#BMI公式
print('BMI = %s'%(bmi))#印出BMI
#判斷BMI 給出結果
if bmi<18.5:
    print('多吃一點')
elif bmi>=18.5 and bmi<24:
    print('體重正常')
elif bmi>=24 and bmi<27:
    print('有一點點過重')
elif bmi>=27:
    print('要多運動')

