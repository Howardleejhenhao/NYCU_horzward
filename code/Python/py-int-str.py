import sys
sys.set_int_max_str_digits(1000000)
int('1'*999999) # ok
int('1'*1000000) # error
# int(str) time complexity = O(n^2 / 64)