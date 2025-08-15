#include <stdio.h>
#include <string.h>

char* caesarCipher(char* s, int k){
    int length = strlen(s);
    k = k % 26;
    for(int i = 0; i < length; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            char base = 'a';
            s[i] = ((s[i] - base + k) % 26) + base;
        } else if(s[i] >= 'A' && s[i] <= 'Z'){
            char base = 'A';
            s[i] = ((s[i] - base + k) % 26) + base;
        }
    }
    return s;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    char* s = (char*)malloc((n + 1) * sizeof(char));
    fgets(s, n + 1, stdin);
 
    if(s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }
    int k;
    scanf("%d", &k);
    char* result = caesarCipher(s, k);
    printf("%s\n", result);
    free(s);
    return 0;
}
