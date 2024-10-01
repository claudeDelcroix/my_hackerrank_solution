// la version optimiser de mon code par copilot 
char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    k = k % 26;
    for(int i = 0; i < len; i++) {
        if(isalpha(s[i])) {
            char base = islower(s[i]) ? 'a' : 'A';
            s[i] = base + (s[i] - base + k) % 26;
        }
    }
    return s;
}


// la version originale de mon code 
//le code est trp long et ne passe pas tous les tests, la valeur de K n'est pas bien ajuster 
char* caesarCipher(char* s, int k) {
        for(int i = 0;i<strlen(s);i++){
            if(s[i]>= 'a' && s[i]<='z'){
                if(((s[i]+k) > 'z') && k<=26){
                    int add = abs(s[i]-'z');
                    add = abs(add - k);
                    s[i] = 'a' + add-1;
                }
                else if(k>26){
                    int k_s = k;
                    while(k_s>27){
                        k_s-=27;
                    }
                    if(((s[i]+k_s) > 'z')){
                    int add = abs(s[i]-'z');
                    add = abs(add - k_s);
                    s[i] = 'a' + add-1;
                }
                else{
                    s[i] = 'a' + k_s -1;
                }
                }
                else{
                    s[i] += k;
                }
            }
            //deuxieme partie
            if(s[i]>= 'A' && s[i]<='Z'){
                if((s[i]+k > 'Z') && k<=26){
                    int add = abs(s[i]-'Z');
                    add = abs(add - k);
                    s[i] = 'A' + add-1;
                }
                else if(k>26){
                    int k_s = k;
                    while(k_s>27){
                        k_s-=27;
                    }
                    if(((s[i]+k_s) > 'Z')){
                    int add = abs(s[i]-'Z');
                    add = abs(add - k_s);
                    s[i] = 'A' + add-1;
                }
                    s[i] = 'A' + k_s - 1;
                }
                else{
                    s[i] += k;
                }
            }
        }
    return s;
    }
