int lengthOfLastWord(char* s) {
    int count = 0;
    for(int i = strlen(s)-1; i >= 0; --i) {
        // Find whitespace if there is any at the end of s
        if(count == 0 && isspace(s[i])){
            printf("continue\n");
            continue;
        }

        if(s[i] != ' ')
            ++count;

        if(s[i] == ' ')
            break;
    }

    return count;
}