#ifndef VECTORGENERATOR_H
#define VECTORGENERATOR_H

#include <vector>
#include <algorithm>
#include <random>

// Rastgele vektör oluşturur
template<typename T>
std::vector<T> generateRandomVector(size_t size) {
    std::vector<T> v(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(1, 10000);

    for (auto& x : v) {
        x = dis(gen);
    }
    return v;
}

// Sıralı vektör oluşturur
template<typename T>
std::vector<T> generateSortedVector(size_t size) {
    std::vector<T> v(size);
    for (size_t i = 0; i < size; ++i) {
        v[i] = i;
    }
    return v;
}

// Ters sıralı vektör oluşturur
template<typename T>
std::vector<T> generateSortedReverseVector(size_t size) {
    std::vector<T> v(size);
    for (size_t i = 0; i < size; ++i) {
        v[i] = size - i;
    }
    return v;
}

#endif
