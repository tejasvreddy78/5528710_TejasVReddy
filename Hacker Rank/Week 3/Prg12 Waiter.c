#include <stdio.h>

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    int A[n];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    int primes[q], count = 0, num = 2;
    while (count < q){
        int prime = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) { prime = 0; break; 
            }
        if (prime) primes[count++] = num;
        num++;
    }

    int res[n], r = 0;
    int *curr = A, currSize = n;

    for (int i = 0; i < q; i++){
        int p = primes[i], next[n], nextSize = 0, B[n], BSize = 0;

        for (int j = currSize - 1; j >= 0; j--){
            if (curr[j] % p == 0) B[BSize++] = curr[j];
            else next[nextSize++] = curr[j];
        }
        for (int j = BSize - 1; j >= 0; j--) res[r++] = B[j];

        for (int j = 0; j < nextSize; j++) curr[j] = next[j];
        currSize = nextSize;
    }
    for (int j = currSize - 1; j >= 0; j--) res[r++] = curr[j];

    for (int i = 0; i < r; i++) printf("%d\n", res[i]);
    return 0;
}
