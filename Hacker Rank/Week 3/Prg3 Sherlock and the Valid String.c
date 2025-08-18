#include <stdio.h>
#include <string.h>

char* isValid(char *s){
    int freq[26] = {0};

    for (int i = 0; s[i]; i++){
        freq[s[i] - 'a']++;
    }

    int max_freq = 0;
    for(int i=0; i<26; i++){
        if(freq[i] > max_freq){
            max_freq = freq[i];
        }
    }

    int countFreq[100005] = {0};
    for(int i=0; i<26; i++){
        if(freq[i] > 0){
            countFreq[freq[i]]++;
        }
    }

    int distinct = 0;
    int f1 = 0, f2 = 0;
    for(int i = 1; i <= max_freq; i++){
        if(countFreq[i] > 0){
            distinct++;
            if(f1 == 0) f1 = i;
            else if(f2 == 0) f2 = i;
        }
    }

    if(distinct == 1){

        return "YES";
    }

    if(distinct > 2){
        return "NO";
    }

    if(f1 > f2){
        int t = f1; f1 = f2; f2 = t;
    }

    if(f1 == 1 && countFreq[f1] == 1){
        return "YES";
    }
    if(f2 == f1 + 1 && countFreq[f2] == 1){
        return "YES";
    }

    return "NO";
}

int main(){
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}