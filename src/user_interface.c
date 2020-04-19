#include "user_interface.h"

/*
 * The string can contain garbage values. We do not want this. So, we set
 * all elements of the array to 0/NULL.
 */
void set_clean(char *str)
{
    memset(str, 0, BUFFER);
}

void print_string(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
        printf("%c", str[i]);

    printf("\n");
}

void get_user_input(char *str)
{
    char line[BUFFER];
    set_clean(line);
    set_clean(str);

    char *fp = fgets(line, sizeof(line), stdin);
    if (fp) {
         if (line[strlen(line)-1] != '\n') {
            while (fgets(line, sizeof(line), stdin) &&
                line[strlen(line)-1] != '\n');
            printf("Error!! Input too long\n");
            strncpy(str, ERROR, strlen(ERROR));
            return;
         }
    }

    strncpy(str, line, strlen(line) - 1);
}
