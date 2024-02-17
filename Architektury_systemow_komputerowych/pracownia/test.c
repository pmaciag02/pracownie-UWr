#include <stdio.h>
#include <inttypes.h>


//uint64_t bitrev(uint64_t);
int mod17(uint64_t);

int main() {

    //uint64_t m = 18446744073709551615;
    // uint64_t m = 0x8000000000000000;
    // printf("%016lx\n", m);
    // printf("%016lx\n", bitrev(m));
    // printf("%016lx\n", bitrev(0x0000000000000001));
    // printf("%016lx\n", bitrev(UINT64_MAX));

    // printf("%016lx\n", mod17(1));
    // printf("%ld\n", mod17(1));
    // printf("%016lx\n", mod17(0x4ad8f2));
    // printf("%ld\n", mod17(0x4ad8f2));
    // printf("%016lx\n", mod17(0x4321));
    // printf("%ld\n", mod17(0x4321));
    // printf("%016lx\n", mod17(0x123458));
    // printf("%ld\n", mod17(0x123458));
    // printf("%016lx\n", mod17(0x0101010101010101));
    // printf("%ld\n", mod17(0x0101010101010101));
    

    // printf("%016lx\n", mod17(0x0101010101010101));
    // printf("%ld\n", mod17(0x0101010101010101));
    

    
    printf("%d\n", mod17(18));
    printf("%d\n", 18%17);
    return 0;
}

//gcc -std=c99 test.c clz.s && ./a.out
//gcc -std=c99 test.c bitrev.s && ./a.out
//gcc -std=c99 -no-pie test.c mod17.s && ./a.out
