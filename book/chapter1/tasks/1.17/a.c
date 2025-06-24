//  gcc a.c -static -L. -lb -ld

extern int a;
int main() {
    return a;
}