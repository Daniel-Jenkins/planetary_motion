#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "celestial_system.h"

int main(void){
    int num_steps = 100;
    double dt = 0.001;
    char input_file[] = "/home/daniel/Documents/projects/planet_simulation/C/simulation/input.dat";
    char output_file[] = "/home/daniel/Documents/projects/planet_simulation/C/simulation/output.dat";

    struct celestial_system* ce_system = calloc(1, sizeof(struct celestial_system));
    populate_system(ce_system, input_file);

    FILE* output = fopen(output_file, "w");
    if(output == NULL){
        printf("Failed to open file in simulation.c\n");
        exit(EXIT_FAILURE);
    }

    double posx, posy, posz;
    for(int body_num=0; body_num < ce_system->number_of_bodies; body_num++){
        posx = ce_system->body_list[body_num]->position->x;
        posy = ce_system->body_list[body_num]->position->y;
        posz = ce_system->body_list[body_num]->position->z;
        fprintf(output, "%lf %lf %lf\n", posx, posy, posz);
    }
    fprintf(output, "\n");

    struct vector* force = calloc(1, sizeof(struct vector));
    for(int step=0; step < num_steps; step++){
        for(int body_num=0; body_num < ce_system->number_of_bodies; body_num++){
            get_net_force(force, ce_system->body_list[body_num], ce_system);
            move_body(force, dt, ce_system->body_list[body_num]);
            posx = ce_system->body_list[body_num]->position->x;
            posy = ce_system->body_list[body_num]->position->y;
            posz = ce_system->body_list[body_num]->position->z;
            fprintf(output, "%lf %lf %lf\n", posx, posy, posz);
        }
        fprintf(output, "\n");
    }

    fclose(output);
    free(force);
    clear_system(ce_system);
}

