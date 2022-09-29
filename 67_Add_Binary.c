#define max(a,b) (a > b ? a : b)
char * addBinary(char * a, char * b)
{
    int la = strlen(a), lb = strlen(b);
    int lc = max(la,lb);
    char *c = (char *)malloc(lc + 1);
    c[lc] = '\0';
    int carry = 0;
    for(int i = 0; i < lc; i++) {
        if(la)carry+=a[--la] - '0';
        if(lb)carry+=b[--lb] - '0';
        c[lc - 1 - i] = (carry&1) + '0';
        carry >>= 1;
    }
    if(carry == 1) {
        c = (char*)realloc(c,lc+2);
        for(int i = lc; i >= 0; i--)
            c[i + 1] = c[i];
        c[0] = '1';
    }
    return c;
}