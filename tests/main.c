#include <stdio.h>
#include "cstring.h"

int main() {
    printf("Hello, World!\n");
    String *str = NEW(String, "test");
    printf("%s\n", str->getString());
    str->setString("hello");
    printf("%s\n", str->getString());
    str->setString("hello execute method!");
    printf("%s\n", str->getString());

    DELETE(str);
    return 0;
}
