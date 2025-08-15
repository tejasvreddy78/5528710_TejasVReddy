#include <stdio.h>
int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr){
    qsort(arr, arr_count, sizeof(int), compare);
    int minimumUnfairness = __INT_MAX__;
    for(int i = 0; i <= arr_count - k; i++){
        int diff = arr[i + k - 1] - arr[i];
        if(diff < minimumUnfairness) {
            minimumUnfairness = diff;
        }
    }
    return minimumUnfairness;
}

int main(){
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = maxMin(k, n, arr);
    printf("%d\n", result);
    return 0;
}
