import sys
import re


def transform(num):
    summ = 0
    t = ""
    for l in list(num):
        t = t+l
        if l == '-':
            continue
        summ = summ + int(t)
        t = ''
    if abs(summ) >= 10:
        summ = is3(str(summ))
    return sum


def is3(num):
    num = int(num)
    if num > 10:
        num = transform(str(num))
    if num in [-9, -6, -3, 0, -0, 3, 6, 9]:
        return True
    else:
        return False


def is5(num):
    num = int(num)
    if str(num)[-1] == '0' or str(num)[-1] == '5':
        return True
    else:
        return False


npt = sys.stdin.readline()
nums = re.findall("[-\d]+", npt)
answ = ''
for num in nums:
    unchange = True
    if is3(num):
        unchange = False
        answ = answ + 'fizz'
    if is5(num):
        unchange = False
        answ = answ + 'buzz'
    if unchange:
        answ = answ + num
    answ = answ + ' '
print answ
