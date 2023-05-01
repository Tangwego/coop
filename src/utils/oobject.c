#include <stdio.h>
#include "oobject.h"

#define MAX_STRING_BUFFER_SIZE (32)

PRIVATE OObject *mthis;

PRIVATE PROTECTED char *object_to_string()
{
    if (mthis) {
        static char buf[MAX_STRING_BUFFER_SIZE];
        snprintf(buf, MAX_STRING_BUFFER_SIZE, "%s@%08x", TYPE_NAME(OObject), mthis);
        return buf;
    }
    return "NULL";
}

PRIVATE Object object_constructor(Object cthis, va_list *args)
{
    mthis = cthis;
    if (mthis) {
        FUNCTION_PROBE_BY_NAME(mthis, toString, object_to_string);
    }
    return mthis;
}

PRIVATE CLASS(OObject, object_constructor, NULL);
