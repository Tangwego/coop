#include <stdio.h>
#include <string.h>
#include "log.h"
#include "cstring.h"
#include "oobject.h"
#include "ostring.h"

#define COOP_TAG "COOP"

#define EXCEPT_STREQ(s1, s2)                          \
    do {                                              \
        if (strcmp(s1, s2) == 0) {                    \
            logi(COOP_TAG, "%s == %s\n", s1, s2);     \
        } else {                                      \
            logi(COOP_TAG, "%s != %s\n", s1, s2);     \
        }                                             \
    } while (0)


int main() {
    log_init();
    logi(COOP_TAG, "simple class test start...\n");
    const char *test_string1 = "test string 1";
    const char *test_string2 = "test string 2";
    CString *str = NEW(CString, test_string1);
    EXCEPT_STREQ(test_string1, str->getString());
    str->setString(test_string2);
    EXCEPT_STREQ(test_string2, str->getString());
    DELETE(str);
    logi(COOP_TAG, "simple class test end...\n");

    logi(COOP_TAG, "object class test start...\n");
    OObject *obj = NEW(OObject);
    logi(COOP_TAG, "the object.toString: %s\n", obj->toString());
    DELETE(obj);
    logi(COOP_TAG, "object class test end...\n");

    logi(COOP_TAG, "string class test start...\n");
    String *string = NEW(String, "hello");
    logi(COOP_TAG, "the string.toString: %s\n", string->toString());
    logi(COOP_TAG, "string is empty: %s\n", string->isEmpty()?"true":"false");
    logi(COOP_TAG, "indexof e: %d\n", string->indexOf('e'));
    logi(COOP_TAG, "last indexof l: %d\n", string->lastIndexOf('l'));
    logi(COOP_TAG, "string length: %d\n", string->length());
    logi(COOP_TAG, "chat at string %d : %c\n", 4, string->charAt(4));
    logi(COOP_TAG, "starts with %s: %s\n", "el", string->startsWith("el")?"true":"false");
    logi(COOP_TAG, "ends with %s: %s\n", "llo", string->endsWith("llo")?"true":"false");
    DELETE(string);
    logi(COOP_TAG, "string class test end...\n");

    log_deinit();
    return 0;
}
