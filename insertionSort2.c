void insertionSort2(int n, int arr_count, int* arr) {
    for(int i = 1;i<n;i++){
        int cle = arr[i];
        int j = i -1;
        while(j>= 0 && arr[j]>cle){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = cle;
        for(int i =0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
