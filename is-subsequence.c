bool isSubsequence(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int sidx = 0;
    int tidx = 0;

    if(slen > tlen)
        return false;

    while(sidx < slen && tidx < tlen){
        if(s[sidx] == t[tidx]){
            sidx++;
            tidx++;
        }else
            tidx++;
    }

    return sidx == slen;
}
