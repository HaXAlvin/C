cm = float(input('����(cm):'))
kg = float(input('�魫(kg):'))
BMI = (kg/((cm/100)**2))
print(BMI)
if(BMI<18.5):
    print("�h�Y�@�I")
elif(18.5<=BMI<=24):
    print("�魫���`")
elif(24<BMI<27):
    print("���@�I�I�L��")
else:
    print("�n�h�B��")