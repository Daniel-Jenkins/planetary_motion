#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "celestial_system.h"
#include "vector.h"

void get_net_force(struct vector* force, struct celestial_body* target, struct celestial_system* ce_system){
    struct vector* force_tmp = calloc(1, sizeof(struct vector));
    force_tmp->x = 0;
    force_tmp->y = 0;
    force_tmp->z = 0;

    double scalar_factor;
    double distance_factor;
    struct vector* distance = calloc(1, sizeof(struct vector));
    for (int ii=0; ii<ce_system->number_of_bodies; ii++){
        vec_sub(distance, ce_system->body_list[ii]->position, target->position);
        distance_factor = pow(vec_mag(distance), 3);
        if (distance_factor == 0.0){
            continue;
        }
        scalar_factor = ce_system->grav_const * target->mass * ce_system->body_list[ii]->mass / distance_factor;
        scalar_mult_vec(force_tmp, scalar_factor, distance);
        vec_add(force, force, force_tmp);
    }
    free(force_tmp);
    free(distance);
}

void move_body(struct vector* force, double dt, struct celestial_body* body){
    double inverse_mass = 1.0 / body->mass;
    struct vector* acceleration = calloc_zero_vec();
    scalar_mult_vec(acceleration, inverse_mass, force);

    struct vector* delta_velocity = calloc_zero_vec();
    scalar_mult_vec(delta_velocity, dt, acceleration);
    vec_add(body->velocity, body->velocity, delta_velocity);
    struct vector* delta_position = calloc_zero_vec();
    scalar_mult_vec(delta_position, dt, body->velocity);
    vec_add(body->position, body->position, delta_position);

    free(acceleration);
    free(delta_velocity);
    free(delta_position);
}

struct celestial_body* make_body(char* file_line){
    char label[MAX_LEN_LINE];
    double mass;
    double posx, posy, posz;
    double velx, vely, velz;

    if (sscanf(file_line, "%s %lf %lf %lf %lf %lf %lf %lf", label, &mass, &posx, &posy, &posz, &velx, &vely, &velz) != 8){
        printf("Read failure in make_body in celestial_system.c\n");
        exit(EXIT_FAILURE);
    }

    struct celestial_body* body;
    body = calloc(1, sizeof(struct celestial_body));
    struct vector* position = calloc(1, sizeof(struct vector));
    struct vector* velocity = calloc(1, sizeof(struct vector));
    
    body->label = label;
    body->mass = mass;
    position->x = posx;
    position->y = posy;
    position->z = posz;
    velocity->x = velx;
    velocity->y = vely;
    velocity->z = velz;

    body->position = position;
    body->velocity = velocity;

    return body;
}

void populate_system(struct celestial_system* ce_system, char* input_file_name){
    if(ce_system == NULL){
        printf("NULL pointer passed to populate_system\n");
        exit(EXIT_FAILURE);
    }

    FILE* filer;
    filer = fopen(input_file_name, "r");

    ce_system->number_of_bodies = 0;

    if (filer == NULL){
        printf("Cannot open file %s\n", input_file_name);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN_LINE];

    // read in and set the gravitational constant
    fgets(line, MAX_LEN_LINE, filer);
    double grav_const;
    sscanf(line, "%lf", &grav_const);
    ce_system->grav_const = grav_const;

    struct celestial_body* tmp;
    while( fgets(line, MAX_LEN_LINE, filer) != NULL ){
        tmp = make_body(line);

        ce_system->body_list[ce_system->number_of_bodies] = tmp;
        ce_system->number_of_bodies++;
        tmp = NULL;
    }

    fclose(filer);
}

void clear_system(struct celestial_system* ce_system){
    while (ce_system->number_of_bodies > 0){
        free(ce_system->body_list[ce_system->number_of_bodies - 1]->position);
        free(ce_system->body_list[ce_system->number_of_bodies - 1]->velocity);
        free(ce_system->body_list[ce_system->number_of_bodies - 1]);
        ce_system->number_of_bodies--;
    }
    free(ce_system);
}
