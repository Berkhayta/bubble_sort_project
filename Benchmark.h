#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

template<typename DurationType>
class Benchmark {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    Benchmark() { start = std::chrono::high_resolution_clock::now(); }

    int elapsed() {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<DurationType>(end - start).count();
    }
};

#endif
