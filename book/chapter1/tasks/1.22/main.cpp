template <class T>
T foo() {
    T x = 1;
    return x;
}

int main() {
    int v = foo<int>();
}

