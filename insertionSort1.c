void insertionSort1(int n, int arr_count, int* arr) {
   int cle = arr[n - 1],i = n - 2;

    while(cle<arr[i]){
        arr[i +1] = arr[i];
        i--;
        for(int i = 0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    arr[i +1] = cle;
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
