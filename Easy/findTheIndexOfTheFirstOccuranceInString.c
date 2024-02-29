int strStr(char* haystack, char* needle) {
    for (int i = 0; i < strlen(haystack); ++i) {
        int tmp = i;
        bool found = true;
        for (int j = 0; j < strlen(needle); ++j) {
            if (haystack[i++] != needle[j])
                found = false;
            if (i > strlen(haystack))
                break;
        }
        i = tmp;
        if (found)
            return i;
    }

    return -1;
}