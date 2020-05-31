/* This program demonstrates the switch statement without using breaks. */ #include <stdio.h>

main() {

    char ch = '+';
    double a = 10.0, b = 20.0;
    double f;
    printf("ch = %c\n", ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %lf\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %lf\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %lf\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %lf\n", f);
        break;
    default:
        printf("invalid operator\n");
    }
    ch = '-';
    printf("ch = %c\n", ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %lf\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %lf\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %lf\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %lf\n", f);
        break;
    default:
        printf("invalid operator\n");
    }

    ch = '*';
    printf("ch = %c\n", ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %lf\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %lf\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %lf\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %lf\n", f);
        break;
    default:
        printf("invalid operator\n");
    }

    ch = '/';
    printf("ch = %c\n", ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %lf\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %lf\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %lf\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %lf\n", f);
        break;
    default:
        printf("invalid operator\n");
    }

    ch = '%';
    printf("ch = %c\n", ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %lf\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %lf\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %lf\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %lf\n", f);
        break;
    default:
        printf("invalid operator\n");
    }

}