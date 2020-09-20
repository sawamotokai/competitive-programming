#include<stdio.h>

static char *next = NULL;

int isSpace(char c) {
    if (c == ' ' || c == '\t' || c == '\n') return 1;
    return 0;
}
// replace all sapce char before a good char
char *custom_strtok(char *str) {
    if (str != NULL) next = str;
    char *ret = next;
    int i = 0;
    while (next && next[i] != '\0') {
        if (isSpace(next[i])) {
            next[i] = '\0';
            next = next+i+1;
            return ret;
        }
        i++;
    }
    next = NULL;
    return ret;
}


int main () {
    signed char c = 0x8b;
    signed int i = c;
    printf("%d\n", i);
}