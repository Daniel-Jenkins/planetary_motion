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

    struct vector* res_sub = calloc(1, sizeof(struct vector));

    vec_sub(res_sub, v1, v2);
    free(v1);
    free(v2);

    if (res_sub->x == 1.0 && res_sub->y == 1.0 && res_sub->z == 3.0){
        free(res_sub);
        return 0;
    }
    else{
        free(res_sub);
        return 1;
    }
}

