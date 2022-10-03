#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "celestial_system.h"
#include "vector.h"

bool num_bodies_test(struct celestial_system* ce_system){
    if (ce_system->number_of_bodies == 2){
        return true;
    }
    else{
        return false;
    }
}

bool position_test(struct celestial_system* ce_system){
    bool pos1 = (ce_system->body_list[0]->position->x == 0.5);
    bool pos2 = (ce_system->body_list[0]->position->y == 0.0);
    bool pos3 = (ce_system->body_list[0]->position->z == 0.0);

    return (pos1 && pos2 && pos3);
}

bool velocity_test(struct celestial_system* ce_system){
    bool vel1 = (ce_system->body_list[0]->velocity->x == 0.0);
    bool vel2 = (ce_system->body_list[0]->velocity->y == 0.0);
    bool vel3 = (ce_system->body_list[0]->velocity->z == 0.0);

    return (vel1 && vel2 && vel3);
}

int main(void){
    char fname[] = "/home/daniel/Documents/projects/planet_simulation/C/tests/ce_system_tests/sample_bodies.dat";

    struct celestial_system* ce_system;
    ce_system = calloc(1, sizeof(struct celestial_system));

    bool correct_size;
    bool correct_pos;
    bool correct_vel;

    populate_system(ce_system, fname);

    correct_size = num_bodies_test(ce_system);
    correct_pos = position_test(ce_system);
    correct_vel = velocity_test(ce_system);

    clear_system(ce_system);

    if (correct_size != true){
        return 1;
    }
    if (correct_pos != true){
        return 2;
    }
    if (correct_vel != true){
        return 3;
    }

    return 0;
}
