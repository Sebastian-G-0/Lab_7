#include <stdio.h>

void swap(int *xp, int *yp, int *swap_count) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    (*swap_count)++;
}

void bubbleSort(int arr[], int n, int count[], int *swap_count) {
    int i, j;
    for (i = 0; i < n-1; i++) {     
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                count[arr[j]]++; 
                swap(&arr[j], &arr[j+1], swap_count);
            }
        }
    }
}

void selectionSort(int arr[], int n, int count[], int *swap_count) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i) {
            count[arr[min_idx]]++; 
            swap(&arr[min_idx], &arr[i], swap_count);
        }
    }
}


int main() {
    int array1_bubble[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array1_selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2_bubble[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array2_selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1_bubble)/sizeof(array1_bubble[0]);
    int n2 = sizeof(array2_bubble)/sizeof(array2_bubble[0]);
    int count1_bubble[100] = {0};
    int count1_selection[100] = {0};
    int count2_bubble[100] = {0};
    int count2_selection[100] = {0};
    int swap_count1_bubble = 0;
    int swap_count1_selection = 0;
    int swap_count2_bubble = 0;
    int swap_count2_selection = 0;

    bubbleSort(array1_bubble, n1, count1_bubble, &swap_count1_bubble);
    selectionSort(array1_selection, n1, count1_selection, &swap_count1_selection);
    bubbleSort(array2_bubble, n2, count2_bubble, &swap_count2_bubble);
    selectionSort(array2_selection, n2, count2_selection, &swap_count2_selection);

    printf("array1_bubble:\n");
    for (int i = 0; i < n1; i++)
        printf("%d: %d times\n", array1_bubble[i], count1_bubble[array1_bubble[i]]);
    printf("Total swaps in bubble sort: %d\n", swap_count1_bubble);

    printf("array1_selection:\n");
    for (int i = 0; i < n1; i++)
        printf("%d: %d times\n", array1_selection[i], count1_selection[array1_selection[i]]);
    printf("Total swaps in selection sort: %d\n", swap_count1_selection);

    printf("array2_bubble:\n");
    for (int i = 0; i < n2; i++)
        printf("%d: %d times\n", array2_bubble[i], count2_bubble[array2_bubble[i]]);
    printf("Total swaps in bubble sort: %d\n", swap_count2_bubble);

    printf("array2_selection:\n");
    for (int i = 0; i < n2; i++)
        printf("%d: %d times\n", array2_selection[i], count2_selection[array2_selection[i]]);
    printf("Total swaps in selection sort: %d\n", swap_count2_selection);

    return 0;
}
