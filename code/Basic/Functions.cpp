__builtin_popcount(n) // 表示將n表示成2進位有幾個1
__builtin_popcountll(n) // 表示將n表示成2進位有幾個1

__builtin_ctz(n) // 回傳n的二進位下最低為1後面有幾個0
__builtin_ctzll(n) // 回傳n的二進位下最低為1後面有幾個0
    
int __builtin_clz (unsigned int n) // 回傳n的二進位下最高為1前面有幾個0 (n不可為0)
int __builtin_clzll (unsigned long long n)

cout << fixed << setprecision(2) << 12.375019483 << "\n"; // 12.38
