
#include <gtest/gtest.h>
#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
    EXPECT_EQ(String::strlen("hello world"), 11);
    EXPECT_EQ(String::strlen("a"), 1);
}

TEST(StringFunction, strcpy) {
    char result[30];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    String::strcpy(result, "a");
    EXPECT_STREQ(result, "a");

    String::strcpy(result, "");
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[30];

    EXPECT_EQ(String::strncpy(result, "hello", 3), result);
    EXPECT_STREQ(result, "hel");

    String::strncpy(result, "abc", 10);
    EXPECT_STREQ(result, "abc");

    String::strncpy(result, "abc", 0);
    EXPECT_STREQ(result, "");

    String::strncpy(result, "", 5);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
    char result[30] = "hello";

    EXPECT_EQ(String::strcat(result, " world"), result);
    EXPECT_STREQ(result, "hello world");

    String::strcat(result, "");
    EXPECT_STREQ(result, "hello world");

    char empty[30] = "";
    String::strcat(empty, "abc");
    EXPECT_STREQ(empty, "abc");
}

TEST(StringFunction, strncat) {
    char result[30] = "hello";

    EXPECT_EQ(String::strncat(result, "world", 3), result);
    EXPECT_STREQ(result, "hellowor");

    String::strncat(result, "xyz", 0);
    EXPECT_STREQ(result, "hellowor");

    String::strncat(result, "!", 5);
    EXPECT_STREQ(result, "hellowor!");

    char empty[30] = "";
    String::strncat(empty, "abc", 2);
    EXPECT_STREQ(empty, "ab");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
    EXPECT_LT(String::strcmp("", "a"), 0);
    EXPECT_GT(String::strcmp("a", ""), 0);
    EXPECT_EQ(String::strcmp("", ""), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abd", 2), 0);
    EXPECT_LT(String::strncmp("abc", "abd", 3), 0);
    EXPECT_GT(String::strncmp("abd", "abc", 3), 0);
    EXPECT_EQ(String::strncmp("abc", "xyz", 0), 0);
    EXPECT_EQ(String::strncmp("abc", "abcde", 3), 0);
    EXPECT_LT(String::strncmp("", "a", 3), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[30];

    String::reverse_cpy(result, "hello");
    EXPECT_STREQ(result, "olleh");

    String::reverse_cpy(result, "abc");
    EXPECT_STREQ(result, "cba");

    String::reverse_cpy(result, "a");
    EXPECT_STREQ(result, "a");

    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";

    EXPECT_EQ(String::strchr(s, 'e'), s + 1);
    EXPECT_EQ(String::strchr(s, 'l'), s + 2);
    EXPECT_EQ(String::strchr(s, 'x'), nullptr);
    EXPECT_EQ(String::strchr(s, '\0'), s + 5);

    const char *empty = "";
    EXPECT_EQ(String::strchr(empty, '\0'), empty);
}

TEST(StringFunction, strstr) {
    const char *s = "hello world";

    EXPECT_EQ(String::strstr(s, "hello"), s);
    EXPECT_EQ(String::strstr(s, "world"), s + 6);
    EXPECT_EQ(String::strstr(s, "lo"), s + 3);
    EXPECT_EQ(String::strstr(s, "xyz"), nullptr);
    EXPECT_EQ(String::strstr(s, ""), s);

    const char *empty = "";
    EXPECT_EQ(String::strstr(empty, ""), empty);
    EXPECT_EQ(String::strstr(empty, "a"), nullptr);
}

