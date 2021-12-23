/* This one uses memory management to make this a bit more interesting */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Trims the amount of characters specified to a given char pointer 
 * from another given char pointer */
void strtrim(void *dest, void *src, int trim_head, int trim_tail)
{
    size_t len = strlen(src);
    int it;
    for (it = 0; it < len - (trim_tail+1); it++)
        ((char *)dest)[it] = ((char *)src)[it+trim_head];
}

int is_palindrome(char *str)
{
    size_t len = strlen(str);
    int check = 0;
    char *inner_str = NULL;

    if (len <= 1)
        return 1;

    check = str[0] == str[len - 1];
    inner_str = (char *) malloc(sizeof(char) * (len - 2));
    strtrim(inner_str, str, 1, 1);
    check *= is_palindrome(inner_str);
    free(inner_str);
    inner_str = NULL;
    return check;
}

void check_palindrome(char *str)
{

    printf("The word %s %s palindrome\n",
           str, (is_palindrome(str) ? "is" : "isn't"));

}

int main(int argc, char **argv)
{
    char *str = (argc == 2) ? argv[1] : "";
    is_palindrome(str);
    is_palindrome("rotor");
    is_palindrome("banana");
    return (0);
}
