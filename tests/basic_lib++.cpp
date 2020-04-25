// Test libc++ headers and lib detection
//
// RUN: %clangxx -stdlib=libc++ %s -o %t
// RUN: %t
// ldd %t 2>&1|grep -q  libc++.so.1
// ldd %t 2>&1|grep -q  libc++abi.so.1
// RUN: %clangxx -std=c++11 -stdlib=libc++ %s -o %t
// RUN: %t
// RUN: %clangxx -std=c++14 -stdlib=libc++ %s -o %t
// RUN: %t
// RUN: %clangxx -std=c++17 -stdlib=libc++ %s -o %t
// RUN: %t
// REQUIRES: clangxx, libc++


#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(void) {
    vector<string> tab;
    tab.push_back("the");
    tab.push_back("world");
    tab.insert(tab.begin(), "Hello");

    for(vector<string>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
