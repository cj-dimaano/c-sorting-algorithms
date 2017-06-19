/*******************************************************************************
  File: insertion_sort.c
  Author: CJ Dimaano
  Date created: March 5, 2016
  Last updated: April 5, 2016
  
  Insertion sort is a comparison-based sorting algorithm. It works by visiting
  each element in the array and inserting the current element into the sorted
  portion of the array. The insertion operation involves shifting all elements
  in the sorted portion of the array that are not better than the current
  element being inserted, and placing the insertion element before the shifted
  elements.
*******************************************************************************/

#include "sort.h"

/**
 * `insertion_sort`
 *
 *   Uses the insertion sort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void insertion_sort(int * const arr, const size_t len) {
  size_t i, j;
  int val;

  /*** Select each element in the unsorted portion of the array. ***/
  for(i = 1; i < len; i++) {

    /*** Get the value of the current element. ***/
    val = arr[i];
    
    /*** Shift all of the elements in the sorted portion of the array that ***/
    /*** are not better than the value of the current element.             ***/
    j = i;
    while(j < len && val < arr[j - 1]) {
      arr[j] = arr[j - 1];
      j--;
    }

    /*** Insert the value of the current element into the sorted portion of ***/
    /*** the array.                                                         ***/
    arr[j] = val;
  }
}
