int romanToInt(char* s) {
    int result = 0;
    int table[128] = {0};

    table['I'] = 1;
    table['V'] = 5;
    table['X'] = 10;
    table['L'] = 50;
    table['C'] = 100;
    table['D'] = 500;
    table['M'] = 1000;

    for(int i = 0; s[i] != '\0'; i++){
        if(table[s[i]] < table[s[i+1]]){
            result += table[s[i+1]] - table[s[i]];
            i++;
        }else
            result += table[s[i]];
    }

    return result;
}
