/**
 *  Created by Luis Eduardo Obando on 2015-10-26.
 *  Copyright (c) 2015 Luis E. Obando. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

/*
 * \brief Implementation of merge algorithm
 * \param[in] numbers Vector containing all the numbers to be sorted
 * \param[in] p Index of the first element
 * \param[in] q Index of the last element of the first partition
 * \param[in] r Index of the last element
*/
template<typename T>
void merge(std::vector<T>& numbers, int p, int q, int r)
{
    int n1 = q - p + 1;  // Number of elements to be sorted in leftVector
    int n2 = r - q;      // Number of elements to be sorted in rightVector
    
    std::vector<T> leftVector(n1 + 1); // Add one element for the sentinel value
    std::vector<T> rightVector(n2 + 1);
    
    for (int i = 0; i < n1; i++)
    {
        leftVector[i] = numbers[p + i];
    }
    
    for (int j = 0; j < n2; j++)
    {
        rightVector[j] = numbers[q + j + 1];
    }
    
    leftVector[n1] = std::numeric_limits<T>:: max(); // Sentinel value added at the end of the vector
    rightVector[n2] = std::numeric_limits<T>:: max();
    int i = 0;
    int j = 0;
    
    for (int k = p; k <= r; k++)
    {
        if (leftVector[i] <= rightVector[j])
        {
            numbers[k] = leftVector[i];
            i++;
        }
        else
        {
            numbers[k] = rightVector[j];
            j++;
        }
    }
}

/*
 * \brief Implementation of merge sort algorithm
 * \param[in] numbers Vector containing numbers to be sorted
 * \param[in] p Index of the first element of the vector
 * \param[in] r Index of the last element of the vector
 */
template <typename T>
void mergeSort(std::vector<T>& numbers, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        mergeSort(numbers, p, q);
        mergeSort(numbers, q + 1, r);
        merge(numbers, p, q, r);
    }
}

// Testing the merge sort algorithm

int main() {
    std::vector<int> numbers = {44, 9, 237, 1, 5, 44, 2, 5, 6};
    mergeSort(numbers, 0, numbers.size()- 1);
    for(const auto& x: numbers)
        std::cout << x <<" ";
    return 0;
}
