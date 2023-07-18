/*
 * This simple program checks if the kernel running the testsuite has support
 * for tagged address ABI, needed to test hardware assisted address sanitizer.
 * https://www.kernel.org/doc/html/next/arm64/tagged-address-abi.html
 *
 * The program returns 0 if the kernel supports tagged address ABI.
 */

#include <sys/prctl.h>
int main(void)
{
    return prctl(PR_GET_TAGGED_ADDR_CTRL, 0,0,0,0);
}

