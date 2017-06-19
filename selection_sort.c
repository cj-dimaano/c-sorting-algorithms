/*******************************************************************************
  File: selection_sort.c
  Author: CJ Dimaano
  Date created: March 5, 2016
  Last updated: April 5, 2016
  
  Selection sort is a comparison-based sorting algorithm. It works by selecting
  each element in an array and swapping it with the best element in the unsorted
  portion of the array. The best element can only be determined by an exhaustive
  search through the unsorted portion of the array.
*******************************************************************************/

#include "sort.h"

/**
 * `selection_sort`
 *
 *   Uses the selection sort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void selection_sort(int * const arr, const size_t len) {
  size_t i, j;
  int best;

  /*** Select each element in the array one at a time. ***/
  for(i = 0; i < len - 1; i++) {

    /*** Assume the current element is the best out of the remaining ***/
    /*** unsorted elements.                                          ***/
    best = i;

    /*** Search the remainder of the array for the best element. ***/
    for(j = i + 1; j < len; j++) {
      if(arr[best] > arr[j]) {
        best = j;
      }
    }

    /*** Swap the best element with the current element. ***/
    swap(arr, i, best);
  }
}