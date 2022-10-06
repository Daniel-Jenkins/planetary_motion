#ifndef CELESTIAL_SYSTEM_H
#define CELESTIAL_SYSTEM_H

#define MAX_NUM_BODIES 20
#define MAX_LEN_LINE 500

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct celestial_body{
    char* label;
    struct vector* position;
    struct vector* velocity;
    double mass;
};

struct celestial_system{
    int number_of_bodies;
    double grav_const;
    struct celestial_body* body_list[MAX_NUM_BODIES];
};

/*
 * Function: get_net_force
 * 
 * Returns the net Newtonian gravitational force on a celestial body
 *
 * force: vector struct to hold the result
 * target: the body the force will be acting on
 * ce_system: the full celestial system that is acting upon the target
 */
void get_net_force(struct vector* force, struct celestial_body* target, struct celestial_system* ce_system);

/*
 * Function: move_body
 *
 * Moves the given body given the force and a time step
 *
 * force: vector representing the force on the body
 * dt: length of the time step to use in the Euler integration
 * body: the celestial body to be moved, on which the force is acting
 */
void move_body(struct vector* force, double dt, struct celestial_body* body);

/*
 * Function: populate_system
 *
 * ce_system: the system to be populated
 * input_file_name: path to the input file
 */
void populate_system(struct celestial_system* ce_system, char* input_file_name);

/*
 * Function clear_system
 *
 * Free up all the memeory used in a given celestial_system
 *
 * ce_system: the system to be freed from memory 
 */
void clear_system(struct celestial_system* ce_system);

/*
 * Function: make_body
 *
 * Takes a line from the input files and produces a celestial_body object
 *
 * file_line: a char* with the file line containing all the info
 *
 * returns: a pointer to a celestial_body with all the information from file_line
 */
struct celestial_body* make_body(char* file_line);

#endif
