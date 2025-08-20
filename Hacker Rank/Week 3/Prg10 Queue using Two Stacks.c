#include <stdio.h>
#define MAX 100000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x){
    stack1[++top1] = x;
}

void transfer(){
    while (top1 >= 0){
        stack2[++top2] = stack1[top1--];
    }
}

int main(){
    int q;
    scanf("%d", &q);

    while (q--){
        int type;
        scanf("%d", &type);

        if (type == 1){
            int x;
            scanf("%d", &x);
            push1(x);
        }
        else if (type == 2){
            if (top2 == -1){
                transfer();
            }
            if (top2 >= 0){
                top2--;
            }
        }
        else if (type == 3){
            if (top2 == -1){
                transfer();
            }
            if (top2 >= 0){
                printf("%d\n", stack2[top2]);
            }
        }
    }
    return 0;
}
