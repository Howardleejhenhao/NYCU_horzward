int c[n + 1][n + 1];
for(int i = 0; i < n; i++) {
    c[i][i] = 1;
    c[i][0] = 1;
}
for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= i - 1; j++) {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        c[i][i - j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}
/////////////
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int fac[N], fac_inv[N];

void init()
{
    fac[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    fac_inv[N - 1] = power(fac[N - 1], mod - 2, mod);
    for(int i = N - 2; i >= 0; i--) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % mod;
    }
}

int C(int n, int m)
{
    return fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod;
}