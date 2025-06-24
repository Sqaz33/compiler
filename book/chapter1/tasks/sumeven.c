#include <stdio.h>

int sumeven(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() { 
    puts("Hi");
}


/*

clang -O2 -emit-llvm -S -mllvm --print-after-all sumeven.c >& all.log
grep  "\*\*\*" all

ar x libc.a
ar cr libc.a *
*/