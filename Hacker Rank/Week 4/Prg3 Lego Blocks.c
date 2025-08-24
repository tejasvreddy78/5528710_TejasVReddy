long long modpow(long long a, int b){
    long long res = 1;
    while (b){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int legoBlocks(int n, int m) {
    long long row[1001] = {1}, total[1001] = {0}, solid[1001] = {0};
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= 4; k++)
            if (i - k >= 0) row[i] = (row[i] + row[i-k]) % MOD;

    for (int i = 1; i <= m; i++){
        total[i] = modpow(row[i], n);
        solid[i] = total[i];
        for (int j = 1; j < i; j++)
            solid[i] = (solid[i] - solid[j] * total[i-j]) % MOD;
        if (solid[i] < 0) solid[i] += MOD;
    }
    return (int)solid[m];
}
