int cmp(const void* a, const void* b){
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
        return len1 - len2;
    return strcmp(s1, s2);
}
char** bigSorting(int unsorted_count, char** unsorted, int* result_count){
    qsort(unsorted, unsorted_count, sizeof(char*), cmp);
    *result_count = unsorted_count;
    return unsorted;
}
