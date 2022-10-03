#ifndef VECTOR_H
#define VECTOR_H

// A vector struct containing three doubles, one for each Cartesian coordinate
struct vector{
    double x;
    double y;
    double z;
};

/*
 * Function: vec_add
 *
 * Adds the two given vectors.
 *
 * res: A pointer to a vector to save the result in
 * v1: A vector struct pointer to one summand
 * v2: A vector struct pointer to the other summand
 */
void vec_add(struct vector* res, struct vector* v1, struct vector* v2);

/*
 * Function: vec_sub
 *
 * Takes the difference of two given vectors.
 *
 * res: A pointer to a vector to save the result in
 * v1: A vector struct pointer to the first vector
 * v2: A vector struct pointer to the vector to be subtracted.
 */
void vec_sub(struct vector* res, struct vector* v1, struct vector* v2);

/*
 *Function: vec_mag
 *
 *Returns the magnitude of the given vector.
 *
 *v1: A vector struct
 *
 *returns: A double
 */
double vec_mag(struct vector* v1);

void scalar_mult_vec(struct vector* res, double scalar, struct vector* v1);

struct vector* calloc_zero_vec();

#endif
