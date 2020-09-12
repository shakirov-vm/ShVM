#include <stdio.h>
#include <math.h>

const double small = 1e-6;

//-------------------------------------------------------------------------------------------------------------------
int IsZero(double forCompare)
    {
        if (fabs(forCompare) <  small) return 0;
        if (fabs(forCompare) >= small) return 1;
    }
//-------------------------------------------------------------------------------------------------------------------
int SolveLinear(double b, double c, double* x)
{
        printf ("This equation is not quadratic, but linear.\n\n");

        if (b!=0)
        {
            *x = -c/b;

            printf ("There 1 root. x = %lf",*x);

            return 1;
        }
        if (b==0 && c==0)
        {
            printf ("There are infinite roots here - any number is a solution");

            return 2;
        }
        if (b==0 && c!=0)
        {
            printf ("There no roots");

            return 0;
        }
        else return -1;
}
//-------------------------------------------------------------------------------------------------------------------
int SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x)
{

        double discrim = b*b - 4*a*c;


        if (discrim > 0)
        {
            *x1 = (-b - sqrt(discrim))/(2*a);
            *x2 = (-b + sqrt(discrim))/(2*a);

            printf ("\nThere 2 roots. x1 = %lf, x2 = %lf.",*x1,*x2);

            return 2;
        }

        if (discrim == 0)
        {
            *x = -b/2*a;

            printf ("\nThere 1 root. x = %lf.",*x);

            return 1;

        }
        if (discrim < 0)
        {
            printf ("\nThere no real roots.");

            return 0;
        }
        else return -1;
}
//=======================================================================================================================
int main()
{
    printf ("\nThis program displays the number of roots of a quadratic equation and the roots themselves\n");
    printf ("This program was written by Vadim Shakirov, its version is 1.0.0\n");
    printf ("You need to enter the coefficients of the equation a*x*x + b*x + c = 0. You will be prompted to enter them individually as a decimal.\n");

    printf ("\nEnter a: ");

    double a = 0;
    scanf("%lf",&a);

    printf ("\nEnter b: ");

    double b = 0;
    scanf("%lf",&b);

    printf ("\nEnter c: ");

    double c = 0;
    scanf("%lf",&c);

    printf ("\n");

    double x  = 0;
    double x1 = 0;
    double x2 = 0;

    if (a!=0)
    {
        int nRoots = SolveQuadratic(a,b,c,&x1,&x2,&x);
    }
    if  (a==0)
    {
        int nRoots = SolveLinear(b,c,&x);
    }

    printf ("\n\n");
    printf ("The program has completed work");

    return 0;
}


