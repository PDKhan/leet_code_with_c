int evalRPN(char** tokens, int tokensSize) {
    int top = 0;
    int stack[tokensSize];

    for(int i = 0; i < tokensSize; i++){
        if(strcmp(tokens[i], "+") == 0){
            int num2 = stack[--top];
            int num1 = stack[--top];
            stack[top++] = num1 + num2;
        }else if(strcmp(tokens[i], "-") == 0){
            int num2 = stack[--top];
            int num1 = stack[--top];
            stack[top++] = num1 - num2;
        }else if(strcmp(tokens[i], "*") == 0){
            int num2 = stack[--top];
            int num1 = stack[--top];
            stack[top++] = num1 * num2;
        }else if(strcmp(tokens[i], "/") == 0){
            int num2 = stack[--top];
            int num1 = stack[--top];
            stack[top++] = num1 / num2;;
        }else
            stack[top++] = atoi(tokens[i]);
    }

    return stack[0];    
}