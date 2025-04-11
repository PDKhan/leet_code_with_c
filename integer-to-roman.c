char* intToRoman(int num) {
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    char* result = (char*)malloc(20);

    memset(result, 0, 20);

    for(int i = 0; i < 13; i++ ){
        if(num >= value[i]){
            strcat(result, symbol[i]);
            num -= value[i];
            i--;
        }
    }

    return result;
}
