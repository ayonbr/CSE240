#include <stdio.h>

main(){

char ch;
int a = 10, b = 20;
double f;
//printf("ch = %c\n", ch);

for(int i=0;i<5;i++)
{
    printf("Enter math operation: ");
    scanf(" %c", &ch);
    switch (ch) {
    case '+':
        f = a + b;
        printf("f = %f\n", f);
        break;
    case '-':
        f = a - b;
        printf("f = %f\n", f);
        break;
    case '*':
        f = a * b;
        printf("f = %f\n", f);
        break;
    case '/':
        f = a / b;
        printf("f = %f\n", f);
        break;
    default:
        printf("invalid operator\n");
    }
	fflush(stdin);	
}



    
}
