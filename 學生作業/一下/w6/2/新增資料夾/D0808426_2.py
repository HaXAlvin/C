def main():
    cm = float(input('身高(cm)：'))  # 提示輸入並轉型為浮點數
    kg = float(input('體重(kg)：'))
    bmi = kg / ((cm / 100) ** 2)  # 套公式
    print(f'BMI = {bmi}')  # 印出BMI
    if bmi < 18.5:
        print('多吃一點')
    elif bmi < 24:
        print('體重正常')
    elif bmi < 27:
        print('有一點點過重')
    else:
        print('要多運動')


if __name__ == '__main__':  # 直接執行腳本就call main
    main()
