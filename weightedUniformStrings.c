int giveTHeNumbers(const char s) {
    switch (s) {
        case 'a' :
            return 1;
        case 'b' :
            return 2;
        case 'c' :
            return 3;
        case 'd' :
            return 4;
        case 'e' :
            return 5 ;
        case 'f' :
            return 6;
        case 'g' :
            return 7;
        case 'h' :
            return 8;
        case 'i' :
            return 9;
        case 'j' :
            return 10;
        case 'k' :
            return 11;
        case 'l' :
            return 12;
        case 'm' :
            return 13;
        case 'n' :
            return 14;
        case 'o' :
            return 15;
        case 'p' :
            return 16;
        case 'q' :
            return 17;
        case 'r' :
            return 18;
        case 's' :
            return 19;
        case 't' :
            return 20;
        case 'u' :
            return 21;
        case 'v' :
            return 22;
        case 'w' :
            return 23;
        case 'x' :
            return 24;
        case 'y' :
            return 25;
        case 'z' :
            return 26;
        default:
            return 0;
    }
}

int* returnArray(char* s) {
    int* value = (int*)malloc(strlen(s)*sizeof(int));
    int fois = 2,c = 0;

    //remplicage des valeurs dans le tableau
    value[0] = giveTHeNumbers(s[0]);
    for(int i = 1 ; i < strlen(s);i++) {
        if(s[i] == s[i - 1]) {
            value[i] = value[i - 1 - c] * fois;
            fois++;
            c++;
        }else {
            value[i] = giveTHeNumbers(s[i]);
            fois = 2;
            c = 0;
        }
    }
    return value;
}

char** weightedUniformStrings(char* s, int queries_count, int* queries, int* result_count) {
    //tableau d'entier
    int* array = returnArray(s);
    char** reponse = (char**)malloc(queries_count*sizeof(char*));

    for(int i = 0;i < queries_count;i++) {
        reponse[i] = (char*)malloc(3*sizeof(char));
        int count = 0;
        for(int j = 0; j < strlen(s);j++) {
            if(queries[i] == array[j]) {
                count++;
                break;
            }
        }
        if(count != 0) {
            reponse[i] = "Yes";
        }else {
            reponse[i] = "No";
        }
    }
    free(array);
    *result_count = queries_count;
    return reponse;
}
