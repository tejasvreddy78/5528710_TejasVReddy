#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    int **seq = malloc(n * sizeof(int*));
    int *sizes = calloc(n, sizeof(int));
    int *capacity = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        seq[i] = malloc(sizeof(int));
        capacity[i] = 1;
    }

    int lastAnswer = 0;
    while (q--){
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1){
            if (sizes[idx] == capacity[idx]){
                capacity[idx] *= 2;
                seq[idx] = realloc(seq[idx], capacity[idx] * sizeof(int));
            }
            seq[idx][sizes[idx]++] = y;
        } else {
            int value = seq[idx][y % sizes[idx]];
            lastAnswer = value;
            printf("%d\n", lastAnswer);
        }
    }
    return 0;
}
