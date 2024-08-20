from fractions import Fraction
Fraction(16, -10) # Fraction(-8, 5)
Fraction(123) # Fraction(123, 1)
Fraction() # Fraction(0, 1)
Fraction('3/7') # Fraction(3, 7)
Fraction(' -3/7 ') # Fraction(-3, 7)
Fraction('1.414213 \t\n') # Fraction(1414213, 1000000)
Fraction('-.125') # Fraction(-1, 8)
Fraction('7e-6') # Fraction(7, 1000000)
Fraction(2.25) # Fraction(9, 4)
Fraction(1.1) # Fraction(2476979795053773, 2251799813685248) (直接傳小數會失真，應改成傳字串)

# method
Fraction(1,2).numerator # 1 (分子)
Fraction(1,2).denominator # 2 (分母)
Fraction(__import__(math).pi).limit_denominator(1000) # Fraction(355, 113) (113 < 1000)
Fraction(__import__(math).pi).limit_denominator(1000000) # Fraction(3126535, 995207) (995207 < 1000000)
