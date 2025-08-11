#include <stdio.h>
int cmpAsc(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int cmpDesc(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}
char* twoArrays(int k, int A[], int B[], int n){
    static char yes[] = "YES";
    static char no[] = "NO";
    qsort(A, n, sizeof(int), cmpAsc);
    qsort(B, n, sizeof(int), cmpDesc);
    
    for (int i = 0; i < n; i++){
        if (A[i] + B[i] < k){
            return no;
        }
    }
    return yes;
}
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int *A = malloc(n * sizeof(int));
        int *B = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);
        printf("%s\n", twoArrays(k, A, B, n));
        free(A);
        free(B);
    }
    return 0;
}
