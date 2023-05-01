#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "class.h"

#ifdef __cplusplus
extern "C" {
#endif

PUBLIC INTERFACE_START(OObject)
    EXTENDS(Class);
    PROTECTED char *(*toString)();
INTERFACE_END(OObject);

#ifdef __cplusplus
}
#endif

#endif