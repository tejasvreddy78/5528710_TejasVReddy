long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long* diff = calloc(n + 2, sizeof(long));
    long max_val = 0, curr = 0;

    for (int i = 0; i < queries_rows; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        diff[a] += k;
        if (b + 1 <= n) diff[b + 1] -= k;
    }

    for (int i = 1; i <= n; i++) {
        curr += diff[i];
        if (curr > max_val) max_val = curr;
    }

    free(diff);
    return max_val;
}
