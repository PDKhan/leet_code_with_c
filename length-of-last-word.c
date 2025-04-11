int lengthOfLastWord(char* s) {
    int result;
    int length = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            if(length)
                result = length;
            length = 0;
        }else
            length++;
    }

    if(length)
        return length;
    else
        return result;
}
