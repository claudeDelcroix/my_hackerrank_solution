int* quickSort(int arr_count, int* arr, int* result_count) {
    *result_count = arr_count;
    int j = 0,pivot = arr[0];
    int* ar = (int*)malloc(arr_count*sizeof(int));
    
    for(int i = 0;i < arr_count;i++){
        if(arr[i] < pivot){
            ar[j++] = arr[i];
        }
    }
    
    ar[j++] = pivot;
    for(int i = 0;i < arr_count;i++){
        if(arr[i] > pivot){
            ar[j++] = arr[i];
        }
    }
    return ar;
}


//c++ solution
vector<int> quickSort(vector<int> arr) {
    vector<int> left, equal, right;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < arr[0]) left.push_back(arr[i]);
        else if(arr[i] > arr[0]) right.push_back(arr[i]);
        else equal.push_back(arr[i]);
    }
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

//python
  left = []
right = []
equal = [arr[0]]
for i in range(1,len(arr)):
    if arr[i] > arr[0]:
        right.append(arr[i])
    else:
        left.append(arr[i])
x = left + equal + right
return x
