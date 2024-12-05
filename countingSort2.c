int* countingSort(int arr_count, int* arr, int* result_count) {
    int* result = (int*)calloc(100,sizeof(int));
    if(result == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0;i < arr_count;i++){
        result[arr[i]]++;
    }
    int* newArray = (int*)calloc(arr_count,sizeof(int));
    if(newArray == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    int j = 0;
    for(int i = 0;i < 100;i++){
        if(result[i] == 1){
            newArray[j] = i;
            j++;
        }else if(result[i] > 1){
            int c = result[i];
            while(c > 0){
                newArray[j] = i;
                j++;
                c--;
            }
        }
    }
    *result_count = arr_count;
    free(result);
    return newArray;
}


//version du code optimiser par copilot
#include <stdio.h>
#include <stdlib.h>

int* countingSort(int arr_count, int* arr, int* result_count) {
    // Trouver la valeur maximale dans le tableau pour optimiser la taille de "result"
    int max_val = 0;
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Allouer de la mémoire pour le tableau de comptage
    int* result = (int*)calloc(max_val + 1, sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Remplir le tableau de comptage
    for (int i = 0; i < arr_count; i++) {
        result[arr[i]]++;
    }

    // Allouer de la mémoire pour le tableau trié
    int* sortedArray = (int*)malloc(arr_count * sizeof(int));
    if (sortedArray == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Remplir le tableau trié en fonction des occurrences
    int j = 0;
    for (int i = 0; i <= max_val; i++) {
        while (result[i] > 0) {
            sortedArray[j++] = i;
            result[i]--;
        }
    }

    *result_count = arr_count;
    free(result);
    return sortedArray;
}

int main() {
    int arr[] = {5, 3, 8, 6, 1, 9, 2, 4, 7, 0};
    int arr_count = sizeof(arr) / sizeof(arr[0]);
    int result_count;
    int* sortedArray = countingSort(arr_count, arr, &result_count);

    printf("Tableau trié : ");
    for (int i = 0; i < result_count; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    free(sortedArray);
    return 0;
}
