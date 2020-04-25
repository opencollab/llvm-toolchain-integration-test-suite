// Tests scan-view runs correctly, see https://bugzilla.redhat.com/show_bug.cgi?id=1647130
// REQUIRES: scan-build, scan-view
// RUN: mkdir %t.out && cd %t.out && rm -rf *
// RUN: %scan-build -o . %clangxx -c %s -o %t
// It's not super satisfying to call sh like this, and not portable on windows.
// Yet that's the only I found to cope with the lack of support for '&' in lit.
// RUN: sh -c "%scan-view --no-browser * & WPID=$! && sleep 5 && kill $WPID"
int main(int argc, char *argv[]) {
  while (argc--)
    new int();
  return 0;
}
