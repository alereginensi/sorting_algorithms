#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of numbers
 * @size: size of the array
 */
 void quick_sort(int *array, size_t size)
 {

 }

 void quicksort(int *array,int first,int last){
    int i, j, pivot, temp;
    if(first<last){
       pivot=first;
       i=first;
       j=last;
       while(i<j){
          while(number[i]<=number[pivot]&&i<last)
          i++;
          while(number[j]>number[pivot])
          j--;
          if(i<j){
             temp=number[i];
             number[i]=number[j];
             number[j]=temp;
          }
       }
       temp=number[pivot];
       number[pivot]=number[j];
       number[j]=temp;
       quicksort(number,first,j-1);
       quicksort(number,j+1,last);
    }
 }
