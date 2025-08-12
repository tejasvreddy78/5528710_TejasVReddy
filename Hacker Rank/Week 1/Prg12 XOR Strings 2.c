#include <stdio.h>
#include <string.h>
void strings_xor(char *s, char *t){
    int i;
    int len = strlen(s);
    char res[101];
    for (i = 0; i < len; i++){
        if (s[i] == t[i])
            res[i] = '0';
        else
            res[i] = '1';
    }
    res[len] = '\0';
    printf("%s\n", res);
}
int main() {
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);
    strings_xor(s, t);
    return 0;
}
