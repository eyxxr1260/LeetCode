class Fancy {
private:
    long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long add;
    long long mul;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) { return power(n, MOD - 2); }

public:
    Fancy() {
        add = 0;
        mul = 1;
    }

    void append(int val) {
        long long current_val = (val - add + MOD) % MOD;
        long long original_x = (current_val * modInverse(mul)) % MOD;
        seq.push_back(original_x);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }

        long long result = (seq[idx] * mul + add) % MOD;
        return result;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */