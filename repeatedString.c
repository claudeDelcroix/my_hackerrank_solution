/*
 * la fonction une chaine s qu'il faut pour commencer reproduire n fois
 * ensuite compter le nombre de fois que a apparait
 *
 */


long repeatedString(const char* s,const long n) {
    if(strlen(s) == 1) {
        return (s[0] == 'a') ? n : 0;
    }

    long long isA = 0;
    long len = strlen(s);
    for(long i = 0;i < strlen(s);i++) {
        if(s[i] == 'a') {
            isA++;
        }
    }

    long long numberOfTimes = n / len;
    long long remaining = n % len;
    long long totalA = numberOfTimes * isA;

    for(long i = 0;i < remaining;i++) {
        if(s[i] == 'a') {
            totalA++;
        }
    }
    printf("number : %lld and isA = %ld\n",numberOfTimes,isA);
    return totalA;
}

//C++ solution
long ccount(string s) {
    return count(s.begin(), s.end(), 'a');
}

long repeatedString(string s, long n) {
    return (n / s.size()) * ccount(s) + ccount(s.substr(0, n % s.size()));
}
