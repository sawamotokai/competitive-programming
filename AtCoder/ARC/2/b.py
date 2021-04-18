y, m, d = map(int, input().split("/"))


def isDivisible(y, m, d):
    if y % m == 0 and (y / m) % d == 0:
        return True


import datetime

today = datetime.datetime(y, m, d)
while not isDivisible(today.year, today.month, today.day):
    today = today + datetime.timedelta(days=1)

print(today.strftime("%Y/%m/%d"))
