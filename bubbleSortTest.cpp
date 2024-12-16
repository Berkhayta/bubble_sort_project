#include "Sort.h"
#include "Benchmark.h"
#include "vectorGenerator.h"
#include <iostream>
#include <vector>
#include <functional>

void runSortTests(size_t size) {
    std::cout << "Vector size: " << size << std::endl;

    std::function<bool(int, int)> relation = [](int a, int b) { return a < b; };

    // Rastgele vektör
    auto randomVec = generateRandomVector<int>(size);
    Benchmark<std::chrono::microseconds> b1;
    bubbleSort(randomVec, relation);
    std::cout << "Classic Bubble Sort (Random): " << b1.elapsed() << " µs\n";

    randomVec = generateRandomVector<int>(size);
    Benchmark<std::chrono::microseconds> b2;
    bubbleSortReduced(randomVec, relation);
    std::cout << "Reduced Bubble Sort (Random): " << b2.elapsed() << " µs\n";

    randomVec = generateRandomVector<int>(size);
    Benchmark<std::chrono::microseconds> b3;
    bubbleSortwithFlag(randomVec, relation);
    std::cout << "Bubble Sort with Flag (Random): " << b3.elapsed() << " µs\n";

    // Sıralı vektör
    auto sortedVec = generateSortedVector<int>(size);
    Benchmark<std::chrono::microseconds> b4;
    bubbleSort(sortedVec, relation);
    std::cout << "Classic Bubble Sort (Sorted): " << b4.elapsed() << " µs\n";

    sortedVec = generateSortedVector<int>(size);
    Benchmark<std::chrono::microseconds> b5;
    bubbleSortReduced(sortedVec, relation);
    std::cout << "Reduced Bubble Sort (Sorted): " << b5.elapsed() << " µs\n";

    sortedVec = generateSortedVector<int>(size);
    Benchmark<std::chrono::microseconds> b6;
    bubbleSortwithFlag(sortedVec, relation);
    std::cout << "Bubble Sort with Flag (Sorted): " << b6.elapsed() << " µs\n";

    // Ters sıralı vektör
    auto reverseVec = generateSortedReverseVector<int>(size);
    Benchmark<std::chrono::microseconds> b7;
    bubbleSort(reverseVec, relation);
    std::cout << "Classic Bubble Sort (Reverse): " << b7.elapsed() << " µs\n";

    reverseVec = generateSortedReverseVector<int>(size);
    Benchmark<std::chrono::microseconds> b8;
    bubbleSortReduced(reverseVec, relation);
    std::cout << "Reduced Bubble Sort (Reverse): " << b8.elapsed() << " µs\n";

    reverseVec = generateSortedReverseVector<int>(size);
    Benchmark<std::chrono::microseconds> b9;
    bubbleSortwithFlag(reverseVec, relation);
    std::cout << "Bubble Sort with Flag (Reverse): " << b9.elapsed() << " µs\n";

    std::cout << "-------------------------------------\n";
}

int main() {
    std::vector<size_t> sizes = {5000, 10000, 20000, 30000, 40000, 50000, 60000};

    for (size_t size : sizes) {
        runSortTests(size);
    }

    return 0;
}
