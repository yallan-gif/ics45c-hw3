#include "string.hpp"
#include <iostream>

String::String(const char *s) {
    strncpy(buf, s, MAXLEN - 1);
}

String::String(const String &s) {
    strncpy(buf, s.buf, MAXLEN - 1);
}

String::~String() {
}

String &String::operator=(const String &s) {
    if (this != &s)
        strcpy(buf, s.buf);
    return *this;
}

int String::strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int i = strlen(dest);
    int j = 0;
    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int i = strlen(dest);
    int j = 0;
    while (j < n && src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return dest;
}

int String::strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i])
        ++i;
    return static_cast<unsigned char>(s1[i])
         - static_cast<unsigned char>(s2[i]);
}

int String::strncmp(const char *s1, const char *s2, int n) {
    for (int i = 0; i < n; ++i) {
        unsigned char a = static_cast<unsigned char>(s1[i]);
        unsigned char b = static_cast<unsigned char>(s2[i]);
        if (a != b || a == '\0')
            return a - b;
    }
    return 0;
}

void String::reverse_cpy(char *dest, const char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

const char *String::strchr(const char *s, char c) {
    for (int i = 0; ; ++i) {
        if (s[i] == c)
            return s + i;
        if (s[i] == '\0')
            return nullptr;
    }
}

const char *String::strstr(const char *haystack, const char *needle) {
    if (needle[0] == '\0')
        return haystack;

    for (int i = 0; haystack[i] != '\0'; ++i) {
        int j = 0;
        while (needle[j] != '\0' &&
               haystack[i + j] != '\0' &&
               haystack[i + j] == needle[j])
            ++j;
        if (needle[j] == '\0')
            return haystack + i;
    }
    return nullptr;
}

int String::size() const {
    return strlen(buf);
}


char &String::operator[](int index) {
    if (!in_bounds(index)) {
        std::cerr << "ERROR: Index Out Of Bounds\n";
        return buf[0];
    }
    return buf[index];
}

String String::reverse() const {
    String result;
    reverse_cpy(result.buf, buf);
    return result;
}

int String::indexOf(char c) const {
    const char *p = strchr(buf, c);
    return p == nullptr ? -1 : static_cast<int>(p - buf);
}

int String::indexOf(const String &s) const {
    const char *p = strstr(buf, s.buf);
    return p == nullptr ? -1 : static_cast<int>(p - buf);
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const {
    String result(*this);
    result += s;
    return result;
}

String &String::operator+=(const String &s) {
    int len = size();
    int remaining = MAXLEN - 1 - len;

    if (s.size() > remaining)
        std::cerr << "ERROR: String Capacity Exceeded\n";

    strncat(buf, s.buf, remaining);
    return *this;
}

void String::print(std::ostream &out) const {
    out << buf;
}

void String::read(std::istream &in) {
    char temp[MAXLEN];
    in.width(MAXLEN);
    if (in >> temp)
        strcpy(buf, temp);
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}

