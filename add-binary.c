char* addBinary(char* a, char* b) {
    int carry = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);
    int max_len = (a_len > b_len ? a_len : b_len) + 1;
    int i = a_len - 1;
    int j = b_len - 1;
    int pos = max_len - 1;
    char* result = (char*)calloc(max_len, max_len);

    while(i >= 0 || j >= 0 || carry){
        int sum = carry;

        if(i >= 0)
            sum += a[i--] - '0';
        
        if(j >= 0)
            sum += b[j--] - '0';

        result[pos--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    return &result[pos + 1];
}
