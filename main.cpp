#include <stdio.h>
#include <cstdlib>

const int STRSIZE = 1000;

struct s_list {
    int delta;
    char *sym;
    s_list *next;
};

int StrLen (char *str);
struct s_list *StrHandle (char *str, int len, int *sets);
void StrPrint (char *str, struct s_list *s_start);
void StrBruteForce (struct s_list *s_start, int sets, struct s_list *s0, char *str);

int main() {
    char *str = (char *) calloc (STRSIZE, sizeof(char));
    scanf ("%s", str);
    int len = StrLen (str), sets = 0;
    struct s_list *s_start = StrHandle (str, len, &sets);
    StrBruteForce (s_start, sets, s_start, str);
    s_list *ptr = s_start;
    do {
        s_start = ptr;
        ptr = s_start->next;
        free (s_start);
    } while (ptr != nullptr);
    free (str);
    return 0;
}

int StrLen (char *str) {
    int len = 0;
    while (str[len++]);
    return --len;
}

struct s_list *StrHandle (char *str, int len, int *sets) {
    struct s_list *s_start = (struct s_list *) calloc (1, sizeof (struct s_list));
    struct s_list *s0 = s_start;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '[') {
            s_start->sym = (str + i);
            s_start->delta = 1;
            s_start->next = (struct s_list *) calloc (1, sizeof (struct s_list));
            ++*sets;
            int j = 1;
            while (str[i + j++] != ']');
            str[i] = '0' + j;
            s_start = s_start->next;
        }
    }
    return s0;
}

void StrPrint (char *str, struct s_list *s_start) {
    int len = StrLen (str);
    int i = 0;
    if (s_start->next == nullptr) {
        printf("%s\n", str);
        return;
    }
    while ((str + i) < s_start->sym && i < len)
        printf ("%c", str[i++]);
    printf ("%c", *(s_start->sym + s_start->delta));
    StrPrint (str + i + (str[i] - '0'), s_start->next);
    return;
}

void StrBruteForce (struct s_list *s_start, int sets, struct s_list *s0, char *str) {
    if (sets == 0) {
        StrPrint (str, s0);
        return;
    }
    for (int i = 0; i < (*(s_start->sym) - '0') - 2; ++i) {
        s_start->delta += i;
        StrBruteForce (s_start->next, sets - 1, s0, str);
        s_start->delta -= i;
    }
}