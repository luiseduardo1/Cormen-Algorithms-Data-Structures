//  Created by Luis Eduardo Obando on 2015-10-26.
//  Copyright (c) 2015 Luis E. Obando. All rights reserved.
//
//  An example of Heapsort implementation in C++ using vectors:
//     Worst case performance       O(n log n)
//     Best case performance        O(n log n)
//     Average case performance     O(n log n)
//

#include <vector>
#include <iostream>
#include <math.h>

void maxHeapify(std::vector<int>& A, int i, size_t heapSize){
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int largest = i;
    
    if ((left <= heapSize) && (A[left] > A[i])) {
        largest = left;
    }
    if ((right <= heapSize) && (A[right] > A[largest])) {
        largest = right;
    }
    if (largest != i){
        std::swap(A[i], A[largest]);
        maxHeapify(A, largest, heapSize);
    }
}

void BuildMaxHeapify(std::vector<int>& A){
    for (int i = floor((A.size()/2)-1); i >= 0; --i) {
        maxHeapify(A, i, A.size()-1);
    }
}

void heapsort(std::vector<int>& A){
    BuildMaxHeapify(A);
    size_t heapSize = A.size()-1;
    for (size_t i = A.size()-1; i >= 1; --i) {
        std::swap(A[0], A[i]);
        --heapSize;
        maxHeapify(A, 0, heapSize);
    }
}

int main() {
    std::vector<int> numbers = {1,7,2,2,3,11,5,8};
    heapsort(numbers);
    for(const auto& x: numbers)
        std::cout << x <<" ";
    return 0;
}
