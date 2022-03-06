
l = float(input('身高(cm):'))#輸入身高
w = float(input('體重(kg):'))#輸入體重
ans =float(w/((l/100)**2))#計算BMI
print('BMI = ',ans)#輸出BMI
#以下為判斷每一個區間
if ans<18.5:
    print('多吃一點')
elif (ans>=18.5 and ans<24):
    print('體重正常')
elif (ans>24 and ans<27):
    print('有一點點過重')
else:
    print('要多運動')

