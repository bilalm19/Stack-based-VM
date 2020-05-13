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

void free_interface_memory(u_interface *user_i)
{
    free_stack(user_i->i_stack);
    free(user_i);
}

/*
 * User selects which option to take, and enters a number if option is
 * to add.
 */
void interface(void)
{
    u_interface *user_i = malloc(sizeof(u_interface));
    user_i->i_stack = initialize_stack();

    enum status c_status = LOOP;
    while(c_status) {
        printf("0 to exit\n");
        printf("1 to push to top\n");
        printf("2 to pop top\n");
        printf("3 to add top two\n");
        printf("4 to Duplicate top\n");
        printf("5 to print top\n");
        printf("6 to print stack\n");

        get_user_input(user_i->user_input);
        switch(user_i->user_input[0]) {
            case 48:
                c_status = EXIT;
                break;
            case 49:
                break;
            case 50:
                break;
            case 51:
                break;
            case 52:
                break;
            case 53:
                break;
            case 54:
                break;
        }
        printf("\n");
    }

    printf("Exiting...\n");
    free_interface_memory(user_i);
}
