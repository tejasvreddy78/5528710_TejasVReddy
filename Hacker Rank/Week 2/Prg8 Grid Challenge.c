#include <stdio.h>
#include <string.h>
int cmpchar(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
}

char* gridChallenge(int grid_count, char** grid){
    for(int i = 0; i < grid_count; i++){
        int len = strlen(grid[i]);
        qsort(grid[i], len, sizeof(char), cmpchar);
    }
    for(int col = 0; col < strlen(grid[0]); col++){
        for(int row = 1; row < grid_count; row++){
            if(grid[row][col] < grid[row-1][col]){
                return "NO";
            }
        }
    }
    return "YES";
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char **grid = (char**)malloc(n * sizeof(char*));
        for(int i = 0; i < n; i++){
            char temp[100];
            scanf("%s", temp);
            grid[i] = strdup(temp);
        }
        char* ans = gridChallenge(n, grid);
        printf("%s\n", ans);
        // free memory
        for(int i = 0; i < n; i++){
            free(grid[i]);
        }
        free(grid);
    }
    return 0;
}
