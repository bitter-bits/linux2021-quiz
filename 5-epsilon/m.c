#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int iceil2(unsigned int x)
{
    x = x - 1;
    printf("  %d ", x);
    x = x | (x >> 1);
    printf("  %d ", x);
    x = x | (x >> 2);
    printf("  %d ", x);
    x = x | (x >> 4);
    printf("  %d ", x);
    x = x | (x >> 8);
    printf("  %d ", x);
    x = x | (x >> 16);
    printf("  %d ", x);

    return x + 1;
}

int main(void)
{
    for (int i = 0; i < 18; i++)
    {
        int c = iceil2(i);
        printf("    %d : %d\n", i, c);
    }

    return 0;
}
