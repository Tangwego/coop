#include <stdio.h>
#include <string.h>
#include "gtest/gtest-c-api.h"
#include "log.h"
#include "cstring.h"
#include "oobject.h"
#include "ostring.h"

#define COOP_TAG "COOP"

int main(int argc, char **argv)
{
    int ret = 0;
    log_init();
    ret = GTest_Init(argc, argv);
    log_deinit();
    return ret;
}

TEST(TestObject, ObjectClassTest)
{
    OObject *obj = NEW(OObject);
    logi(COOP_TAG, "the object.toString: %s\n", obj->toString());
    DELETE(obj);
}

TEST(TestStringCopy, StringClassTest)
{
    const char *hello = "hello";
    String *string = NEW(String, hello);

    ASSERT_STREQ((char *)string->toString(), (char *)hello);
    ASSERT_FALSE(string->isEmpty());
    ASSERT_TRUE(string->indexOf('h') == 0);
    ASSERT_TRUE(string->lastIndexOf('o') == (string->length() - 1));
    ASSERT_TRUE(string->length() == strlen(hello));
    ASSERT_TRUE(string->charAt(0) == 'h');
    ASSERT_TRUE(string->startsWith("he"));
    ASSERT_TRUE(string->endsWith("llo"));

    DELETE(string);
}