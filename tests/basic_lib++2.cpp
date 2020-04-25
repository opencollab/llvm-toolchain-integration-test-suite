// Test a libc++ issues reported https://bugs.launchpad.net/ubuntu/+source/libc++/+bug/1586215
//
// RUN: %clangxx -stdlib=libc++ -Wall -Werror %s -o %t
// RUN: %t
// REQUIRES: clangxx, libc++

#include <string>
#include <iostream>

int main()
{
    try
    {
        std::string x;
        char z = x.at(2);
        std::cout << z << std::endl;
    }
    catch (...)
    {
    }

    return 0;
}
