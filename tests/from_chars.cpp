// Test charconv integration, see https://bugzilla.redhat.com/show_bug.cgi?id=1657544
//
// REQUIRES: clang
// RUN: %clangxx %s -o %t
// RUN: %t 100 | grep 100

#include <charconv>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
        size_t r=0;
        const char *begin = argv[1];
        const char *end = begin + strlen(begin);
        from_chars(begin, end, r);
        cout << r << '\n';
        return 0;
}
