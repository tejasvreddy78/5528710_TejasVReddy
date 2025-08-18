#include<stdio.h>
#include<string.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char str[100010];
        scanf("%s", str);
        int n = strlen(str);

        int i = 0, j = n - 1;
        int flag = 0;

        while(i < j){
            if(str[i] != str[j]){
                int a = i, b = j - 1;
                int ok1 = 1;
                while(a < b){
                    if(str[a] != str[b]) { ok1 = 0; break;
                    }
                    a++; b--;
                }
                if(ok1){
                    printf("%d\n", j);
                } else{
                    printf("%d\n", i);
                }
                flag = 1;
                break;
            }
            i++;
            j--;
        }
        if(flag == 0){
            printf("-1\n");
        }
    }
    return 0;
}
