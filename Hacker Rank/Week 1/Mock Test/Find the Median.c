/*
* Complete the 'findMedian' function below.
*
* The function is expected to return an INTEGER.
* The function accepts INTEGER_ARRAY arr as parameter.
*/
int sortAscending(const void *x, const void *y){
 int a = *(const int *)x;
 int b = *(const int *)y;
 return (a > b) - (a < b);
}
int findMedian(int size, int *arr){
 qsort(arr, size, sizeof(int), sortAscending);
 return arr[size / 2];
}

