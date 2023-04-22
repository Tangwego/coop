#ifndef STRING_H_
#define STRING_H_

#include "class.h"

#ifdef __cplusplus
extern "C" {
#endif

PUBLIC INTERFACE_START(String)
    EXTENDS(Class);
    PUBLIC char * content;
    PUBLIC char *(*getString)(String *);
    PUBLIC void (*setString)(String *, const char *);
INTERFACE_END(String);

#ifdef __cplusplus
}
#endif

#endif