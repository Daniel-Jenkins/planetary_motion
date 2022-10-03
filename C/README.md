# Planet Motion Simulation

A program to simulate the motion of the planets using Euler integration of Newtonian gravity.

# Modules
## Vector
A 3D-vector struct with basic addition/subtraction, as well as magnitude and multiplication by a scalar functions.

## Celestial Body
A struct containing the position, velocity, and mass of a celestial body (planet, star, etc.).
Functions for determining total force on a given body given an array of other bodies.

## System
A collection of celestial bodies and functions to update the position and velocities of the bodies.

## Simulation
The main code to kick start the simulation and handle I/O.
