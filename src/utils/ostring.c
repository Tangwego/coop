#include <string.h>
#include <malloc.h>

#include "ostring.h"

PRIVATE String *mthis;

PRIVATE int len = 0;

PRIVATE int string_indexof(int ch)
{
    char *p;
    p = strchr(mthis->value, (char)ch);
    if (p != NULL) {
        return (int)(p - mthis->value);
    }
    return -1;
}

PRIVATE int string_last_indexof(int ch)
{
    char *p;
    p = strrchr(mthis->value, (char)ch);
    if (p != NULL) {
        return (int)(p - mthis->value);
    }
    return -1;
}

PRIVATE boolean string_is_empty()
{
    if (mthis && mthis->value) {
        if (strlen(mthis->value) > 0) {
            return false;
        }
    }
    return true;
}

PRIVATE PROTECTED char *string_to_string()
{
    if (mthis && mthis->value) {
        return mthis->value;
    }
    return "NULL";
}

PRIVATE int string_length()
{
    return len;
}

PRIVATE char string_charat(int index)
{
    if (index >= len) {
        return '\0';
    }
    return mthis->value[index];
}

PRIVATE boolean string_endswith(PROTECTED char *suffix)
{
   char *rel = strstr(mthis->value, suffix);
   if (rel != NULL) {
       if((rel - mthis->value + strlen(suffix)) == len) {
           return true;
       }
   }
   return false;
}

PRIVATE boolean string_startswith(PROTECTED char *prefix)
{
    char *rel = strstr(mthis->value, prefix);
    if (rel != NULL) {
        if(rel - mthis->value == 0) {
            return true;
        }
    }
    return false;
}

PRIVATE Object string_constructor(Object cthis, va_list *args)
{
    mthis = cthis;
    const char *content = va_arg(*args, const  char*);
    mthis->value = strdup(content);
    len = strlen(mthis->value);
    FUNCTION_PROBE_BY_NAME(mthis, toString, string_to_string);
    FUNCTION_PROBE_BY_NAME(mthis, isEmpty, string_is_empty);
    FUNCTION_PROBE_BY_NAME(mthis, indexOf, string_indexof);
    FUNCTION_PROBE_BY_NAME(mthis, lastIndexOf, string_last_indexof);
    FUNCTION_PROBE_BY_NAME(mthis, charAt, string_charat);
    FUNCTION_PROBE_BY_NAME(mthis, length, string_length);
    FUNCTION_PROBE_BY_NAME(mthis, endsWith, string_endswith);
    FUNCTION_PROBE_BY_NAME(mthis, startsWith, string_startswith);
    return mthis;
}

PRIVATE Object string_deconstructor(Object cthis)
{
    String* this = cthis;
    if(this->value) {
        free(this->value);
        this->value= NULL;
    }
    mthis = NULL;
    return this;
}

PRIVATE CLASS(String, string_constructor, string_deconstructor);
