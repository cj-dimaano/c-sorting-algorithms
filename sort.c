/*******************************************************************************
  File: sort.c
  Author: CJ Dimaano
  Date created: March 5, 2016
  Last updated: April 5, 2016
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

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
void init_arr(int * const arr, const size_t len) {
  size_t i, rng; /* Iterator, random number generator. */

  /*** Add distinct elements to the array. ***/
  for(i = 0; i < len; i++) {
    arr[i] = i;
  }

  /*** Shuffle the elements in the array. ***/
  for(i = 0; i < len; i++) {
    rng = rand() % len;
    swap(arr, i, rng);
  }
}

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
void test_arr(const int * const arr, const size_t len) {
  size_t i;  /* Iterator. */

  /*** Make sure the previous element is not greater than the current ***/
  /*** element.                                                       ***/
  for(i = 1; i < len && arr[i - 1] <= arr[i]; i++);

  /*** Print an error message if the array is not sorted. ***/
  if(i < len) {
    printf("error: failed to sort array.\n");
    printf("\tarr[%u] = %d\n", (unsigned int)(i - 1), arr[i - 1]);
    printf("\tarr[%u] = %d\n", (unsigned int)i, arr[i]);
  }
}

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
inline void swap(int * const arr, const size_t i, const size_t j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
