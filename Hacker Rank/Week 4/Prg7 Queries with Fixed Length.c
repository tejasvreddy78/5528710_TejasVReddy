int* solve(int n, int* arr, int q, int* queries, int* result_count) {
    *result_count = q;
    int* results = malloc(q * sizeof(int));

    for (int idx = 0; idx < q; idx++) {
        int d = queries[idx];
        int* deque = malloc(n * sizeof(int));
        int front = 0, back = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (front <= back && deque[front] <= i - d)
                front++;
            while (front <= back && arr[deque[back]] <= arr[i])
                back--;

            deque[++back] = i;

            if (i >= d - 1) {
                int max_in_window = arr[deque[front]];
                if (max_in_window < best)
                    best = max_in_window;
            }
        }
        results[idx] = best;
        free(deque);
    }
    return results;
}
