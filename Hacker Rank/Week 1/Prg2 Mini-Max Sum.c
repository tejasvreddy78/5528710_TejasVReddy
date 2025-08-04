#include <stdio.h>
#include <limits.h>
void miniMaxSum(int* arr){
    long long sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < 5; i++){
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("%lld ", sum - max);
    printf("%lld\n", sum - min);
}
int main(){
    int arr[5];
    for (int i = 0; i< 5; i++){
        scanf("%d", &arr[i]);
    }
    miniMaxSum(arr);
    return 0;
}
