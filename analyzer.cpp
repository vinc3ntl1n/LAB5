#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "getData.h"

// Linear search function
int linear_search(const std::vector<std::string>& container, const std::string& element) {
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
            std::cout << "The linear search for " << element << " takes " << duration.count() << " microseconds" << std::endl;
            return static_cast<int>(i);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << element << " was not found in the data but it took " << duration.count() << " microseconds" << std::endl;
    return -1;
}

// Binary search function
int binary_search(const std::vector<std::string>& container, const std::string& element) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int low = 0, high = static_cast<int>(container.size()) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        const std::string& mid_element = container[mid];

        if (element == mid_element) {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
            std::cout << "The binary search for " << element << " takes " << duration.count() << " microseconds" << std::endl;
            return mid;
        } else if (mid_element < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << element << " was not found in the data but it took " << duration.count() << " microseconds" << std::endl;
    return -1;
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<std::string> data = get_data();
    linear_search(data, "not_here");
    binary_search(data, "not_here");
    linear_search(data, "mzzzz");
    binary_search(data, "mzzzz");
    linear_search(data, "aaaaa");
    binary_search(data, "aaaaa");

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Total time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}