#include <stdio.h>
#include <stdlib.h>
#define max 100000

int stack[max], top = -1;
void push(int stack[], int val){
    if (top == max - 1){
        printf("Stack Overflow \n");
    }
    else{
        top++;
        stack[top] = val;
    }
}
void pop(int stack[]){
    if (top == -1){
        printf("Stack Underflow \n");
    }else
    {
        int val = stack[top];
        top--;
    }
}
int maxm(int stack[], int size){
    int mx;
    mx = stack[0];
    for (int i = 1; i < size; i++){
        if (stack[i] > mx)
            mx = stack[i];
    }
    return mx;
}
void getMax(int stack[]){
    int n;
    int n1, n2;
    int val;
    scanf("%d", &n);
    int arr[max];
    for (int i = 1; i <= n; i++){
        scanf("%d", &n1);
        if (n1 == 1){
            scanf("%d", &n2);
            push(stack, n2);
        }
        else if (n1 == 2){
            pop(stack);
        }
        else if (n1 == 3){
            val = maxm(stack, top + 1);
            printf("%d\n", val);
        }
    }
}
int main(){
    getMax(stack);
    return 0;
}
