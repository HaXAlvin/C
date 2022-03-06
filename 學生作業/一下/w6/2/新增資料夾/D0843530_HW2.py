hi = float(input('身高(cm):')) #輸入身高 字串轉浮點數
we = float(input('體重(kg):'))  #輸入體重 字串轉浮點數
BMI = we/(hi ** 2)*10000    #算BMI阿 要次方呦 呵呵呵
print('BMI =',BMI)   #印出BMI啦
if BMI < 18.5:     #要多吃一點呦
    print('多吃一點')
elif 18.5 <= BMI < 24:   #體重好正常呀
    print('體重正常')
elif 24 <= BMI <27:    #過重就過重
    print('有一點點過重')
else:     #超級無敵重啦 哈哈哈
    print('要多運動')
