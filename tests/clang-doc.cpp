// Check that clang-doc can be executed in html format and that the output
// contains the expected log messages. The test is executed for all supported
// formats to check that the correct log message is emitted for each format.

// This test exists because in Fedora we packaged clang-doc but some assets were
// missing. See https://bugzilla.redhat.com/show_bug.cgi?id=2443053

// RUN: %clang-doc --format=html --executor=standalone %s | %FileCheck --check-prefix=HTML %s
// RUN: %clang-doc --format=json --executor=standalone %s | %FileCheck --check-prefix=JSON %s
// RUN: %clang-doc --format=md --executor=standalone %s | %FileCheck --check-prefix=MD %s
// RUN: %clang-doc --format=yaml --executor=standalone %s | %FileCheck --check-prefix=YAML %s
// REQUIRES: clang-doc

int main(int argc, char** argv) {
        return 0;
}

// HTML: Emiting docs in html format.
// JSON: Emiting docs in json format.
// MD: Emiting docs in md format.
// YAML: Emiting docs in yaml format.

// CHECK-NEXT: Mapping decls...                          
// CHECK-NEXT: Collecting infos...                       
// CHECK-NEXT: Reducing 1 infos...                       
// CHECK-NEXT: Generating docs...                        
// CHECK-NEXT: Generating assets for docs...

