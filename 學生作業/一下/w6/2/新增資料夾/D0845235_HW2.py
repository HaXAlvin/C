height = int(input("身高(cm):"))#宣告身高以及輸入身高
weight = int(input("體重(kg):"))#宣告體重以及輸入體重
BMI = float()#宣告BMI
print("BMI = %f" % (weight/((height/100)*(height/100))))
BMI = weight/((height/100)*(height/100))#計算BMI
if BMI < 18.5:#如果BMI小於18.5則印出多吃一點
    print("多吃一點")
elif 18.5 <= BMI < 24:#如果BMI大於18.8以及小於24則印出體重適中
    print("體重正常")
else:#BMI大於24則印出要多運動
    print("要多運動")
