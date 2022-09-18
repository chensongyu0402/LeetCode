int longestPalindrome(char * s)
{
    int len = strlen(s);
    int max = 0;
    if(len == 1)
        return 1;
    int tb[52];
    for(int i = 0; i < 52; i++)
        tb[i] = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] - 'a' >= 0 && s[i] - 'a' <26)
            tb[s[i] - 'a']++;
        else
            tb[s[i] - 'A'+26]++;
    }
    for(int i = 0; i < 52; i++) {
        int p = tb[i] / 2;
        max += p;
    }
    max *= 2;
    for(int i = 0; i < 52; i++) {
        if(tb[i]%2==1) {
            max++;
            break;
        }
    }
    return max;
}