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

poly addPolynomials(poly *p1, poly *p2) {
    poly result = createPoly(p1->numTerms + p2->numTerms);

    int i = 0, j = 0;
    while (i < p1->numTerms && j < p2->numTerms) {
        if (p1->terms[i].expo == p2->terms[j].expo) {
            addTerm(&result, p1->terms[i].coeff + p2->terms[j].coeff, p1->terms[i].expo);
            i++;
            j++;
        } else if (p1->terms[i].expo > p2->terms[j].expo) {
            addTerm(&result, p1->terms[i].coeff, p1->terms[i].expo);
            i++;
        } else {
            addTerm(&result, p2->terms[j].coeff, p2->terms[j].expo);
            j++;
        }
    }

    while (i < p1->numTerms) {
        addTerm(&result, p1->terms[i].coeff, p1->terms[i].expo);
        i++;
    }

    while (j < p2->numTerms) {
        addTerm(&result, p2->terms[j].coeff, p2->terms[j].expo);
        j++;
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

    addTerm(&poly1, 5, 2);
    addTerm(&poly1, 4, 1);
    addTerm(&poly1, 2, 0);

    addTerm(&poly2, 5, 1);
    addTerm(&poly2, 5, 0);

    poly result = addPolynomials(&poly1, &poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
