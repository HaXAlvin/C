a = float(input('身高(cm):'))#輸入身高
b = float(input('體重(kg):'))#輸入體重
c = b/((a/100) ** 2)#BMI公式
print('BMI =', c)
if c < 18.5:#若BMI小於18.5
    print('多吃一點')
elif 18.5 <= c < 24:#若BMI位在此範圍
    print('體重正常')
elif 24 <= c < 27:#若BMI位在此範圍
    print('有一點點過重')
elif c >= 27:#若BMI大於27
    print('要多運動')