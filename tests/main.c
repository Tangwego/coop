#include <stdio.h>
#include "cstring.h"

int main() {
    printf("Hello, World!\n");
    String *str = NEW(String, "test");
    printf("%s\n", str->getString(str));
    str->setString(str, "hello");
    printf("%s\n", str->getString(str));

    EXECUTE_METHOD(str, setString, "hello execute method!\n");
    printf("%s\n", str->getString(str));

    return 0;
}
