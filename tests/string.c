#include <stdarg.h>
#include <string.h>
#include <malloc.h>

#include "cstring.h"

PRIVATE String *mThisPtr;

PRIVATE char *getString()
{
    return mThisPtr->content;
}

PRIVATE void setString(const char *newcontent)
{
    if(mThisPtr->content) {
        free(mThisPtr->content);
    }
    mThisPtr->content = strdup(newcontent);
}

PRIVATE Object string_ctor(Object cthis, va_list *args)
{
    String *this = cthis;
    const char *content = va_arg(*args, const  char*);
    this->content = strdup(content);
    FUNCTION_PROBE(this, getString);
    FUNCTION_PROBE(this, setString);
    mThisPtr = this;
    return this;
}

PRIVATE Object string_dtor(Object cthis)
{
    String* this = cthis;
    if(this->content) {
        free(this->content);
        this->content = NULL;
    }
    mThisPtr = NULL;
    return this;
}

PRIVATE CLASS(String, string_ctor, string_dtor);
