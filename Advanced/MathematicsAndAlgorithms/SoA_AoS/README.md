## Initialization:
    AoS: We create a vector of ParticleAoS structures and initialize each particle's position and velocity.
    SoA: We create a ParticlesSoA structure containing vectors for each coordinate and initialize them.

### Update Function:
    AoS: updateParticlesAoS updates the positions using the velocities for each particle in the particlesAoS vector.
    SoA: updateParticlesSoA updates the positions using the velocities for each particle in the particlesSoA structure.
### Timing:
    We use std::chrono::high_resolution_clock to measure the time taken to update all particles for both AoS and SoA.

#### Output
    Time taken by AoS: 0.00841062 seconds
    Time taken by SoA: 0.00835908 seconds    

## How to run:
    g++ ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp -o SoA_vs_Aos 
### To enable C++11, use the following command:
    g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp -o ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos -o SoA_vs_Aos 
### To run the program, use this command:
    ./SoA_vs_Aos
