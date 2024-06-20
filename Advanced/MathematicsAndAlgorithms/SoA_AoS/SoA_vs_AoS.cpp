#include <iostream>
#include <chrono>
#include <vector>

//  to make it run:
//  g++ ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp -o SoA_vs_Aos 
//  To enable C++11, use the following command:
//  g++ -std=c++11 ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos.cpp -o ./Advanced/MathematicsAndAlgorithms/SoA_Aos/SoA_vs_Aos -o SoA_vs_Aos 
//  To run the program, use this command:
//  ./SoA_vs_Aos

// Number of particles
const int NUM_PARTICLES = 1000000;
const float DT = 0.01f;

// Structure of Arrays (SoA)
struct ParticlesSoA {
    std::vector<float> x, y, z;
    std::vector<float> vx, vy, vz;

    ParticlesSoA(int n) {
        x.resize(n);
        y.resize(n);
        z.resize(n);
        vx.resize(n);
        vy.resize(n);
        vz.resize(n);
    }
};

// Array of Structures (AoS)
struct ParticleAoS {
    float x, y, z;
    float vx, vy, vz;
};

void updateParticlesAoS(std::vector<ParticleAoS>& particles, float dt) {
    for (int i = 0; i < particles.size(); ++i) {
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
        particles[i].z += particles[i].vz * dt;
    }
}

void updateParticlesSoA(ParticlesSoA& particles, float dt) {
    for (int i = 0; i < particles.x.size(); ++i) {
        particles.x[i] += particles.vx[i] * dt;
        particles.y[i] += particles.vy[i] * dt;
        particles.z[i] += particles.vz[i] * dt;
    }
}

int main() {
    // Initialize particles for AoS
    std::vector<ParticleAoS> particlesAoS(NUM_PARTICLES);
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        particlesAoS[i] = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    }

    // Initialize particles for SoA
    ParticlesSoA particlesSoA(NUM_PARTICLES);
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        particlesSoA.x[i] = 0.0f;
        particlesSoA.y[i] = 0.0f;
        particlesSoA.z[i] = 0.0f;
        particlesSoA.vx[i] = 1.0f;
        particlesSoA.vy[i] = 1.0f;
        particlesSoA.vz[i] = 1.0f;
    }

    // Measure time for AoS
    auto start = std::chrono::high_resolution_clock::now();
    updateParticlesAoS(particlesAoS, DT);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedAoS = end - start;
    std::cout << "Time taken by AoS: " << elapsedAoS.count() << " seconds" << std::endl;

    // Measure time for SoA
    start = std::chrono::high_resolution_clock::now();
    updateParticlesSoA(particlesSoA, DT);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSoA = end - start;
    std::cout << "Time taken by SoA: " << elapsedSoA.count() << " seconds" << std::endl;

    return 0;
}
