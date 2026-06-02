int find(int* start, int* fin, int elt) {
    for (int* p = start; p != fin; ++p) {
        if (*p == elt) {
            return (p - start);
        }
    } 
    return (fin - start);
}