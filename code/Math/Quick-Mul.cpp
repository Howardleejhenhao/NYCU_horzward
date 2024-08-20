ll qMul(ll a,ll b,ll mod){
    ll ans = 0;
    while(b){
        if(b&1) ans = (ans+a)%mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return ans;
}

// O(1)
ll qMul(ll x,ll y,ll mod){
    ll ret = x * y - (ll)((long double)x / mod * y) * mod;
    return ret<0?ret+mod:ret;
}