int cookies(int k, int n, int* A) {
    int heap[1000000], size = 0;

    void push(int x) {
        int i = size++; heap[i] = x;
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            int t = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = t;
            i = (i-1)/2;
        }
    }
    int pop() {
        int v = heap[0]; heap[0] = heap[--size];
        for (int i = 0;;) {
            int s = i, l = 2*i+1, r = 2*i+2;
            if (l < size && heap[l] < heap[s]) s = l;
            if (r < size && heap[r] < heap[s]) s = r;
            if (s == i) break;
            int t = heap[i]; heap[i] = heap[s]; heap[s] = t; i = s;
        }
        return v;
    }

    for (int i = 0; i < n; i++) push(A[i]);

    int ops = 0;
    while (size > 0 && heap[0] < k) {
        if (size < 2) return -1;
        int a = pop(), b = pop();
        push(a + 2*b);
        ops++;
    }
    return ops;
}
