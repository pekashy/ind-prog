import sys
import re

def transform3(num):
    digit_summ = 0
    for digit in list(num):
        if digit == '-':
            continue
        digit_summ = digit_summ + int(digit)
    if abs(digit_summ) >= 10:
        digit_summ = check(str(digit_summ), 3)
    return digit_summ


def check(number_str, delimiter):
    if delimiter == 5:
        if number_str[-1] == '0' or number_str[-1] == '5':
            return True
        else:
            return False
    
    if delimiter == 3:
        number = int(number_str)
        if number > 10:
            number = transform3(number_str)
        if number in [-9, -6, -3, 0, -0, 3, 6, 9]:
            return True
        else:
            return False
    
    return False #if we get here we are likely to have unknown delimiter


npt = sys.stdin.readline()
nums = re.findall("[-\d]+", npt)
answ = ''
for num in nums:
    unchange = True
    if check(num, 3):
        unchange = False
        answ = answ + 'fizz'
    if check(num, 5):
        unchange = False
        answ = answ + 'buzz'
    if unchange:
        answ = answ + num
    answ = answ + ' '

print(answ)
