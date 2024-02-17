        .data
         m2 : .quad 0x0F0F0F0F0F0F0F0F
         M1 : .quad 0x00000000000000FF
         M2 : .quad 0x000000000000000F
         M : .quad 0x000000000000FFFF
         S1 : .quad 136
         S2 : .quad 17
        .text
        .globl  mod17
        .type   mod17, @function
        

/*
 * W moim rozwiązaniu używam następującej techniki: korzystam dwa razy ze wskazówki podanej w zadaniu (raz, a potem dla otrzymanego wyniku, który ma maksymalnie 2 znaki w systemie szesnastkowym, stąd tylko jedna różnica). Korzystam też ze stałych podzielnych przez 17, aby niwelować ujemny wynik.
 */

mod17:
        mov     %rdi, %rdx
        and     m2, %rdx
        mov     %rdx, %rcx
        shr     $32, %rcx
        add     %rcx, %rdx
        
        mov     %rdx, %rcx
        shr     $16, %rcx
        add     %rcx, %rdx

        mov     %rdx, %rcx
        shr     $8, %rcx
        and     M1, %rcx
        and     M1, %rdx
        add     %rcx, %rdx

        mov     %rdx, %rax


        mov     %rdi, %rdx
        shr     $4, %rdx
        and     m2, %rdx
        mov     %rdx, %rcx
        shr     $32, %rcx
        add     %rcx, %rdx
        
        mov     %rdx, %rcx
        shr     $16, %rcx
        add     %rcx, %rdx

        mov     %rdx, %rcx
        shr     $8, %rcx
        and     M1, %rcx
        and     M1, %rdx
        add     %rcx, %rdx

        sub     %rdx, %rax

        
        mov     $0, %rdx
        cmp     %rdx, %rax
        cmovl   S1, %rdx
        add     %rdx, %rax

        mov     $0, %rcx
        mov     %rax, %rdx
        and     M2, %rdx
        shr     $4, %rax
        sub     %rax, %rdx
        cmp     %rcx, %rdx
        cmovl   S2, %rcx
        add     %rcx, %rdx
        mov     %rdx, %rax
        ret
