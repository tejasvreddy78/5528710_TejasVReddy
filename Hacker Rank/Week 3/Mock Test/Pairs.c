int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int pairs(int k, int arr_count, int* arr) {
    int count = 0;
    qsort(arr, arr_count, sizeof(int), cmp);

    for (int i = 0; i < arr_count; i++){
        int target = arr[i] + k;
        int left = i+1, right = arr_count - 1;

        while (left <= right){
            int mid = (left + right)/2;
            if (arr[mid] == target){
                count++;
                break;
            } else if (arr[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
