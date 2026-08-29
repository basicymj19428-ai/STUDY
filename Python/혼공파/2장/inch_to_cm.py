#숫자 입력
raw_input = input("inch 단위의 숫자를 입력해주세요 : ")

#입력받은 데이터 형변환
inch = int(raw_input)

# cm단위로 변경
cm = inch * 2.54

#출력
print(inch, "inch는 cm단위로", cm, "cm 입니다.")