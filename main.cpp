#include <iostream>
#include <string>
#include <chrono>
#include <random>

const int N = 1000;

int A[N][N];
int B[N][N];
int C[N][N];

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) C[i][j] = 0;
    }
}

void kij() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    } 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for kij: " << duration.count() << " microseconds" << std::endl;
}

void kji() {
    auto start = std::chrono::high_resolution_clock::now();
    for(int k = 0; k < N; k++) {
        for(int j = 0; j < N; j++) {
            for(int i = 0; i < N; i++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for kji: " << duration.count() << " microseconds" << std::endl;
}

void ijk() {
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for ijk: " << duration.count() << " microseconds" << std::endl;
}

void ikj() {
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < N; i++) {
        for(int k = 0; k < N; k++) {
            for(int j = 0; j < N; j++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for ikj: " << duration.count() << " microseconds" << std::endl;
}

void jki() {
    auto start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < N; j++) {
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for jki: " << duration.count() << " microseconds" << std::endl;
}

void jik() {
    auto start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N; i++) {
            for(int k = 0; k < N; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken for jik: " << duration.count() << " microseconds" << std::endl;
}

int main(int argc, char *argv[]) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 50.0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = dist(mt), B[i][j] = dist(mt);
            C[i][j] = 0;
        }
    }
    std::string cmd = argv[1];
    if(cmd == "kij") {
        kij();
    } else if(cmd == "kji") {
        kji();
    } else if(cmd == "ijk") {
        ijk(); 
    } else if(cmd == "ikj") {
        ikj();
    } else if(cmd == "jik") {
        jik();
    } else {
        jki();
    }
}
