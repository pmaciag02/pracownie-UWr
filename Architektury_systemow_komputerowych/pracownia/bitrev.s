        .text
        .globl  bitrev
        .type bitrev, @function

/*
 * W moim rozwiązaniu używam następującej techniki: najpierw odwracam kolejność bajtów (jak w jednym zadaniu z ćwiczeń), a potem maskami zamieniam pojedyńcze bity parami.
 */

bitrev:
        movq    %rdi, %rax
        rol     $8, %ax
        rol     $16, %eax
        rol     $8, %ax
        shl     $32, %rax
        shr     $32, %rdi
        rol     $8, %di
        rol     $16, %edi
        rol     $8, %di
        orq     %rdi, %rax
        movq    $0xF0F0F0F0F0F0F0F0, %rsi
        movq    %rax, %rdi
        shlq    $4, %rdi
        andq    %rsi, %rdi
        andq    %rsi, %rax
        shrq    $4, %rax
        orq     %rdi, %rax
        movq    $0xCCCCCCCCCCCCCCCC, %rsi
        movq    %rax, %rdi
        shlq    $2, %rdi
        andq    %rsi, %rdi
        andq    %rsi, %rax
        shrq    $2, %rax
        orq     %rdi, %rax
        movq    $0xAAAAAAAAAAAAAAAA, %rsi
        movq    %rax, %rdi
        shlq    $1, %rdi
        andq    %rsi, %rdi
        andq    %rsi, %rax
        shrq    $1, %rax
        orq     %rdi, %rax
        ret



        .size bitrev, .-bitrev
