#ifndef STRING_HPP
#define STRING_HPP

#include <iosfwd>

constexpr int MAXLEN = 1024;

class String {
public:

private:
    char buf[MAXLEN];

public:
    explicit String(const char *s = "");
    String(const String &s);
    ~String();

    String &operator=(const String &s);

    char &operator[](int index);
    int size() const;
    bool in_bounds(int index) const {
    return index >= 0 && index < strlen(buf);
	}

    String reverse() const;
    int indexOf(char c) const;
    int indexOf(const String &s) const;

	bool operator==(const String &s) const;
    bool operator!=(const String &s) const;
    bool operator<(const String &s) const;
    bool operator>(const String &s) const;
    bool operator<=(const String &s) const;
    bool operator>=(const String &s) const;

    String operator+(const String &s) const;
    String &operator+=(const String &s);

    void print(std::ostream &out) const;
    void read(std::istream &in);

    static int strlen(const char *s);
    static char *strcpy(char *dest, const char *src);
    static char *strncpy(char *dest, const char *src, int n);
    static char *strcat(char *dest, const char *src);
    static char *strncat(char *dest, const char *src, int n);
    static int strcmp(const char *s1, const char *s2);
    static int strncmp(const char *s1, const char *s2, int n);
    static void reverse_cpy(char *dest, const char *src);
    static const char *strchr(const char *s, char c);
    static const char *strstr(const char *haystack, const char *needle);
};

std::ostream &operator<<(std::ostream &out, const String &s);
std::istream &operator>>(std::istream &in, String &s);

#endif

