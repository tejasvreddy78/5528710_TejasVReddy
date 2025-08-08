#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int primarySum = 0, secondarySum = 0;
    int value;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            scanf("%d", &value);
            if (i == j) {
                primarySum += value;
            }
            if (i+j == n - 1){
                secondarySum += value;
            }
        }
    }
    printf("%d\n", abs(primarySum - secondarySum));
    return 0;
}
