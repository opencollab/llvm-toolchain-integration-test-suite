// Tests scan-view runs correctly, see https://bugzilla.redhat.com/show_bug.cgi?id=1647130
// REQUIRES: scan-build, scan-view
// RUN: rm -rf %t.out && mkdir %t.out && cd %t.out && rm -rf *
// RUN: %scan-build -o . %clangxx -c %s -o %t
// RUN: %scan-view --no-browser * & WPID=$! && sleep 5 && kill $WPID
int main(int argc, char *argv[]) {
  while (argc--)
    new int();
  return 0;
}
