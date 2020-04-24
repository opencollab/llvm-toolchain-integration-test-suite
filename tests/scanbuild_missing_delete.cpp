// Tests scan-view runs correctly, see https://bugzilla.redhat.com/show_bug.cgi?id=1647130
// REQUIRES: scanbuild, scanview
// RUN: mkdir %t.out
// RUN: %scan-build -o %t.out %clangxx -c %s -o %t
// RUN: timeout 10 %scan-view --no-browser %t.out/*
int main(int argc, char *argv[]) {
  while (argc--)
    new int();
  return 0;
}
