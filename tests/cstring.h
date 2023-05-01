#ifndef TEST_STRING_H_
#define TEST_STRING_H_

#include "class.h"

#ifdef __cplusplus
extern "C" {
#endif

PUBLIC INTERFACE_START(CString)
    EXTENDS(Class);
    PUBLIC char * content;
    PUBLIC char *(*getString)();
    PUBLIC void (*setString)(const char *);
INTERFACE_END(CString);

#ifdef __cplusplus
}
#endif

#endif
