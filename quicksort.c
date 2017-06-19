/*******************************************************************************
  File: quicksort.c
  Author: CJ Dimaano
  Date created: March 6, 2016
  Last updated: April 6, 2016
  
  Quicksort is a comparison-based sorting algorithm. It works by partitioning an
  array and recursively sorting both sides of the partition. Partitioning
  involves choosing a pivot value and moving elements less than the pivot to one
  side and moving the remaining elements to the other side.
*******************************************************************************/

#include "sort.h"

/**
 * `partition`
 *
 *   Partitions an array by arranging elements less than a pivot value onto one
 *   side and the remaining elements onto the other.
 *
 * @param arr
 *   The array to partition.
 *
 * @param len
 *   The length of the array.
 *
 * @return
 *   The pivot index between the two partitions.
 */
static inline size_t partition(int * const arr, const size_t len) {
  size_t left = 0;
  size_t right = len - 2;
  size_t pivot = len - 1;

  /*** Partition the sub-array. ***/
  while(left < right) {

    /*** Move the left index to the first element that is not less than the ***/
    /*** pivot. ***/
    while(left < right && arr[left] < arr[pivot]) {
      left++;
    }

    /*** Move the right index to the first element that is not greater-than ***/
    /*** or equal to the pivot, or up to the left index.                    ***/
    while(right > left && arr[right] >= arr[pivot]) {
      right--;
    }

    /*** Swap the left and right elements if they are not in the correct ***/
    /*** half of the sub-array.                                          ***/
    if(left < right) {
      swap(arr, left, right);
      left++;
      right--;
    }
  }

  /*** Swap the left element with the pivot. ***/
  if(arr[left] < arr[pivot]) {
    left++;
  }
  swap(arr, left, pivot);
  return left;
}



/**
 * `quicksort`
 *
 *   Uses the quicksort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void quicksort(int * const arr, const size_t len) {
  size_t pivot;
  size_t length = len;
  int *array = arr;

  /*** Keep sorting the sub-array while its length is greater than 1. ***/
  while(length > 1) {

    /*** Partition the sub-array and obtain the pivot index. ***/
    pivot = partition(array, length);

    /*** Quicksort the right sub-array if it has fewer elements and update ***/
    /*** the bounds of the working array.                                  ***/
    if(pivot > length - pivot) {
      quicksort((array + pivot + 1), length - pivot - 1);
      length = pivot;
    }

    /*** Quicksort the left sub-array if it has the same or fewer elements ***/
    /*** and update the bounds of the working array.                       ***/
    else {
      quicksort(array, pivot);
      array = array + pivot + 1;
      length = length - pivot - 1;
    }
  }
}
