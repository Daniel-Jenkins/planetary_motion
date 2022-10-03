#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

int main(void){
    struct vector* v1 = calloc(1, sizeof(struct vector));
    v1->x = 2.0;
    v1->y = 3.0;
    v1->z = 6.0;

    float res_mag;

    res_mag = vec_mag(v1);
    free(v1);

    if (res_mag == 7.0){
        return 0;
    }
    else{
        return 1;
    }
}

