foo:
    mov eax, rcx
    add eax, r8
    add eax, r9d
    add eax, dword ptr [rsp + 8]
    ret