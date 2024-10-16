long xorArrayUntil(long num) {
    int rem = num % 8;
    
    if (rem < 2) {
        return num;
    } else if (rem < 4) {
        return 2;
    } else if (rem <6) {
        return num + 2;
    } else {
        return 0;
    }
}

long xorSequence(long l, long r) {
        long start = xorArrayUntil(l-1);
        long end = xorArrayUntil(r);
    
    return start ^ end;
}

//mon code
//gros problemes de memoire "segmentation fault" , ne rempli pas tout les tests 
long xorSequence(long l, long r) {
    long *a = (long*)malloc((r+1)*sizeof(long));
    a[0] = 0;
    for(long i = 1;i < r+1;i++){
        a[i] = a[i-1]^i;
    }
    long result = 0;
    for(long i = l;i<=r;i++){
        result ^= a[i];
    }
    free(a);    
    return result;
}
