#include <stdio.h>

int main()
{
    int x = 3;
    printf("&x = %p, &x + 1 = %p", &x, &x + 1);
    printf("%d", sizeof(x));
    return 0;
}