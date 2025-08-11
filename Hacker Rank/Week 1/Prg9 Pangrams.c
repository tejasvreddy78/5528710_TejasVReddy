#include <stdio.h>
int main(){
    char str[1000];
    int seen[26] = {0};
    int uniqueCount = 0;
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++){
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z'){
            int index = ch - 'a';
            if (!seen[index]){
                seen[index] = 1;
                uniqueCount++;
            }
        }
    }
    if (uniqueCount == 26){
        printf("pangram\n");
    }else{
        printf("not pangram\n");
    }

    return 0;
}
