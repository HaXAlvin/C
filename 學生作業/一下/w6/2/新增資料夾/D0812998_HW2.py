cm = float (input('身高(cm):')) #輸入身高 轉成浮點數
kg = float (input('體重(kg):')) #輸入體重 轉成浮點數
m = float(cm/100) #公分轉公尺
bmi = float(kg/m**2) #計算bmi
print('BMI =',bmi) #輸出bmi
if bmi<18.5: #判斷bmi
    print('多吃一點')
elif 18.5<=bmi<=24:
    print('體重正常')
elif 24<=bmi<27:
    print('有一點點過重')
elif bmi<=27:
    print('要多運動')