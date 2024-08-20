// 一個字串的後綴可以和字串本身匹配到多長從第i項開始一路到n-1
inline vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n, 0);
    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = max(0, r - i + 1);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        }
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}