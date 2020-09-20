#include <stdio.h>
#include <math.h>

int IsZero(double forCompare)
    {
        const double small = 1e-6;

        if (fabs(forCompare) <  small) return 1;
        if (fabs(forCompare) >= small) return 0;
    }
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
int SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x)
{

        double discrim = b*b - 4*a*c;

        if (IsZero(discrim) == 1) discrim = 0;

        if (discrim > 0)
        {
            *x1 = (-b - sqrt(discrim))/(2*a);
            *x2 = (-b + sqrt(discrim))/(2*a);

            return 2;
        }

        if (discrim == 0)
        {
            *x = -b/2*a;
            *x = round(*x);

            return 1;

        }
        if (discrim < 0)
        {
            return 0;
        }
        else return -1;
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


    n = SolveQuadratic(1, 2, 1, 0, 0, &x);
    if (n==1 && x==-1) printf ("Test 2 ok\n");
    else printf ("Test 2 BAD: n=1; x=-1 expected, but n=%d, x=%lf.\n", n, x);


    n = SolveQuadratic(1, 2, 3, 0, 0, 0);
    if (n==0) printf ("Test 3 ok\n");
    else printf ("Test 2 BAD: n=0 expected, but n=%d.\n", n);


    n = SolveLinear(0, 0, 0);
    if (n==3) printf ("Test 4 ok\n");
    else printf ("Test 4 BAD: infinity roots expected, but n=%d.", n);


    n = SolveLinear(0, 1, 0);
    if (n==0) printf ("Test 5 ok\n");
    else printf ("Test 5 BAD: n=0 expected, but n=%d.\n", n);


    n = SolveLinear(1, 2, &x);
    if (n==1 && x==-2) printf ("Test 6 ok\n");
    else printf ("Test 6 BAD: n=1; x=-2 expected, but n=%d, x=%lf.\n", n, x);


    n = SolveQuadratic(1, 0, 0, 0, 0, &x);
    if (n==1 && x==0) printf ("Test 7 ok\n");
    else printf ("Test 7 BAD: n=1; x=0 expected, but n=%d, x=%lf.\n", n, x);


    n = SolveQuadratic(1, 4.000000004, 4.000000001, 0, 0, &x);
    if (n==1 && x==-2) printf ("Test 8 ok\n");
    else printf ("Test 8 BAD: n=1; x=-2 expected, but n=%d, x=%lf.\n", n, x);


    n = SolveQuadratic(1, 4.000000001, 4.000000004, 0, 0, &x);
    if (n==1 && x==-2) printf ("Test 9 ok\n");
    else printf ("Test 9 BAD: n=1; x=-2 expected, but n=%d, x=%lf.\n", n, x);
}
