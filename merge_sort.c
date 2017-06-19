/*******************************************************************************
  File: merge_sort.c
  Author: CJ Dimaano
  Date created: March 6, 2016
  Last updated: April 5, 2016
  
  Merge sort is a comparison-based sorting algorithm. It works by dividing an
  array into halves, sorting each sub-array, and merging the two halves back
  together. Merge sort is recursive and will recurse until the sub-array it is
  working on has 2 or less elements.
*******************************************************************************/

#include "sort.h"

/**
 * `merge`
 *
 *   Merges two sub-arrays in sorted order.
 *
 * @param arr
 *   The beginning of the array containing the sub-arrays to be merged.
 *
 * @param len
 *   The length of the array.
 *
 * @param mid
 *   The midpoint of the array.
 */
static void merge(int * const arr, const size_t len, const size_t mid) {
  int temp[len];  /* Temporary array to hold sorted elements. */
  size_t i;          /* Main iterator. */
  size_t j = 0;      /* Left sub-array iterator. */
  size_t k = mid;    /* Right sub-array iterator. */

  /*** Merge the two sub-arrays. ***/
  for(i = 0; i < len; i++) {
    if(j >= mid || (k < len && arr[j] > arr[k])) {
      temp[i] = arr[k];
      k++;
    }
    else {
      temp[i] = arr[j];
      j++;
    }
  }

  /*** Update the array. ***/
  for(i = 0; i < len; i++) {
    arr[i] = temp[i];
  }
}


/**
 * `merge_sort`
 *
 *   Uses the merge sort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void merge_sort(int * const arr, const size_t len) {
  int mid;  /* Middle index. */

  /*** Base case. ***/
  /***   Swap the left and right elements if the left is greater than the ***/
  /***   right.                                                           ***/
  if(len == 2) {
    if(arr[0] > arr[1]) {
      swap(arr, 0, 1);
    }
  }

  /*** Recurse case. ***/
  /***   Split the array into halves, sort each sub-array, and merge. ***/
  else if(len > 2) {
    mid = (len >> 1);
    merge_sort(arr, mid);
    merge_sort((arr + mid), len - mid);

    /*** Only merge if the middle two elements are unsorted. ***/
    if(arr[mid - 1] > arr[mid]) {
      merge(arr, len, mid);
    }
  }
}