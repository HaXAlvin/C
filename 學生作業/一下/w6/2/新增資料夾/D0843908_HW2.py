cm = float(input('身高(cm):'))
kg = float(input('體重(kg):'))
BMI = (kg/((cm/100)**2))
print(BMI)
if(BMI<18.5):
    print("多吃一點")
elif(18.5<=BMI<=24):
    print("體重正常")
elif(24<BMI<27):
    print("有一點點過重")
else:
    print("要多運動")