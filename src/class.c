#include <malloc.h>
#include <stdarg.h>
#include "class.h"

PUBLIC Object new(Type type, ...)
{
    const Class *class = type;
    Object cthis = calloc(1, class->size);
    *(Class **)cthis = (Class *)class;
    if (class->ctor) {
        va_list vl;
        va_start(vl, type);
        cthis = class->ctor(cthis, &vl);
        va_end(vl);
    }
    return cthis;
}

PUBLIC void delete(Object self)
{
    const Class **cthis = self;
    if (self && *cthis && (*cthis)->dtor) {
        self = (*cthis)->dtor(self);
    }
    free(self);
}
