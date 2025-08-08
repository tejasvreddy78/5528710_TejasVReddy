#include <stdio.h>
unsigned int flippingBits(unsigned int n) {
    return n ^ 0xFFFFFFFFU;
}
int main(){
    int queries;
    scanf("%d", &queries);
    while (queries--){
        unsigned int num;
        scanf("%u", &num);
        printf("%u\n", flippingBits(num));
    }
    return 0;
}
