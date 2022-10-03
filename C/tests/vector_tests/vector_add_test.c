#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

int main(void){
    struct vector* v1 = calloc(1, sizeof(struct vector));
    v1->x = 2.0;
    v1->y = 3.0;
    v1->z = 6.0;

    struct vector* v2 = calloc(1, sizeof(struct vector));
    v2->x = 1.0;
    v2->y = 2.0;
    v2->z = 3.0;

    struct vector* res_add = calloc(1, sizeof(struct vector));

    vec_add(res_add, v1, v2);
    free(v1);
    free(v2);


    if (res_add->x == 3.0 && res_add->y == 5.0 && res_add->z == 9.0){
        free(res_add);
        return 0;
    }
    else{
        free(res_add);
        return 1;
    }
}

