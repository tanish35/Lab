#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct term {
    float coeff;
    int expo;
} term;

typedef struct poly {
    term *terms;
    int numTerms;
} poly;

poly createPoly(int maxTerms) {
    poly p;
    p.numTerms = 0;
    p.terms = (term *)malloc(maxTerms * sizeof(term));
    return p;
}

void addTerm(poly *p, float coeff, int expo) {
    if (coeff != 0) {
        p->terms[p->numTerms].coeff = coeff;
        p->terms[p->numTerms].expo = expo;
        p->numTerms++;
    }
}

int evaluatePolynomial(poly p, int x) {
    int result = 0;
    for (int i = 0; i < p.numTerms; i++) {
        result += p.terms[i].coeff * pow(x, p.terms[i].expo);
    }
    return result;
}

int main() {
    poly poly1 = createPoly(3);
    int x = 2;

    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 5, 1);
    addTerm(&poly1, 6, 0);

    int result = evaluatePolynomial(poly1, x);

    printf("Polynomial evaluated at x = %d: %d\n", x, result);

    return 0;
}
