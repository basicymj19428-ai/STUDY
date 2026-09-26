number = input("정수 입력 : ")

last_charater = number[-1]

if last_charater in "02468":
    print("짝수입니다.")

if last_charater in "13579":
    print("홀수입니다.")