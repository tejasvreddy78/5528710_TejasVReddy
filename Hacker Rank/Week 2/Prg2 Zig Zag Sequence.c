#include <stdio.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void findZigZagSequence(int arr[], int n){
    qsort(arr, n, sizeof(int), compare);

    int mid = (n - 1) / 2;
    swap(&arr[mid], &arr[n-1]);

    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed) {
        swap(&arr[st], &arr[ed]);
        st++;
        ed--;
    }
    for(int i = 0; i < n; i++){
        if(i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        findZigZagSequence(arr, n);
    }
    return 0;
}
