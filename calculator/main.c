#include <stdio.h>

int add(int num1, int num2){
    return num1 + num2;
}

int multiply(int num1, int num2){
    return num1 * num2;
}

int subtract(int num1, int num2){
    return num1 - num2;
}

int divide(int num1, int num2, int* rem){
    *rem = num1 % num2;
    return num1 / num2;
}

int main() {

    int num1, num2, rem;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Addition result: %d\n", add(num1, num2));
    printf("Multiplication result: %d\n", multiply(num1, num2));
    printf("Subtraction result: %d\n", subtract(num1, num2));

    int result = divide(num1, num2, &rem);

    printf("Division result: %d\n", result);
    printf("rem: %d\n", rem);

    return 0;
}