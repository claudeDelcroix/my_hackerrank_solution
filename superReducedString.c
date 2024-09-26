//deuxieme version de la fonction 
//ces deux codes perfomes la suppression des caracteres qui se repete dans une chaine de facon dont le nombre total de lettre qui se repete doit etre impaire 
//au cas contraire la lettre est supprimee de la chaine.

char* superReducedString(char* s){
    if(strlen(s) == 1){
        return s;
    }
    char *result = (char*)malloc(strlen(s)*sizeof(char));
    int taille = strlen(s), c = 0, idx = 0;

    for(int i = 0;i<taille;i++){
        for(int j = 0;j<taille;j++){
            if(s[i] == s[j]){
                c++;
            }
        }
        if(c%2 != 0){
                int error = 0;
                for(int x = 0;x<idx;x++){
                    if(s[i] == result[x]){
                        error++;
                    }
                }
                if(error == 0){
                     result[idx] = s[i];
                      idx++;
                }
        }
        c = 0;
    }
    if(idx == 0){
        return "Empty String";
    }
    result[idx] = '\0';
    return result;
}

//premiere version du code 
char* superReducedString(char* s){
        if(strlen(s) == 1){
        return s;
    }
    char *result = (char*)malloc(strlen(s)*sizeof(char));
    int taille = strlen(s), c = 0, idx = 0;

    for(int i = 0;i<taille;i++){
        for(int j = 0;j<taille;j++){
            if(s[i] == s[j]){
                c++;
            }
        }
        if(c%2 != 0){
            result[idx] = s[i];
            idx++;
        }
        c = 0;
        if(s[i] == s[i+1])i+=2;
    }
    result[idx] = '\0';
    if(idx == 0){
        return "Empty String";
    }
    return result;
}
/*la fonction qui execute reellement la tache ordonne*/
char* superReducedString(char* s) {
     int len = strlen(s);
    if (len == 0) return "Empty String";

    char *result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < len; i++) {
        if (idx > 0 && result[idx - 1] == s[i]) {
            idx--;  // Remove the last character if it matches the current one
        } else {
            result[idx++] = s[i];  // Add the current character to the result
        }
    }

    result[idx] = '\0';

    if (idx == 0) {
        free(result);
        return "Empty String";
    }

    return result;

}
