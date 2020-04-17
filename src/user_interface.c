#include "user_interface.h"

void get_user_input(void)
{
    if (fgets(line, sizeof(line), stdin)) {
        printf("DAWG: %s\n", line);
    }
}
