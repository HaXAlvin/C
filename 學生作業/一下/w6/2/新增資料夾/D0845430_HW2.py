height = float(input('Height:'))  # input height and turn string to float
weight = float(input('Weight:'))  # inout weight and turn string to float
bmi = weight/(height/100)**2  # calculate BMI
print('BMI=', bmi)  # print BMI
if bmi < 18.5:  # if BMI < 18.5
    print('Eat more.')  # print "Eat more."
elif 18.5 <= bmi < 24:  # if 18.5 <= bmi < 24
    print('Normal.')  # print "Normal."
elif 24 <= bmi < 27:  # if 24 <= bmi < 27
    print('A little bit overweight.')  # print "A little bit overweight."
else:  # bmi >= 27
    print('Exercise more.')  # print "Exercise more."
