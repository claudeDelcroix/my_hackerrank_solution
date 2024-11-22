void separateNumbers(char* s) {
    int len = strlen(s);
    if(len == 1){
        printf("NO\n");
        return;
    }
    
    for(int i = 1;i <= len /2 ;i++){
        char t[32];
        strncpy(t,s,i);
        t[i] = '\0';
        long long firstNum = atoll(t);
        
        char tempStr[1024];
        snprintf(tempStr,sizeof(tempStr),"%lld",firstNum);
        long long nextNum = firstNum + 1;
        while(strlen(tempStr) < len){
            char buffer[32];
            snprintf(buffer,sizeof(buffer),"%lld",nextNum);
            strcat(tempStr,buffer);
            nextNum++;
        }
        
        if(strcmp(tempStr,s) == 0){
            printf("YES %lld\n",firstNum);
            return;
        }
    }
    printf("NO\n");
}

//the C++ solution
void separateNumbers(string s) {
    int bl = 1;
    bool f = false;
    while(bl * 2 <= s.size()){
        string base = s.substr(0, bl);
        string newString = "";
        long baselong = atol(base.c_str());
        do{
            newString += to_string(baselong);
            baselong++;
        }while(newString.size() < s.size());
        if(newString == s) {cout << "YES " << base;f = true;break;}
        bl++;
    }
    if(!f) cout << "NO";
    cout << endl;
}





void separateNumbers(string s) {
    int size = s.size();
    for (int i = 1; i <= size / 2; i++) {
        string t = s.substr(0, i);
        string n = t;
        long long count = stoll(t);
        while (t.size() < size) {
            count++;
            t += to_string(count);
        }
        if (t == s) {
            cout << "YES " << n << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

//Python solution 
def match(s, sub) -> bool:
    if len(s) == 0:
        return True
    
    expected = sub + 1
    actual = int(s[: len(str(expected))])
    
    if actual == expected:
        return match(s[len(str(expected)):], expected)
    return False
    
def separateNumbers(s):
    # Write your code here
    if len(s) <= 1:
        return print("NO")

    found = False
    sub = 0
    for i in range(int(math.ceil(len(s)/2))):
        sub = int(s[:i+1])
        found = match(s[i+1:], sub)
        if found:
            break
    
    print('YES ' + str(sub) if found else 'NO'
