/*******************************************************************************
  File: sort.h
  Author: CJ Dimaano
  Date created: March 5, 2016
  Last updated: April 5, 2016
  
  
  TODO:
  -radix_msd_sort
  -bubble sort
  -cocktail shaker sort
  -other sorts
*******************************************************************************/

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * `init_arr`
 *
 *   Initializes an array with shuffled distinct values.
 *
 *   The array must already be allocated in memory.
 *
 * @param arr
 *   The array to be populated with shuffled values.
 *
 * @param len
 *   The length of the array. 
 */
void init_arr(int * const arr, const size_t len);


/**
 * `test_arr`
 *
 *   Checks if an array is sorted in ascending order.
 *
 * @param arr
 *   The array to be checked.
 *
 * @param len
 *  The length of the array.
 */
void test_arr(const int * const arr, const size_t len);


/**
 * `swap`
 *
 *   Swaps two elements in an array according to their indices.
 *
 *   This function does not check if the indices are out-of-bounds.
 *
 * @param arr
 *   The array with which to swap the elements.
 *
 * @param i
 *   The index of the first element to be swapped.
 *
 * @param j
 *   The index of the second element to be swapped.
 */
inline void swap(int * const arr, const size_t i, const size_t j);


/**
 * `selection_sort`
 *
 *   Uses the selection sort algorithm to sort an array of integers.
 *
 * @description
 *   Selection sort is a comparison-based sorting algorithm. It works by
 *   selecting each element in an array and swapping it with the best element
 *   in the unsorted portion of the array. The best element can only be
 *   determined by an exhaustive search through the unsorted portion of the
 *   array.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void selection_sort(int * const arr, const size_t len);


/**
 * `insertion_sort`
 *
 *   Uses the insertion sort algorithm to sort an array of integers.
 *
 * @description
 *   Insertion sort is a comparison-based sorting algorithm. It works by
 *   visiting each element in the array and inserting the current element into
 *   the sorted portion of the array. The insertion operation involves shifting
 *   all elements in the sorted portion of the array that are not better than
 *   the current element being inserted, and placing the insertion element
 *   before the shifted elements.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void insertion_sort(int * const arr, const size_t len);


/**
 * `merge_sort`
 *
 *   Uses the merge sort algorithm to sort an array of integers.
 *
 * @description
 *   Merge sort is a comparison-based sorting algorithm. It works by dividing an
 *   array into halves, sorting each sub-array, and merging the two halves back
 *   together. Merge sort is recursive and will recurse until the sub-array it
 *   is working on has 2 or less elements.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void merge_sort(int * const arr, const size_t len);


/**
 * `quicksort`
 *
 *   Uses the quicksort algorithm to sort an array of integers.
 *
 * @description
 *   Quicksort is a comparison-based sorting algorithm. It works by partitioning
 *   an array and recursively sorting both sides of the partition. Partitioning
 *   involves choosing a pivot value and moving elements less than the pivot to
 *   one side and moving the remaining elements to the other side.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void quicksort(int * const arr, const size_t len);


/**
 * `heapsort`
 *
 *   Uses the heapsort algorithm to sort an array of integers.
 *
 * @description
 *   Heapsort is a comparison-based sorting algorithm. It uses the idea of a
 *   complete binary tree in order to organize a collection of elements into a
 *   partially sorted list. The root node is the element of highest importance
 *   in the collection, and each child is no greater than its parent. Since the
 *   heap is a complete binary tree, the data structure can be represented as an
 *   array. The root node will be stored at index 0; the index of the left child
 *   can be calculated as the index of the current element doubled and
 *   incremented by 1; the index of the right child can be calculated as the
 *   index of the current element doubled and incremented by 2; and the parent
 *   of any node can be calculated as the index of the current element
 *   subtracted by 1 and halved. Once the elements have been "heapified", the
 *   root node is swapped with the last element in the array, the heap size is
 *   decreased by one, and the beginning of the array up to the heap size is
 *   re-"heapified". This process repeats until the heap has a size of 1.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void heapsort(int * const arr, const size_t len);


/**
 * `radix_lsd_sort`
 *
 *   Uses the radix (LSD) sort algorithm to sort an array of integers.
 *
 * @description
 *   Radix sort is a sorting algorithm that takes advantage of integer
 *   properties. It is built on top of the counting sort algorithm. The idea
 *   behind counting sort is that a count for the number of times each distinct
 *   element appears in the collection is recorded; then the counts are updated
 *   to be the number of elements "less than or equal to" the element (here, the
 *   notion of "less than" is arbitrary); then the elements are rearranged into
 *   a new collection in the order indicated by the counts, where the count for
 *   an element represents the position in the new collection. Each time an
 *   element is placed into the new collection, its count is decremented by 1.
 *   Counting sort is stable, which is important for allowing radix sort to
 *   work.
 *
 *   With radix sort, the counting sort algorithm is used to rearrange elements
 *   at the "digit" level. Radix sort typically treats a single byte as a digit.
 *   Radix sort LSD (least significant digit) works by using counting sort on
 *   the least significant digit first and working its way up. No comparisons
 *   are made in this algorithm.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
*/
void radix_lsd_sort(int * const arr, const size_t len);


/**
 * `radix_msd_sort`
 *
 *   Uses the radix (MSD) sort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
/*void radix_msd_sort(int * const arr, const size_t len);*/


#endif
