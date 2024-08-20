const int N = 1e4 + 10;
vector<int> prime;
vector<int> vis(N);
vector<int> prime_count(N); // 算最後的次方

void add_integer(int n, int d)
{
    for(int i = 0; i < prime.size(); i++) {
        while(n % prime[i] == 0) {
            n /= prime[i];
            prime_count[i] += d;
        }
        if(n == 1) break;
    }
}

void add_factorial(int n, int d) // n ^ d
{
    for(int i = 1; i <= n; i++) {
        add_integer(i, d);
    }
}

void solve()
{
    for(int i = 2; i <= 10000; i++) {
        if(!vis[i]) prime.push_back(i);
        for(int j = i * 2; j <= 10000; j += i) vis[j] = 1;
    }
    // main code

    // 對於很多數字一起相乘可使用
    // add_factorial->階層

    // 求解
    double ans = 1;
    for(int i = 0; i < prime.size(); i++) ans *= pow(prime[i], prime_count[i]);
    cout << fixed << setprecision(5) << ans << '\n';
    return;
}
