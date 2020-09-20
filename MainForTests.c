#include <stdio.h>
#include <math.h>

#include "Tests.h"

int main()
{
    QuadTest();

    printf ("\nThis program displays the number of roots of a quadratic equation and the roots themselves\n");
    printf ("This program was written by Vadim Shakirov, its version is 1.0.2\n");
    printf ("You need to enter the coefficients of the equation a*x*x + b*x + c = 0. You will be prompted to enter them individually as a decimal.\n");

    printf ("\nEnter a: ");

    double a = 0;
    while(scanf("%lf",&a) != 1)
    {
        printf("Please enter the first coefficient of the equation\n");
        fflush(stdin);
    }
    if (IsZero(a)) a = 0;

    printf ("\nEnter b: ");

    double b = 0;
    while(scanf("%lf",&b) != 1)
    {
        printf("Please enter the second coefficient of the equation\n");
        fflush(stdin);
    }
    if (IsZero(b) == 1) b = 0;

    printf ("\nEnter c: ");

    double c = 0;
    while(scanf("%lf",&c) != 1)
    {
        printf("Please enter the third coefficient of the equation\n");
        fflush(stdin);
    }
    if (IsZero(c) == 1) c = 0;

    printf ("\n");

    int nRoots = 0;

    double x  = 0;
    double x1 = 0;
    double x2 = 0;

    if (a!=0)
    {
        nRoots = SolveQuadratic(a,b,c,&x1,&x2,&x);
    }
    if  (a==0)
    {
        nRoots = SolveLinear(b,c,&x);

        printf ("This equation is not quadratic, but linear.\n\n");
    }

    if (IsZero(x) == 1) x = 0;

    if (nRoots == 3) printf ("There are infinite roots here - any number is a solution");
    if (nRoots == 2)
        printf ("\nThere 2 roots. x1 = %lf, x2 = %lf.",x1,x2);
    if (nRoots == 1) printf ("\nThere 1 root. x = %lf.",x);
    if (nRoots == 0) printf ("There no roots");

    printf ("\n\n");
    printf ("The program has completed work");

    return 0;
}
