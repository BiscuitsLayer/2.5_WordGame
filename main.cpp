#include <stdio.h>
#include <cstdlib>
#include <ctype.h>

const int STRSIZE = 1000;

char CharHash (int SetNum, int idx);

int StrLen (char *str);
int StrHandle (char *str);
void StrPrint (char *str);

int main() {
    char *str = (char *) calloc (STRSIZE, sizeof(char));
    scanf ("%s", str);
    StrHandle (str);
    StrPrint(str);
    return 0;
}

char CharHash (int SetNum, int idx) {

}

int StrLen (char *str) {
    int len = 0;
    while (str[len++]);
    return --len;
}

int StrHandle (char *str) {
   int len = StrLen(str);
   int sets = 0;
   for (int i = 0; i < len; ++i) {
       if (str[i] == '[') {
           ++sets;
           int j = 1;
           while (str[i + j] != ']')
               ++j;
           str[i] = '0' + j;
       }
   }
   return sets;
}

void StrPrint (char *str) {
    int len = StrLen(str);
    for (int i = 0; i < len; ++i) {
        while (isalpha(str[i]) && i < len)
            printf("%c", str[i++]);
        //CharHash();
        if (i < len)
            i += str[i] - '0';
    }
}