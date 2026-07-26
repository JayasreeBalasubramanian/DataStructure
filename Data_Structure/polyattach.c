#include <stdio.h>

typedef struct
{ int co_eff, exp;
} TERM;
typedef struct
{
     TERM t[100];
     int n;
} POLY;
POLY createPoly()
{
    POLY p;
    p.n=0;
    return p;
}
void printPoly(POLY p) {
    for (int i = 0; i < p.n; i++) {
        if (p.t[i].co_eff >= 0 && i > 0) {
            printf("+");
        }
        printf("%dx^%d ", p.t[i].co_eff, p.t[i].exp);
    }
    printf("\n");
}
POLY attachTerm(POLY p, TERM t)
{   int i = p.n-1;
    while (i>=0) {
        if (p.t[i].exp == t.exp) {
            return p;
        } else {
            i = i - 1;
        }
    }
    i = p.n-1;
    while ((i>=0) && (p.t[i].exp < t.exp))
        {
            p.t[i+1] = p.t[i];
            i = i - 1;
        }
    p.t[i+1] = t;
    p.n = p.n + 1;
    return p;
}

int main()
{
    TERM t1 = {2, 12}, t2 = { 7, 12}, t3 = {3, 7};
    POLY p;
    p = createPoly();
    p = attachTerm(p, t1);
    p = attachTerm(p, t2);
    p = attachTerm(p, t3);
    printf ("\n P1 = ");
    printPoly(p);
    return 0;
}
