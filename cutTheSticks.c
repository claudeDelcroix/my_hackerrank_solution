 void swap(int* xp,int* yp){
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
 }
 
 int partition(int arr[],int low,int high){
    const int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low;j < high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
 }
 
 void quickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi - 1);
        quickSort(arr,pi + 1,high);
    }
 }
 
 int minValue(int arr[],int size){
    int min = 0;
    for(int i = 0; i < size;i++){
        if(size <= arr[i] && arr[i] > 0){
            min = arr[i];
        }
    }
    return min;
 }

//mon code , avec une complexite qui ne repond pas a tous les tests mais la logique de depart est interessante 
int* cutTheSticks(int arr_count,int* arr,int* result_count) {
    quickSort(arr,0,arr_count -1);

    int final = 0,k = 0,size = 1;
    int* t = (int*)malloc(arr_count*sizeof(int));
    int* result = (int*)malloc(arr_count*sizeof(int));
    result[0] = arr_count;

    while(final != 1) {
        const int min = arr[0];
        for(int i = 0;i < arr_count;i++) {
            if((arr[i] - min)>0) {
                t[k] = arr[i] - min;
                k+=1;
            }
        }

        for(int i = 0;i <= k;i++) {
            arr[i] = t[i];
        }
        final = k;
        arr_count = k;
        printf("k = %d \n",k);
        if(k > 0) {
            result[size++] = k;
        }
        k = 0;
    }
    result = (int*)realloc(result,size*sizeof(int));
    *result_count = size;
    free(t);
    return result;
}

//l'optimisation generer par copilot 
void swap(int* xp,int* yp){
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
 }
 
 int partition(int arr[],int low,int high){
    const int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low;j < high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
 }
 
 void quickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi - 1);
        quickSort(arr,pi + 1,high);
    }
 }
 
 int minValue(int arr[],int size){
    int min = 0;
    for(int i = 0; i < size;i++){
        if(size <= arr[i] && arr[i] > 0){
            min = arr[i];
        }
    }
    return min;
 }
 
int* cutTheSticks(int arr_count, int* arr, int* result_count) {
    quickSort(arr, 0, arr_count - 1);

    int size = 0;
    int* result = (int*)malloc(arr_count * sizeof(int));
    result[size++] = arr_count;

    int current_length = arr_count;
    int min = arr[0];
    
    for (int i = 0; i < arr_count;) {
        int count = 0;
        while (i < arr_count && arr[i] == min) {
            count++;
            i++;
        }
        current_length -= count;
        if (current_length > 0) {
            result[size++] = current_length;
            if (i < arr_count) {
                min = arr[i];
            }
        }
    }

    result = (int*)realloc(result, size * sizeof(int));
    *result_count = size;

    return result;
}
