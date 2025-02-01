int jumpingOnClouds(int c_count, int* c) {
    if(c_count == 2){
        return 1;
    }
    int mov = 0;
    for(int i = 0;i < c_count;i++) {
        if((i+1) < c_count && c[i+1] == 1) {
            mov++;
            i++;
        }else if(((i+1) < c_count || (i+2) < c_count ) && c[i+1] == 0 && c[i+2] == 1) {
            mov++;
        }else if(((i+1) < c_count || (i+2) < c_count ) && c[i+1] == 0 && c[i+2] == 0) {
            mov++;
            i+=1;
        }else {
            mov++;
        }
    }
    return mov - 1;
}

//good C++ solution 
int jumpingOnClouds(vector<int> c) {
    int result = 0, index = 0;
    while(index < c.size() - 1){
        if(c[index + 2] == 1) index++;
        else index+=2;
        result++;
    }
    return result;
}
