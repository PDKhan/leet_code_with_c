char* simplifyPath(char* path) {
    int len = strlen(path);
    int top = 0;
    char* stack[len];
    char* str = strtok(path, "/");
    char* result = (char*)calloc(len+1, 1);

    while(str){
        if(strcmp(str, "..") == 0){
            if(top > 0)
                top--;
        }else if(strcmp(str, ".") == 0);
        else
            stack[top++] = strdup(str);

        str = strtok(NULL, "/");
    }

    strcat(result, "/");

    for(int i = 0; i < top; i++){
        char* s = stack[i];
        strcat(result, s);

        if(i < top - 1)
            strcat(result, "/");

        free(s);
    }

    return result;
}
