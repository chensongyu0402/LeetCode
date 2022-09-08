bool isValid(char * s)
{
    char stack[10000];
    int i = 0, j = -1;
    while(i < strlen(s)) {
        if(s[i] == '(' || s[i] =='[' || s[i] == '{') {
            stack[++j] = s[i];
        }
        else if(s[i] == ')') {
            if(j == -1)
                return false;
            if(stack[j] == '(')
                j--;
            else
                return false;
        }
        else if(s[i] == ']') {
            if(j == -1)
                return false;
            if(stack[j] == '[')
                j--;
            else
                return false;
        }
        else if(s[i] == '}') {
            if(j == -1)
                return false;
            if(stack[j] == '{')
                j--;
            else
                return false;
        }
        i++;
    }
    if(j == -1)
        return true;
    else
        return false;
}