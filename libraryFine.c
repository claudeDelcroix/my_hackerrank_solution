int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if(y1 > y2){
        return 10000;
    }
    if(d1>d2 && m1 == m2 && y1 == y2){
        int fine = (d1 - d2)*15;
        return fine;
    }
    if(m1 > m2 && y1 == y2){
        int fine = 500*(m1 - m2);
        return fine;
    }
    return 0;
}
