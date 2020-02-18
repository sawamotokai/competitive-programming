
def isLeap(year):
    if (year % 400 == 0):
        return True
    if year % 100 == 0:
        return False
    if year % 4 == 0:
        return True
        
    return False
    

_DAYS = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
_DAYS_LEAP = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


dayOfWeek = 1

def cal():
    janFirst = 1
    sundayCounter = 0

    for i in range(1901, 2001):
        days = []
        if isLeap(i):
            days = _DAYS_LEAP.copy()
        else:
            days = _DAYS.copy()

        firstDay = janFirst        
        for day in days:
            firstDay = (firstDay + day % 7) % 7
            if firstDay == 0:
                sundayCounter += 1
        janFirst = firstDay

    if janFirst == 1:
        sundayCounter -= 1

    return sundayCounter

print(cal())