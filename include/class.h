#ifndef CLASS_H_
#define CLASS_H_

#include <stdint.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* class access start */
#define PUBLIC
#define PRIVATE static
#define PROTECTED const
/* class access end */

typedef void *Object;
typedef const void *Type;

#define EXTENDS(type) Type type
#define IMPLEMENTS(type) Type type

#define NEW(type, ...) new(Type##type, ##__VA_ARGS__)
#define DELETE(cthis) delete(cthis)

#define CLASS_START(type) Class Class##type = {
#define CLASS_END(type)              \
    };                               \
                                     \
    const Type Type##type = &Class##type

#define INTERFACE_START(type)        \
    typedef struct type type;        \
    struct type {
#define INTERFACE_END(type)          \
    }
#define INTERFACE_DEFINE(type) extern const Type Type##type

#define FUNCTION_PROBE(ptr, name) ptr->name = name
#define FUNCTION_PROBE_BY_NAME(ptr, name, func) ptr->name = func


#define EXECUTE_METHOD(ptr, func, ...) ptr->func(ptr, ##__VA_ARGS__)

PUBLIC INTERFACE_START(Class)
    size_t size;
    Object (*ctor)(Object cthis, va_list *args);
    Object (*dtor)(Object cthis);
INTERFACE_END(Class);

void *new(Type type, ...);
void delete(Object self);

#ifdef __cplusplus
}
#endif

#endif