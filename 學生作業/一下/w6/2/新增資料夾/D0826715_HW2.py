height = float(input('height(cm) : '))#input height
weight = float(input('weight(kg) : '))#input weight
bmi = weight/((height/100)**2)#bmi caculate
print('BMI = ',bmi)
if(bmi<18.5):#low bmi
    print('多吃一點')
elif(18.5<=bmi<24):#normal bmi
    print('體重正常')
elif(24<=bmi<27):#slightly overweight bmi
    print('有一點點過重')
elif(bmi>=27):#overweight bmi
    print('要多運動')

