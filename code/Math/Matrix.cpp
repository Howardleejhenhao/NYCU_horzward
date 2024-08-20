const int MOD = 1e9 + 7;
typedef vector<vector<ll>> matrix;
matrix operator*(matrix A, matrix B)
{
    const int n = A.size(), m = B.size(), o = B[0].size();
    matrix ret(n, vector<ll>(o, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < o; j++) {
            for(int k = 0; k < m; k++) {
                ret[i][j] += A[i][k] * B[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

matrix power(matrix A, int n)
{
    matrix ans(A.size(), vector<ll>(A.size(), 0));
    for(int i = 0; i < A.size(); i++) ans[i][i] = 1;

    while(n) {
        if(n & 1) ans = ans * A;
        A = A * A;
        n >>= 1;
    }
    return ans;
}