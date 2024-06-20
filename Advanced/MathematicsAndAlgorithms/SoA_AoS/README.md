Explanation

    Initialization:
        AoS: We create a vector of ParticleAoS structures and initialize each particle's position and velocity.
        SoA: We create a ParticlesSoA structure containing vectors for each coordinate and initialize them.

    Update Function:
        AoS: updateParticlesAoS updates the positions using the velocities for each particle in the particlesAoS vector.
        SoA: updateParticlesSoA updates the positions using the velocities for each particle in the particlesSoA structure.

    Timing:
        We use std::chrono::high_resolution_clock to measure the time taken to update all particles for both AoS and SoA.

    Output:
    Time taken by AoS: 0.00841062 seconds
    Time taken by SoA: 0.00835908 seconds    