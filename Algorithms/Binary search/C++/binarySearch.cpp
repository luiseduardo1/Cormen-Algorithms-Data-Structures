/**
 *  Created by Luis Eduardo Obando on 2015-10-26.
 *  Copyright (c) 2015 Luis E. Obando. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include <math.h>

template<typename T>
int binarySearch(std::vector<T>& numbers, int firstElementIndex, int lastElementIndex, int elementToFind) {
    if (firstElementIndex > lastElementIndex) {
        return -1;
    }

    int median = floor((firstElementIndex + lastElementIndex) / 2);
    if (numbers[median] == elementToFind) {
        return median;
    } else if (numbers[median] > elementToFind) {
        return binarySearch(numbers, firstElementIndex, median - 1, elementToFind);
    } else {
        return binarySearch(numbers, median + 1, lastElementIndex, elementToFind);
    }
}

// Testing the binary seach algorithm
int main() {
    std::vector<int> numbers = {1, 4, 6, 14, 134, 234, 432, 321};
    int result1 = binarySearch(numbers, 0, numbers.size()-1, 432);
    int result2 = binarySearch(numbers, 0, numbers.size()-1, 66);
    std::cout << result1 << std::endl; // Should return 6
    std::cout << result2 << std::endl; // Should return -1
    return 0;
}
