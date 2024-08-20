long long dp[1<<20][20];
vector<int> a[25];
int main()
{ 
    dp[1][0] = 1;
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!dp[i][j])
                continue;
            for(int k: a[j])
            {
                if((i>>k) & 1)
                    continue;
                dp[i | (1<<k)][k] += dp[i][j];
                dp[i | (1<<k)][k] %= mod;
            }
        }
    }
}