#include <stdio.h>
#include <math.h>

const double small = 1e-6;

//-------------------------------------------------------------------------------------------------------------------
int IsZero(double forCompare)
    {
        if (fabs(forCompare) <  small) return 1;
        if (fabs(forCompare) >= small) return 0;
    }
//-------------------------------------------------------------------------------------------------------------------
int SolveLinear(double b, double c, double* x)
{
        if (b!=0)
        {
            *x = -c/b;

            return 1;
        }
        if (IsZero(b) == 1 && IsZero(c) == 1)
        {
            return 3;
        }
        if (IsZero(b) == 1 && c!=0)
        {
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

            return 2;
        }

        if (IsZero(discrim) == 1)
        {
            *x = -b/2*a;

            return 1;

        }
        if (discrim < 0)
        {
            return 0;
        }
        else return -1;
}//=======================================================================================================================
int main()
{
    QuadTest();

    printf ("\nThis program displays the number of roots of a quadratic equation and the roots themselves\n");
    printf ("This program was written by Vadim Shakirov, its version is 1.0.2\n");
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

    if (nRoots == 3) printf ("There are infinite roots here - any number is a solution");
    if (nRoots == 2)
        printf ("\nThere 2 roots. x1 = %lf, x2 = %lf.",x1,x2);
    if (nRoots == 1) printf ("\nThere 1 root. x = %lf.",x);
    if (nRoots == 0) printf ("There no roots");

    printf ("\n\n");
    printf ("The program has completed work");

    return 0;
}
void QuadTest()
{
    double x1 = 0;
    double x2 = 0;
    double x  = 0;
    int n = 0;


    n = SolveQuadratic(1,-3,2,&x1,&x2,0);
    if (n==2 && x1==1 && x2==2) printf ("Test 1 ok\n");
    else printf ("Test 1 BAD: n=2; x1=1; x2=2 expected, but n=%d, x1=%lf, x2 = %lf.\n", n, x1, x2);


    n = SolveQuadratic(1,2,1,0,0,&x);
    if (n==1 && x==-1) printf ("Test 2 ok\n");
    else printf ("Test 2 BAD: n=1; x=0 expected, but n=%d, x=%lf.\n", n, x);


    n = SolveQuadratic(1,2,3,0,0,0);
    if (n==0) printf ("Test 3 ok\n");
    else printf ("Test 2 BAD: n=0 expected, but n=%d.\n", n);

    n = SolveLinear(0,0,0);
    if (n==3) printf ("Test 4 ok\n");
    else printf ("Test 4 BAD: infinity roots expected, but n=%d.", n);

    n = SolveLinear(0,1,0);
    if (n==0) printf ("Test 5 ok\n");
    else printf ("Test 5 BAD: n=0 expected, but n=%d.\n", n);


    n = SolveLinear(1,2,&x);
    if (n==1 && x==-2) printf ("Test 6 ok\n");
    else printf ("Test 6 BAD: n=1; x=-2 expected, but n=%d, x=%lf.\n", n, x);
}



