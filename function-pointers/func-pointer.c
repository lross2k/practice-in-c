/* Using function pointers to call the same 
 * speak() function with different modifiers 
 * to the message */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void speak(void (*func)(char*), char *message);
void to_lower(char *letter);
void to_upper(char *letter);
void shout(char *message);
void broken(char *message);

int main(void)
{
    /* Function pointers */
    void (*func_ptr)(char*) = &shout;
    void (*brk_ptr)(char *) = &broken;

    /* String using char[] */
    char msg[] = "Usar f1(func) esta sobrevalorado";

    /* String using malloc */
    char *msg2 = malloc(256);
    strcpy(msg2,"A bueno di si");

    /* Using NULL equals to no modifier */
    speak(NULL, msg);
    speak(func_ptr, msg);
    speak(NULL, msg2);
    speak(brk_ptr, msg2);

    free(msg2);
    msg2 = NULL;
    return 0;    
}

void speak(void (*func)(char*), char *message)
{
    if (func)
    {
    char *msg_cp = (char*) malloc(sizeof(char) * (strlen(message) + 1));
    strcpy(msg_cp, message);
    func(msg_cp);
    printf("%s\n",msg_cp);
    /*printf("%s\n", *(*func)(message));*/
    free(msg_cp);
    msg_cp = NULL;
    return;
    }
    printf("%s\n",message);
}

void to_lower(char *letter)
{
    if (*letter >= 65 && *letter <= 90)
        *letter ^= (1 << 5); 
}

void to_upper(char *letter)
{
    if (*letter >= 97 && *letter <= 122)
        *letter ^= (1 << 5); 
}

void shout(char *message)
{
    int i = 0;
    for (i = 0; i < strlen(message); i++)
        to_upper(&message[i]);
}

void broken(char *message)
{
    /* random number generator */
    time_t t;
    srand((unsigned) time(&t));
    /* 50% chance to switch the case of every literal given */
    int random_num;
    int i = 0;
    for (i = 0; i < strlen(message); i++)
    {
    random_num = rand() % 10;
        char letter = message[i];
        if ((random_num >= 5)*(
             (letter >= 97 && letter <= 122) || 
             (letter >= 65 && letter <= 90)))
            message[i] ^= (1 << 5);
    }
}

