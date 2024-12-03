int estAlternee(const char* s) {
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == s[i + 1]) {
            return 0;
        }
    }
    return 1;
}


int alternate(char* s) {
    if(strlen(s) == 1){
        return 0;
    }
    int maxLongueur = 0;
    int n = strlen(s);


    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++) {
          
            char temp[n + 1];
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == a || s[i] == b) {
                    temp[k++] = s[i];
                }
            }
            temp[k] = '\0';

 
            if (estAlternee(temp)) {
                int longueur = strlen(temp);
                if (longueur > maxLongueur) {
                    maxLongueur = longueur;
                }
            }
        }
    }

    return maxLongueur;
}
