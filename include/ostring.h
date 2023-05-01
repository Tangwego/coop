#ifndef _STRING_H_
#define _STRING_H_

#include "otypes.h"
#include "oobject.h"

#ifdef __cplusplus
extern "C" {
#endif

PUBLIC INTERFACE_START(String)
        EXTENDS(OObject);
        PUBLIC char *value;
        PROTECTED char *(*toString)();
        PUBLIC int (*indexOf)(int ch);
        PUBLIC int (*lastIndexOf)(int ch);
        PUBLIC char (*charAt)(int index);
        PUBLIC boolean (*endsWith)(PROTECTED char *suffix);
        PUBLIC int (*length)();
        PUBLIC boolean (*equals)(Object obj);
        PUBLIC boolean (*isEmpty)();
        PUBLIC boolean (*startsWith)(PROTECTED char *prefix);
INTERFACE_END(String);

#ifdef __cplusplus
}
#endif

#endif