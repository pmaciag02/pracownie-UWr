#include <stdio.h>
#include <stdlib.h>




int clz(u_int64_t x)
{
    if(x == 0)
    {
        return 64;
    }

    u_int64_t n = 0;

    if((x & 0xFFFFFFFF00000000) == 0){n+=32; x<<=32;}
    if((x & 0xFFFF000000000000) == 0){n+=16; x<<=16;}
    if((x & 0xFF00000000000000) == 0){n+=8; x<<=8;}
    if((x & 0xF000000000000000) == 0){n+=4; x<<=4;}
    if((x & 0xC000000000000000) == 0){n+=2; x<<=2;}
    if((x & 0x8000000000000000) == 0) n+=1;

    return n;
}



int main()
{

    u_int64_t x;

    //scanf("%ld", &x);

    //printf("%d\n", clz(x));
    printf("%lu\n", __UINT64_MAX__);


    return 0;
}