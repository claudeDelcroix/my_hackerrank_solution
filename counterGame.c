int countSetBits(unsigned long long n) {
    int count = 0;
    while(n) {
        count += n&1;
        n >>=1;
    }

    return count;
}
char* counterGame(const long n) {
    const int m = countSetBits(n - 1);

    return m % 2 == 0? "Richard" : "Louise";
}
