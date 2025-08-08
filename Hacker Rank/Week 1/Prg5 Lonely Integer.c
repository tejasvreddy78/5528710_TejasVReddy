#include <stdio.h>
int lonelyinteger(int arr[], int n){
    int result = 0;
    for (int i=0; i<n; i++){
        result ^= arr[i];
    }
    return result;
}
int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    int unique = lonelyinteger(nums, n);
    printf("%d\n", unique);
    return 0;
}

