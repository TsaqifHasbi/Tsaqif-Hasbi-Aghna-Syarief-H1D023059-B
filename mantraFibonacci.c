#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

typedef Stack* StackPtr;

StackPtr createStack() {
    return NULL;
}
void push(StackPtr* stack, int data) {
    StackPtr newNode = (StackPtr) malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(StackPtr* stack) {
    if (*stack == NULL) {
        printf("Stack kosong!\n");
        return -1;
    }
    int data = (*stack)->data;
    StackPtr temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

void fibonacci(int n) {
    StackPtr stackFibo = createStack();
    int a = 0, b = 1;

    push(&stackFibo, a);

    for (int i = 1; i < n; i++) {
        int next = a + b;
        push(&stackFibo, next);
        a = b;
        b = next;
    }

    printf("Deret Fibonacci hingga bilangan ke-%d:\n", n);
    while (stackFibo != NULL) {
        printf("%d ", pop(&stackFibo));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}