int power(int a, int b, int m) // (a ^ b) % m
{
    a %= m;
    int ret = 1 % m;
    for(; b; b >>= 1) {
        if(b & 1) ret = ret * a % m;
        a = a * a % m;
    }
    return ret;
}
