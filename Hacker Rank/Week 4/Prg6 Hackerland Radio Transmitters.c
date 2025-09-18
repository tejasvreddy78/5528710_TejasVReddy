int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int n, int* x, int k) {
    qsort(x, n, sizeof(int), cmp);

    int num = 0, i = 0;
    while (i < n) {
        num++;
        int loc = x[i] + k;
        while (i < n && x[i] <= loc) i++;

        int pos = x[i-1] + k;
        while (i < n && x[i] <= pos) i++;
    }
    return num;
}
