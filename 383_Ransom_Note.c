bool canConstruct(char * ransomNote, char * magazine)
{
    int rl = strlen(ransomNote);
    int ml = strlen(magazine);
    int tb[26];
    for(int i = 0; i < 26; i++)
        tb[i] = 0;
    for(int i = 0; i < rl; i++)
        tb[ransomNote[i] - 'a']++;
    for(int i = 0; i < ml; i++)
        tb[magazine[i] - 'a']--;
    for(int i = 0; i < 26; i++)
        if(tb[i] > 0)
            return false;
    return true;
}