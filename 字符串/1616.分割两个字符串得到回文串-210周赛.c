
bool isOalindrome(char *a, char *b)
{
    int len = strlen(a);
    int start = 0;
    int end = len - 1;
    while(start < end) {
        if (a[start] == b[end]) {
            start++;
            end--;
        } else {
            break;
        }
    }
    int i = start;
    int j = end;
    while(i < j) {
        if (a[i] == a[j]) {
            i++;
            j--;
        } else {
            break;
        }
    }
    if (i >= j) {
        return true;
    }
    i = start;
    j = end;
    while(i < j) {
        if (b[i] == b[j]) {
            i++;
            j--;
        } else {
            break;
        }
    }
    if (i >= j) {
        return true;
    }
    return false;
}

bool checkPalindromeFormation(char * a, char * b){
    return isOalindrome(a, b) || isOalindrome(b, a);
}