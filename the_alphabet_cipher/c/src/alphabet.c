#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "alphabet.h"

char *encode(char *key, char *msg)
{
    char *s = strdup(msg);

    for (char *c = s, *k = key; *c != '\0'; c++, k = *(k + 1) == '\0' ? key : k + 1)
        *c = tolower(((toupper(*k) - 'A') + (toupper(*c) - 'A')) % 26 + 'A');

    return s;
}

char *decode(char *key, char *str)
{
    char *s = strdup(str);

    for (char *c = s, *k = key; *c != '\0'; c++, k = *(k + 1) == '\0' ? key : k + 1)
        *c = tolower((26 + (toupper(*c) - 'A') - (toupper(*k) - 'A')) % 26 + 'A');

    return s;
}

char *dechiper(char *msg, char *str)
{
    if (strlen(msg) != strlen(str))
        return NULL;

    char *key = strdup(str);

    for (char *c = str, *m = msg, *k = key; *c != '\0'; c++, k++, m++)
        *k = tolower((26 + (toupper(*c) - 'A') - (toupper(*m) - 'A')) % 26 + 'A');

    int len = strlen(msg);

    for (int i = 1; i < len; i++)
    {
        int is_valid = 1;
        for (int j = i; j < len && is_valid; j++)
            is_valid = key[j % i] == key[j];

        if (is_valid)
        {
            key[i] = '\0';
            break;
        }
    }

    return key;
}
