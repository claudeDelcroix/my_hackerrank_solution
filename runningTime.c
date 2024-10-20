int runningTime(int arr_count, int* arr) {
    int nbrOperation = 0;
    for(int i = 1;i < arr_count; i++){
        int cle = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > cle){
            arr[j + 1] = arr[j];
            j--;
            nbrOperation++;
        }
        arr[j + 1] = cle;
    }
    return nbrOperation;
}
