#include <stdio.h>
#include <string.h>

int anagram(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return -1;
    }

    int count[26] = {0};
    int half = len / 2;

    for (int i = 0; i < half; i++) {
        count[s[i] - 'a']++;
    }
    for (int i = half; i < len; i++) {
        count[s[i] - 'a']--;
    }

    int diff = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            diff += count[i];
        }
    }
    return diff;
}
