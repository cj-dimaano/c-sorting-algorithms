/*******************************************************************************
  File: heapsort.c
  Author: CJ Dimaano
  Date created: March 5, 2016
  Last updated: April 5, 2016
  
  Heapsort is a comparison-based sorting algorithm. It uses the idea of a
  complete binary tree in order to organize a collection of elements into a
  partially sorted list. The root node is the element of highest importance in
  the collection, and each child is no greater than its parent. Since the heap
  is a complete binary tree, the data structure can be represented as an array.
  The root node will be stored at index 0; the index of the left child can be
  calculated as the index of the current element doubled and incremented by 1;
  the index of the right child can be calculated as the index of the current
  element doubled and incremented by 2; and the parent of any node can be
  calculated as the index of the current element subtracted by 1 and halved.
  Once the elements have been "heapified", the root node is swapped with the
  last element in the array, the heap size is decreased by one, and the
  beginning of the array up to the heap size is re-"heapified". This process
  repeats until the heap has a size of 1.
*******************************************************************************/

#include "sort.h"

/**
 * `LCI`
 *
 *   Left Child Index.
 */
#define LCI(x)    (((x) << 1) + 1)

/**
 * `RCI`
 *
 *   Right Child Index.
 */
#define RCI(x)    (((x) << 1) + 2)

/**
 * `PI`
 *
 *   Parent Index.
 */
#define PI(x)     (((x) - 1) >> 1)


/**
 * `heapsort`
 *
 *   Uses the heapsort algorithm to sort an array of integers.
 *
 *
 * @param arr
 *   The array to be sorted.
 *
 * @param len
 *   The length of the array.
 */
void heapsort(int * const arr, const size_t len) {
  int i, j, k, val, end = len;
  /*** Keep sorting the array until the end of the heap is the first ***/
  /*** element.                                                      ***/
  while(end > 0) {

    /*** Heapify the elements up to the end boundary. ***/
    for(i = 1; i < end; i++) {
      val = arr[i];
      j = i;
      while(j > 0 && val > arr[(k = PI(j))]) {
        swap(arr, j, k);
        j = k;
      }
      arr[j] = val;
    }

    /*** Swap the root of the heap with the end of the heap. ***/
    swap(arr, end - 1, 0);

    /*** Shrink the heap. ***/
    end--;
  }
}
