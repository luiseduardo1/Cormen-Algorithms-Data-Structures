/**
 *  Created by Luis Eduardo Obando on 2015-10-26.
 *  Copyright (c) 2015 Luis E. Obando. All rights reserved.
 *
 */
 
#include <iostream>
#include <vector>

/**
 *  \brief The partition function divide the vector in two sets, one below the pivot value and the other above.
 *  \param[in] p Index of the first element
 *  \param[in] r Index of the last element
 */
int partition(std::vector<int>& numbers, int p, int r)
{
    int pivot = numbers[r]; // Value of the last element
    int i = p - 1; // p = index of the first element
    for (int j = p; j < r ; j++) // Iterate till the last element before the pivot
    {
        if (numbers[j] <= pivot)
        {
            i++;
            std::swap(numbers[i], numbers[j]);
        }
    }
    std::swap(numbers[i + 1], numbers[r]);
    return (i + 1); // Return the index of the final position of the pivot
}

/**
 *  \brief Implement the quicksort algorithm.
 *  \param[in] p Index of the first element
 *  \param[in] r Index of the last element
*/
void quickSort(std::vector<int>& numbers, int p, int r)
{
    if (p < r)
    {
        int q = partition(numbers, p, r);
        quickSort(numbers, p, q - 1);
        quickSort(numbers, q + 1, r);
    }
}

// Testing the quicksort function
int main() {
    std::vector<int> numbers = {44, 9, 237, 1, 34, 5, 345, 1, 3};
    quickSort(numbers, 0, numbers.size()-1);
    for(const auto& x: numbers)
        std::cout << x <<" ";
    return 0;
}
