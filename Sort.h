#ifndef SORT_H
#define SORT_H

#include <vector>
#include <functional>
#include <cstddef> // size_t için gerekli

// Klasik Bubble Sort
template<typename T>
void bubbleSort(std::vector<T>& v, std::function<bool(T, T)> compare) {
    for (std::size_t i = 0; i < v.size() - 1; ++i) {
        for (std::size_t j = 0; j < v.size() - i - 1; ++j) {
            if (!compare(v[j], v[j + 1])) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

// Reduced Bubble Sort
template<typename T>
void bubbleSortReduced(std::vector<T>& v, std::function<bool(T, T)> compare) {
    std::size_t n = v.size();
    while (n > 1) {
        std::size_t newn = 0;
        for (std::size_t i = 1; i < n; ++i) {
            if (!compare(v[i - 1], v[i])) {
                std::swap(v[i - 1], v[i]);
                newn = i;
            }
        }
        n = newn;
    }
}

// Bubble Sort with Flag
template<typename T>
void bubbleSortwithFlag(std::vector<T>& v, std::function<bool(T, T)> compare) {
    for (std::size_t i = 0; i < v.size() - 1; ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j < v.size() - i - 1; ++j) {
            if (!compare(v[j], v[j + 1])) {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

#endif
