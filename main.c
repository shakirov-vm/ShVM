#include <stdio.h>
#include <math.h>

int main()
{
    printf ("\nThis program displays the number of roots of a quadratic equation and the roots themselves\n");
    printf ("This program was written by Vadim Shakirov, its version is 1.0.0\n");
    printf ("You need to enter the coefficients of the equation a*x*x + b*x + c = 0. You will be prompted to enter them individually as a decimal.\n");

    printf ("\nEnter a: ");

    double a = 0;
    scanf("%lg",&a);

    printf ("\nEnter b: ");

    double b = 0;
    scanf("%lg",&b);

    printf ("\nEnter c: ");
    printf ("\n");

    double c = 0;
    scanf("%lg",&c);

    if (a != 0)
    {

        double discrim = b*b - 4*a*c;



        if (discrim > 0)
        {
            double x1 = (-b - sqrt(discrim))/(2*a);
            double x2 = (-b + sqrt(discrim))/(2*a);

            printf ("\nThere 2 roots. x1 = %lg, x2 = %lg.",x1,x2);
        }

        if (discrim == 0)
        {
            double x = -b/2*a;

            printf ("\nThere 1 root. x = %lg.",x);

        }
        if (discrim < 0)
        {
            printf ("\nThere no real roots.");
        }
    }
    if (a == 0)
    {
        printf ("This equation is not quadratic, but linear.\n\n");

        if (b!=0 && c!=0)
        {
            double x = -c/b;

            printf ("There 1 root. x = %lg",x);
        }
        if (b==0 && c==0)
            printf ("There are infinite roots here - any number is a solution");
        if (b==0 && c!=0)
            printf ("There no roots");
    }

    printf ("\n\n");
    printf ("The program has completed work");

    return 0;
}
