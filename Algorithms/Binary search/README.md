# Binary Search

## Algorithm

Binary seach is an algorithm for finding an element in a binary search tree or couldalso be used for sorted arrays. The fact that we use the algorithm on a binary search tree or on an array is not so important because we dont care so much about how the data structure is implemented. What is important is that we can take an object and be able to do 3 things with it: get a element, get a left sub-object and a right sub-object and the data structure respect the constraint that the elements in the left sub-object are smaller than the element, and the the elements in the right sub-object are greater than the element.

We will often use the term *binary search* when the algorithm is used on arrays and *binary search tree* when is used on a tree based data structure.

#### Running time :
  - Best case performance: θ(1)
  - Worst case performance: θ(log n)
  - Average case performance: θ(log n)

## Pseudocode

![binarySearch](fig/binarySearch.png)
