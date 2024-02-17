        .text
        .globl  clz
        .type   clz, @function


clz:
        testq    %rdi, %rdi
        jnz     L0
        movq     $64, %rax
        ret
L0:     movq     $0, %rsi
        movq     $0xFFFFFFFF00000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L1
        addq     $32, %rsi
        shlq     $32, %rdi
L1:     movq     $0xFFFF000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L2
        addq     $16, %rsi
        shlq     $16, %rdi
L2:     movq     $0xFF00000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L3
        addq     $8, %rsi
        shlq     $8, %rdi
L3:     movq     $0xF000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L4
        addq     $4, %rsi
        shlq     $4, %rdi
L4:     movq     $0xC000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L5
        addq     $2, %rsi
        shlq     $2, %rdi
L5:     movq     $0x8000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L6
        addq     $1, %rsi
L6:     movq     %rsi, %rax
        ret

        .size   clz, .-clz
