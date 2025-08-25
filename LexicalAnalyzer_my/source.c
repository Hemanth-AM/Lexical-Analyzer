#include<stdio.h>

int fun()
{
    int x = -42;
    float y = 3.1415;
    char ch = 'A';
    char str[] = "Test String";
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d %.2f %c %s\n", x, y, ch, str);
}