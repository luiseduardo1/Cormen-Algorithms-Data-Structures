//  Created by Luis Eduardo Obando on 2015-10-26.
//  Copyright (c) 2015 Luis E. Obando. All rights reserved.
//
//  An example of bubbleSort implementation in C++ using vectors:
//     Worst case performance       O(n^2)
//     Best case performance        O(n)
//     Average case performance     O(n^2)
//
//  Bubble sort works by iterating through each element of a list and comparing each pair of elements and
//  switching their positions if necessary.

#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> numbers)
{
    for (int i = (numbers.size() - 1); i != 0; i--)
    {
        for (int j = 0; j < (numbers.size() - 1); j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    return numbers;
};

// Testing the bubbleSort function

int main() {
    std::vector<int> numbers = {44, 9, 237, 1, 5, 44, 534, 17, 21, 819, 1};
    std::vector<int> sortedNumbers = bubbleSort(numbers);
    for(const auto& x: sortedNumbers)
        std::cout << x <<" ";
    return 0;
}
