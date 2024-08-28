#include <stdio.h>
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

poly multiplyPolynomials(poly *p1, poly *p2) {
    poly result = createPoly(p1->numTerms * p2->numTerms);

    for (int i = 0; i < p1->numTerms; i++) {
        for (int j = 0; j < p2->numTerms; j++) {
            int expo = p1->terms[i].expo + p2->terms[j].expo;
            float coeff = p1->terms[i].coeff * p2->terms[j].coeff;

            // Add or combine terms with the same exponent
            int found = 0;
            for (int k = 0; k < result.numTerms; k++) {
                if (result.terms[k].expo == expo) {
                    result.terms[k].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                addTerm(&result, coeff, expo);
            }
        }
    }

    return result;
}

void printPolynomial(poly p) {
    int first = 1;
    for (int i = 0; i < p.numTerms; i++) {
        if (!first) {
            printf(" + ");
        }
        printf("%.2fx^%d", p.terms[i].coeff, p.terms[i].expo);
        first = 0;
    }
    if (first) {
        printf("0");
    }
    printf("\n");
}

int main() {
    poly poly1 = createPoly(3);
    poly poly2 = createPoly(2);

    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 5, 1);
    addTerm(&poly1, 6, 0);

    addTerm(&poly2, 6, 1);
    addTerm(&poly2, 8, 0);

    poly result = multiplyPolynomials(&poly1, &poly2);

    printf("Resultant Polynomial:\n");
    printPolynomial(result);

    return 0;
}
