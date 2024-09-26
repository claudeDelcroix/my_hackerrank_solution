int findDigits(int n) {
     int count = 0,recup = n;
    while(recup>0){
        int div = recup%10;
        if( div!= 0 && n%div== 0){
            count++;
        }
        recup = recup / 10;
    }
    return count;
}
