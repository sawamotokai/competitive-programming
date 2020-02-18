# 1000000
import itertools
# 01 + something

# 0123456789 -> 1stnum

# insert the last to before 2nd from the last
# 0123456798 -> 2nd

# replace 3rd from the last with 2nd from the last
# 0123456879 -> 3rd
# insert last before 2nd from the last
# 0123456897 -> 4th
# replace 3rd from the last with 1st from the last
# and insert last to 2nd from the last
# 0123456978 -> 3rd
# 0123456987 -> 4th

# 0123457689
# 0123457698
# 0123457869
# 0123457896
# 0123457968
# 0123457986


num = "0123456789"

p = itertools.permutations(range(10))

print(list(p)[999999])
