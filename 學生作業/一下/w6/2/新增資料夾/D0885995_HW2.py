n=float(input('身高(cm):')) #輸入身高
m=float(input('體重(kg):')) #輸入體重
count = m/((n/100)**2)
print('BMI = ',count)
if count<18.5:
    print('多吃一點')
elif 18.5<=count<=24:
    print('體重正常')
elif 24<count<27:
    print('有一點點過重')
elif count>27:
    print('要多運動')
