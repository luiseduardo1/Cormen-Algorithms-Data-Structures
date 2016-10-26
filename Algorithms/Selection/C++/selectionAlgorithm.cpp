/**
 *  Created by Luis Eduardo Obando on 2016-10-26.
 *  Copyright (c) 2016 Luis E. Obando. All rights reserved.
 *
 */

#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& numbers, int firstElementIndex, int lastElementIndex) {
    int pivot = numbers[lastElementIndex]; 
    int finalPivotIndex = firstElementIndex; 

    for (int j = firstElementIndex; j < lastElementIndex ; ++j) {
        if (numbers[j] <= pivot) {
            std::swap(numbers[finalPivotIndex], numbers[j]);
            finalPivotIndex++;
        }
    }

    std::swap(numbers[finalPivotIndex], numbers[lastElementIndex]);
    return finalPivotIndex; 
}

template <typename T>
T selection(std::vector<T>& numbers, int firstElementIndex, int lastElementIndex, int elementToFindIndex) {
    int pivotIndex = partition(numbers, firstElementIndex, lastElementIndex);

    if ((pivotIndex - firstElementIndex + 1) == elementToFindIndex) {
        return numbers[pivotIndex];
    } else if ((pivotIndex - firstElementIndex + 1) > elementToFindIndex) {
        return selection(numbers, firstElementIndex, pivotIndex-1, elementToFindIndex);
    } else {
        return selection(numbers, pivotIndex+1, lastElementIndex, (elementToFindIndex - pivotIndex + firstElementIndex - 1));
    }
}

// Testing the selection algorithm
int main() {
    std::vector<int> numbers = {345, 44, 9, 237, 1, 5, 1, 44, 2, 5, 6};
    int result = selection<int>(numbers, 0, numbers.size()-1, 7);
    std::cout << result << std::endl; // Should return 9
    return 0;
}
