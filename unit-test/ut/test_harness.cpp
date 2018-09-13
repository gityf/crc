#include "test_harness.h"

#include <string>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <vector>

namespace common {
    namespace test {
        int errCount = 0;
        namespace {
            struct Test {
                const char* base;
                const char* name;
                void(*func)();
            };
            std::vector<Test>* tests;
        }

        bool RegisterTest(const char* base, const char* name, void(*func)()) {
            if (tests == NULL) {
                tests = new std::vector<Test>;
            }
            Test t;
            t.base = base;
            t.name = name;
            t.func = func;
            tests->push_back(t);
            return true;
        }

        int RunAllTests(const char* matcher) {
            int num = 0;
            if (tests != NULL) {
                for (size_t i = 0; i < tests->size(); i++) {
                    const Test& t = (*tests)[i];
                    if (matcher != NULL) {
                        std::string name = t.base;
                        name.push_back('.');
                        name.append(t.name);
                        if (strstr(name.c_str(), matcher) == NULL) {
                            continue;
                        }
                    }
                    fprintf(stderr, "\033[0;32m[ RUN      ] ==== Test %s.%s\n", t.base, t.name);
                    fprintf(stderr, "\033[0m");
                    (*t.func)();
                    ++num;
                }
            }
            fprintf(stderr, "\033[0;32m[ PASS     ] ==== PASSED %d tests\n", num);
            fprintf(stderr, "\033[0;31m[ NOPASS   ] ==== ERROR %d tests\n", errCount);
            fprintf(stderr, "\033[0m\n");
            return 0;
        }

        std::string TmpDir() {
            return "/tmp";
        }

        int RandomSeed() {
            return 301;
        }
        TestPerfomence::TestPerfomence() {
            startMs_ = NowMs();
        }
        TestPerfomence::TestPerfomence(int size) {
            startMs_ = NowMs();
            fprintf(stderr,
                "\033[0;32m[ RUN      ] ==== start to run %lu cases.\n",
                size);
        }
        TestPerfomence::~TestPerfomence() {
            long endMs = NowMs();
            fprintf(stderr,
                "\033[0;32m[ RUN      ] ==== start at %lu, stop at %lu, cost:[%lu]\n",
                startMs_, endMs, endMs - startMs_);
        }
        long TestPerfomence::NowMs() {
            struct timeval timeNow;
            gettimeofday(&timeNow, NULL);
            return (timeNow.tv_sec) * 1000 + timeNow.tv_usec / 1000;
        }

    }
}  // namespace common

using namespace common::test;
int main(int argc, char** argv) {
    common::test::RunAllTests(NULL);
    return 0;
}
