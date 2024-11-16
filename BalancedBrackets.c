char* isBalanced(char* s) {
    if(strlen(s)%2 != 0){
        return "NO";
    }

    //parenthese = 0,crochet = 0,bracket = 0;
    int par_g = 0,par_d = 0,cro_g = 0,cro_d = 0,brac_g = 0,brac_d = 0;

    for(int i = 0;i<strlen(s);i++){
        if(s[i] == '('){
            par_g++;
        }
        if(s[i] == ')')
        {
            par_d++;
        }
        if(s[i] == '['){
            cro_g++;
        }
        if(s[i] == ']'){
            cro_d++;
        }
        if(s[i] == '{'){
            brac_g++;
        }
        if(s[i] == '}'){
            brac_d++;
        }
        

    }

    if(((par_d + par_g)%2 != 0) || ((cro_d + cro_g)%2 != 0) || ((brac_g + brac_d)%2 != 0)){
        return "NO";
    }
    if((par_d != par_g) || (cro_d != cro_g) || (brac_d != brac_g)){
        return "NO";
    }
     char stack[10000];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1)return "NO";
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return "NO";
            }
        }
    }
    return "YES";
}
