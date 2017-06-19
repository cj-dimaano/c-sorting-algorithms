/*******************************************************************************
  File: radix_lsd_sort.c
  Author: CJ Dimaano
  Date created: April 5, 2016
  Last updated: April 5, 2016
  
  Radix sort is a sorting algorithm that takes advantage of integer properties.
  It is built on top of the counting sort algorithm. The idea behind counting
  sort is that a count for the number of times each distinct element appears in
  the collection is recorded; then the counts are updated to be the number of
  elements "less than or equal to" the element (here, the notion of "less than"
  is arbitrary); then the elements are rearranged into a new collection in the
  order indicated by the counts, where the count for an element represents the
  position in the new collection. Each time an element is placed into the new
  collection, its count is decremented by 1. Counting sort is stable, which is
  important for allowing radix sort to work.
  
  With radix sort, the counting sort algorithm is used to rearrange elements at
  the "digit" level. Radix sort typically treats a single byte as a digit. Radix
  sort LSD (least significant digit) works by using counting sort on the least
  significant digit first and working its way up. No comparisons are made in
  this algorithm.
*******************************************************************************/

#include "sort.h"

/**
 * `RADIX`
 *
 *   Number of bits per "digit" used in the counting sort algorithm.
 */
#define RADIX 256

/**
 * `INDEX`
 *
 *   Macro to calculate the index into the counts array.
 */
#define INDEX(x, y) (((x) & (0xFF << ((y) << 3))) >> ((y) << 3))

/**
 * `radix_lsd_sort`
 *
 *   Uses the radix (LSD) sort algorithm to sort an array of integers.
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
*/
void radix_lsd_sort(int * const arr, const size_t len) {
  size_t i, j, k;
  size_t counts[RADIX];
  int old[len];
  int tmp;

  /*** Use counting sort by rearranging the elements for reach RADIX digit. ***/
  for(i = 0; i < sizeof(int); i++) {

    /*** Copy the array elements into another array. ***/
    for(j = 0; j < len; j++) {
      old[j] = arr[j];
    }

    /*** Set the counts of each RADIX digit to 0. ***/
    for(j = 0; j < RADIX; j++) {
      counts[j] = 0;
    }

    /*** Count the number of occurances of each RADIX digit. ***/
    for(j = 0; j < len; j++) {
      counts[INDEX(old[j], i)]++;
    }

    /*** Count the number of RADIX digits less than or equal to the current ***/
    /*** RADIX digit.                                                       ***/
    for(j = 1; j < RADIX; j++) {
      counts[j] += counts[j - 1];
    }

    /*** Rearrange the elements according to their RADIX ordering. ***/
    for(j = len - 1; j < len; j--) {
      tmp = old[j];
      k = (counts[INDEX(tmp, i)] -= 1);
      arr[k] = tmp;
    }
  }
}
