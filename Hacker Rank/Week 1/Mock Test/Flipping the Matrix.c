/*
* Complete the 'flippingMatrix' function below.
*
* The function is expected to return an INTEGER.
* The function accepts 2D_INTEGER_ARRAY matrix as parameter.
*/
int max4(int a, int b, int c, int d){
 int max = a;
 if (b > max) max = b;
 if (c > max) max = c;
 if (d > max) max = d;
 return max;
}
int flippingMatrix(int matrix_rows, int matrix_columns, int **matrix){
 int n = matrix_rows / 2;
 int sum = 0;
 for (int i = 0; i < n; i++){
 for (int j = 0; j < n; j++){
 int topLeft = matrix[i][j];
 int topRight = matrix[i][matrix_columns - 1 - j];
 int bottomLeft = matrix[matrix_rows - 1 - i][j];
 int bottomRight = matrix[matrix_rows - 1 - i][matrix_columns - 1
- j];
 sum += max4(topLeft, topRight, bottomLeft, bottomRight);
 }
 }
 return sum;
}
