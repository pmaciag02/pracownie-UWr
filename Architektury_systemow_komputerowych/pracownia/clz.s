        .text
        .globl  clz
        .type   clz, @function

/*
 * W moim rozwiązaniu używam następującej techniki: "wyszukiwanie binarne", tzn. sprawdzam, czy w "pierwszej polowie" liczby (słowa maszynowego) znajdują się
 * jakieś jedynki. Jeśli nie, to ograniczam przedział do drógiej połowy, wpp. w sprawdzanej części są jedynki, więc sprawdzam przedział na lewo. I tak log64 razy.
 * Rozwiązanie działa w log, jednak używa skoków.
 */

clz:
        testq    %rdi, %rdi
        jnz     L0
        movq     $64, %rax
        ret
L0:     movl     $0, %esi
        movq     $0xFFFFFFFF00000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L1
        addl     $32, %esi
        shlq     $32, %rdi
L1:     movq     $0xFFFF000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L2
        addl     $16, %esi
        shlq     $16, %rdi
L2:     movq     $0xFF00000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L3
        addl     $8, %esi
        shlq     $8, %rdi
L3:     movq     $0xF000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L4
        addl     $4, %esi
        shlq     $4, %rdi
L4:     movq     $0xC000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L5
        addl     $2, %esi
        shlq     $2, %rdi
L5:     movq     $0x8000000000000000, %rax
        andq     %rdi, %rax
        testq    %rax, %rax
        jnz     L6
        addl     $1, %esi
L6:     movl     %esi, %eax
        ret

        .size   clz, .-clz
