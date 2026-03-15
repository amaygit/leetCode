class Fancy {
public:
    const long long MOD = 1e9+7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modpow(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b/=2;
        }
        return res;
    }

    void append(int val) {
        long long inv = modpow(mul,MOD-2);
        long long stored = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx]*mul + add) % MOD;
    }
};