//lab 05
// Created by Vincent Lin on 2/16/24.
//3504
#include <iostream>
#include <vector>
#include <string>
#include "thedatathings.h"

int linear_search(const std::vector<std::string>& container, const std::string& element) {
    for (size_t i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            std::cout << "The linear search found " << element << " at index " << i << std::endl;
            return static_cast<int>(i);
        }
    }

    std::cout << element << " was not found in the data" << std::endl;
    return -1;
}

int binary_search(const std::vector<std::string>& container, const std::string& element) {
    int low = 0, high = static_cast<int>(container.size()) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        const std::string& mid_element = container[mid];

        if (element == mid_element) {
            std::cout << "The binary search found " << element << " at index " << mid << std::endl;
            return mid;
        } else if (mid_element < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << element << " was not found in the data" << std::endl;
    return -1;
}

int main() {
    std::vector<std::string> data = get_data();
    linear_search(data, "not_here");
    binary_search(data, "not_here");
    linear_search(data, "mzzzz");
    binary_search(data, "mzzzz");
    linear_search(data, "aaaaa");
    binary_search(data, "aaaaa");

    return 0;
}

#include "analyzer.h"
