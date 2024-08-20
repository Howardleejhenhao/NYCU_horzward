void calcH(long long &t, long long &h, const long long p) {
	long long tmp=p-1; 
    for(t = 0; (tmp & 1) == 0; tmp /= 2) t++;
    h = tmp;
}
// solve equation x^2 mod p = a
bool solve(long long a, long long p, long long &x, long long &y) {
	if(p == 2) {
        x = y = 1;
        return true; 
    }
	int p2 = p / 2, tmp = power(a, p2, p);
	if (tmp == p - 1) return false;
	if ((p + 1) % 4 == 0) {
		x = power(a, (p + 1) / 4,p); 
        y = p - x;
        return true;
	} 
    else {
		long long t, h, b, pb; 
        calcH(t, h, p);
		if (t >= 2) {
			do {
                b = rand() % (p - 2) + 2;
			} while (power(b, p / 2, p) != p - 1);
			pb = power(b, h, p);
		} 
        int s = power(a, h / 2, p);
		for (int step = 2; step <= t; step++) {
			int ss = (((long long)(s * s) % p) * a) % p;
			for(int i = 0; i < t - step; i++) ss = qMul(ss, ss, p);
			if(ss + 1 == p) s = (s * pb) % p;
            pb = ((long long)pb * pb) % p;
		} 
        x = ((long long)s * a) % p; 
        y = p - x;
	} 
    return true; 
}