#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define GRID_SIZE_X 200
#define GRID_SIZE_Y 200
#define TIME_STEPS 1000

// Physical Constants
const double C = 3e8;         // Speed of light
const double EPSILON = 8.85e-12; // Permittivity
const double MU = 4 * M_PI * 1e-7; // Permeability

// Global Arrayst
double Ez[GRID_SIZE_X][GRID_SIZE_Y]; // Electric field (Z-component)
double Hx[GRID_SIZE_X][GRID_SIZE_Y]; // Magnetic field (X-component)
double Hy[GRID_SIZE_X][GRID_SIZE_Y]; // Magnetic field (Y-component)

// Function Prototypes
void initializeFields();
void updateFields();
void visualizeFields();
void simulate();

int main() {
    printf("Starting Electromagnetic Field Simulation...\n");

    // Initialize fields
    initializeFields();

    // Run the simulation
    simulate();

    printf("Simulation Complete.\n");
    return 0;
}

// Initialize fields to zero
void initializeFields() {
    for (int i = 0; i < GRID_SIZE_X; i++) {
        for (int j = 0; j < GRID_SIZE_Y; j++) {
            Ez[i][j] = 0.0;
            Hx[i][j] = 0.0;
            Hy[i][j] = 0.0;
        }
    }
}

// Update the fields using FDTD method
void updateFields() {
    // Update magnetic fields Hx, Hy based on Ez
    for (int i = 0; i < GRID_SIZE_X - 1; i++) {
        for (int j = 0; j < GRID_SIZE_Y - 1; j++) {
            Hx[i][j] += -(Ez[i][j + 1] - Ez[i][j]);
            Hy[i][j] += (Ez[i + 1][j] - Ez[i][j]);
        }
    }

    // Update electric field Ez based on Hx, Hy
    for (int i = 1; i < GRID_SIZE_X; i++) {
        for (int j = 1; j < GRID_SIZE_Y; j++) {
            Ez[i][j] += (Hy[i][j] - Hy[i - 1][j]) - (Hx[i][j] - Hx[i][j - 1]);
        }
    }
}

// Visualize the fields (Placeholder for now)
void visualizeFields() {
    printf("Visualizing fields (to be implemented)...\n");
}

// Simulation loop
void simulate() {
    for (int t = 0; t < TIME_STEPS; t++) {
        updateFields();
        if (t % 100 == 0) {
            printf("Step %d completed.\n", t);
            visualizeFields();
        }
    }
}


// What This Code Does
// Field Initialization:

// Sets the electric and magnetic fields to zero.
// FDTD Updates:

// Updates the magnetic fields (Hx, Hy) and the electric field (Ez) using simplified finite-difference equations.
// Simulation Loop:

// Iteratively updates fields and calls visualization (currently a placeholder).
