#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

void vec_add(struct vector* res, struct vector* v1, struct vector* v2){
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
}

void vec_sub(struct vector* res, struct vector* v1, struct vector* v2){
    res->x = v1->x - v2->x;
    res->y = v1->y - v2->y;
    res->z = v1->z - v2->z;
}

double vec_mag(struct vector* v1){
    double res = 0;

    res += v1->x * v1->x;
    res += v1->y * v1->y;
    res += v1->z * v1->z;

    return sqrt(res);
}

void scalar_mult_vec(struct vector* res, double scalar, struct vector* v1){
    res->x = scalar * v1->x;
    res->y = scalar * v1->y;
    res->z = scalar * v1->z;
}

struct vector* calloc_zero_vec(){
    struct vector* res = calloc(1, sizeof(struct vector));

    if (res == NULL){
        printf("Failed to calloc vector.\n");
        exit(EXIT_FAILURE);
    }

    res->x = 0.0;
    res->y = 0.0;
    res->z = 0.0;

    return res;
}
