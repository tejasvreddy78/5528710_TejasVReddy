char* highestValuePalindrome(char* s, int n, int k) {
    char* res = malloc((n + 1) * sizeof(char));
    strcpy(res, s);

    int* changed = calloc(n, sizeof(int));

    int l = 0, r = n - 1;
    while (l < r) {
        if (res[l] != res[r]) {
            if (res[l] > res[r]) res[r] = res[l];
            else res[l] = res[r];
            changed[l] = changed[r] = 1;
            k--;
        }
        l++; r--;
    }

    if (k < 0) {
        free(res);
        return "-1";
    }
    l = 0; r = n - 1;
    while (l < r) {
        if (res[l] != '9') {
            if (changed[l] || changed[r]) {
                if (k >= 1) {
                    res[l] = res[r] = '9';
                    k--;
                }
            } else {
                if (k >= 2) {
                    res[l] = res[r] = '9';
                    k -= 2;
                }
            }
        }
        l++; r--;
    }

    if (n % 2 == 1 && k > 0) {
        res[n/2] = '9';
    }

    res[n] = '\0';
    free(changed);
    return res;
}
