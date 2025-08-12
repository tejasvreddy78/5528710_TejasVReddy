#include <stdio.h>
int countWays(int arr[], int n, int day, int month){
    int ways = 0;
    int windowSum = 0;
    int i;
    for (i = 0; i < month; i++){
        windowSum += arr[i];
    }
    if (windowSum == day){
        ways++;
    }
    for (i = month; i < n; i++){
        windowSum += arr[i];
        windowSum -= arr[i - month];
        if (windowSum == day) {
            ways++;
        }
    }
    return ways;
}
int main() {
    int n, i, day, month;
    scanf("%d", &n);
    int arr[1000];
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &day, &month);
    int result = countWays(arr, n, day, month);
    printf("%d\n", result);
    return 0;
}

