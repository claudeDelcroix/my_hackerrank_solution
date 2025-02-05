int gemstones(int arr_count, char** arr) {
    char* ok = NULL;
    int pres = 0, dragon = 0;
    for(char i = 'a';i <= 'z';i++) {
        for(int j = 0;j < arr_count;j++) {
            ok = strchr(arr[j],i);
            if(ok != NULL) {
                pres++;
            }
            ok = NULL;
        }
        if(pres == arr_count) {
            dragon++;
        }
        pres = 0;
    }
    free(ok);
    return dragon;
}
