#include <stdio.h>
#include <math.h>

/* TODO maybe can operate bit? */
int mySqrt(int x)
{
    return (int)(sqrt(x));
}


int main()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", mySqrt(x));
    
    return 0;
}
