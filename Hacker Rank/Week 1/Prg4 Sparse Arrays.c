#include<stdio.h>
#include<string.h>

#define MAX 1000
#define STR_LEN 1001

int main(){
    int n, q;
    scanf("%d", &n);
    
    char strings[MAX][STR_LEN];
    for (int i=0; i<n; i++) {
        scanf("%s", strings[i]);
    }
    
    scanf("%d", &q);
    char queries[MAX][STR_LEN];
    for (int i=0; i<q; i++) {
        scanf("%s", queries[i]);
    }
    
    for (int i=0; i<q; i++) {
        int count=0;
        for (int j=0; j<n; j++) {
            if (strcmp(queries[i], strings[j])==0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
