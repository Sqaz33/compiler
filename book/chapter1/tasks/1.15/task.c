/*
foo:
    test esi, esi
    jle .L4
    mov rax, rdi
    lea edx, -1[rsi]
    lea rsi, 4[rdi+rdx*4]
    mov ecx, 0

.L3:
    add ecx, DWORD PTR [rax]
    mov DWORD PTR [rax], ecx
    add rax, 4
    cmp rax, rsi
    jne .L3

.L1:
    mov eax, ecx
    ret

.L4:
    mov ecx, 0
    jmp .L1
*/

int* prefix_sum(int* /*rdi*/ x, int /*rsi*/ y) {
    int sum = 0; 
    if (y >= 0) {
        int* t1 = x;             // rax
        int t2 = y - 1;         // edx
        int* t3 = (x + t2 * 4) + 4;   

        do {
            sum += *t1;
            *t1 = sum;
            t1 += 4;
        } while (t1 != t3);

    }
    return sum;
}
