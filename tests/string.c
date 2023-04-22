#include <stdarg.h>
#include <string.h>
#include <malloc.h>

#include "cstring.h"

PRIVATE char *getString(String *str)
{
    return str->content;
}

PRIVATE void setString(String *str, const char *newcontent)
{
    if(str->content) {
        free(str->content);
    }
    str->content = strdup(newcontent);
}

PRIVATE Object string_ctor(Object cthis, va_list *args)
{
    String *this = cthis;
    const char *content = va_arg(*args, const  char*);
    this->content = strdup(content);
    FUNCTION_PROBE(this, getString);
    FUNCTION_PROBE(this, setString);
    return this;
}

PRIVATE Object string_dtor(Object cthis)
{
    String* this = cthis;
    if(this->content) {
        free(this->content);
        this->content = NULL;
    }
    return this;
}

PRIVATE CLASS(String, string_ctor, string_dtor);