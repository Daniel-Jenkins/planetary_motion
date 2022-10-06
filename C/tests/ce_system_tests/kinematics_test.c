#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "celestial_system.h"
#include "vector.h"

int main(void){
    char fname[] = "/home/daniel/Documents/projects/planet_simulation/C/tests/ce_system_tests/sample_bodies.dat";

    struct celestial_system* ce_system;
    ce_system = calloc(1, sizeof(struct celestial_system));
    struct vector* force = calloc(1, sizeof(struct vector));

    populate_system(ce_system, fname);
    get_net_force(force, ce_system->body_list[0], ce_system);
    clear_system(ce_system);

    bool passed_test;

    if (force->x == -1.0 && force->y == 0.0 && force->z == 0.0){
        free(force);
        return 0;
    }
    else{
        free(force);
        return 1;
    }

    return 0;
}
