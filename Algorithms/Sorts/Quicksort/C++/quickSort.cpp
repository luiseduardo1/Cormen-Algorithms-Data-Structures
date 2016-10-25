/**
 *  Created by Luis Eduardo Obando on 2015-10-26.
 *  Copyright (c) 2015 Luis E. Obando. All rights reserved.
 *
 */
 
#include <iostream>
#include <vector>

int partition(std::vector<int>& numbers, int firstElementIndex, int lastElementIndex) {
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

void quickSort(std::vector<int>& numbers, int firstElementIndex, int lastElementIndex) {
    if (firstElementIndex < lastElementIndex) {
        int pivotIndex = partition(numbers, firstElementIndex, lastElementIndex);
        quickSort(numbers, firstElementIndex, pivotIndex - 1);
        quickSort(numbers, pivotIndex + 1, lastElementIndex);
    }
}

// Testing the quicksort function
int main() {
    std::vector<int> numbers = {44, 9, 237, 1, 34, 5, 345, 1, 3};
    quickSort(numbers, 0, numbers.size()-1);
    
    for(const auto& x: numbers) {
        std::cout << x <<" ";
    }
    return 0;
}
