const int N = 1e6+5;
const long long A = 27, B = 915660423;
long long pre[N], pw[N];

long long f(int l, int r)
{
    return (pre[r] - pre[l-1]*pw[r-l+1]%B + B) % B;
}

int main()
{
    s = " " + s;
    pw[0] = 1;
    for(int i=1; i<=n; i++)
    {
        pre[i] = (pre[i-1]*A + (s[i]-'a'+1)) % B;
        pw[i] = pw[i-1] * A % B;
    }
}