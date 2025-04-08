bool isValid(char* s) {
    int len = strlen(s);
    int top = 0;
    char stack[len];

    for(int i = 0; i < len; i++){
        if(s[i] == ')'){
            if(top == 0 || stack[top-1] != '(')
                return false;
            
            top--;
        }else if(s[i] == '}'){
            if(top == 0 || stack[top-1] != '{')
                return false;
            
            top--;
        }else if(s[i] == ']'){
            if(top == 0 || stack[top-1] != '[')
                return false;
            
            top--;
        }else
            stack[top++] = s[i];
    }

    return top == 0;
}
