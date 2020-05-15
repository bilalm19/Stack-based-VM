/*
 * A simple interface for user to interact with the application.
 */

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <ctype.h>
#include "stack.h"

#define BUFFER 256
#define ERROR "error"

typedef struct u_interface u_interface;

struct u_interface {
    char user_input[BUFFER];
    stack *i_stack;
};

enum status {
    EXIT,
    LOOP
};

#endif /* USER_INTERFACE_H */
