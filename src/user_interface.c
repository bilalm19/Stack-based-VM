#include "user_interface.h"

int main(void)
{
    if (fgets(line, sizeof(line), stdin)) {
        printf("DAWG: %s\n", line);
    }
}
