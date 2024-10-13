char* pangrams(char* s) {
    if(strlen(s) < 26){
        return "not pangram";
    }
    char* example = {"abcdefghijklmnopqrstuvwxyz"};
    int verif = 0;
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < strlen(s);j++){
            char c = s[j];
            if(s[j]>= 'A' && s[j]<='Z'){
                c = tolower(s[j]);
            }
            if(example[i] == c){
                verif++;
            }
        }
        if(verif == 0){
            return "not pangram";
        }
        verif = 0;
    }
    
    return "pangram";
}
