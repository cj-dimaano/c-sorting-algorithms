/*******************************************************************************
  File: main.c
  Author: CJ Dimaano
  Date created: March 4, 2016
  Last updated: March 6, 2016
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

#define DEF_N 32
#define MAX_N (RAND_MAX > ~(1 << 31) ? ~(1 << 31) : RAND_MAX)

/* Function declarations ******************************************************/

static void print_usage(const char * const);
static void print_arr(const int * const, const int);

/* Main ***********************************************************************/

int main(int argc, char **argv) {
  int n = DEF_N;    /* Number of elements to be sorted. */
  int *arr = NULL;  /* Array to be sorted. */

  /*** Check if any arguments were provided. ***/
  if(argc > 1) {

    /*** Set the length of the array to the max if specified. ***/
    if(!strcmp(argv[1], "max")) {
      n = MAX_N;
    }

    /*** Try to parse the argument for the length of the array. ***/
    else {
      n = atoi(argv[1]);
      if(n <= 0 || n > MAX_N){
        print_usage(argv[0]);
        return 0;
      }
    }
  }

  /*** Try to initialize the array. ***/
  arr = (int *)malloc(sizeof(int) * n);
  if(arr == NULL) {
    printf("error: failed to allocate the array.\n");
    return 0;
  }
  init_arr(arr, n);
  print_arr(arr, n);

  /*** Sort the array. ***/
  /*heapsort(arr, n);*/
  /*selection_sort(arr, n);*/
  /*insertion_sort(arr, n);*/
  /*merge_sort(arr, n);*/
  quicksort(arr, n);
  /*radix_lsd_sort(arr, n);*/
  test_arr(arr, n);
  print_arr(arr, n);

  /*** Free the allocated array. ***/
  free(arr);
  
  return 0;
}

/* Function definitions *******************************************************/

/**
 * `print_usage`
 *
 *   Prints the usage message for this program.
 *
 * @param prgm_name
 *   The name of the program as given by argv[0].
 */
static void print_usage(const char * const prgm_name) {
  printf("Usage: %s [n]\n", prgm_name);
  printf("\tn\tNumber of elements to be sorted. The default is %d. The maximum"
    " is %d.\n\n", DEF_N, MAX_N);
}

/**
 * `print_arr`
 *
 *   Prints the contents of an array.
 *
 * @param arr
 *   The array to be printed.
 *
 * @param len
 *   The length of the array.
 */
static void print_arr(const int * const arr, const int len) {
  int i;
  printf("[");
  if(len > 0) {
    printf(" %d", arr[0]);
    for(i = 1; i < len; i++) {
      printf(", %d", arr[i]);
    }
  }
  printf(" ]\n");
}
