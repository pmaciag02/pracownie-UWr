#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#define N (sizeof(int32_t) * 8)



// void secret(u_int8_t *to, u_int8_t *from, size_t count) {
//     size_t n = (count + 7) / 8;
//     switch (count % 8) {
//     case 0: do { *to++ = *from++;
//     case 7: *to++ = *from++;
//     case 6: *to++ = *from++;
//     case 5: *to++ = *from++;
//     case 4: *to++ = *from++;
//     case 3: *to++ = *from++;
//     case 2: *to++ = *from++;
//     case 1: *to++ = *from++;
//         } while (--n > 0);
//     }
// }


struct A {
 int8_t a;
 void *b;
 int8_t c;
 int16_t d;
};

struct A2 {
 int8_t a;
 int8_t c;
 int16_t d;
 void *b;
};

struct B {
 uint16_t a;
 double b;
 void *c;
};

struct B2 {
 double b;
 void *c;
 uint16_t a;
};




int main()
{
    // for ( u_int8_t i =2; i< 3; i++ ){
    //     u_int8_t to = 10, from = 0;
    //     secret(&to, &from, i);
    //     printf("%d %d %d \n", i, from, to);
    // }

printf("%ld %ld\n", sizeof(struct A), sizeof(struct A2));
printf("%ld %ld\n", sizeof(struct B), sizeof(struct B2));


// struct A *s = malloc(sizeof(struct A));
// s->a=1;
// s->c=3;
// s->d=4;
// printf("%ld %d\n", sizeof(*s), s[1]);

struct A s;
s.a=1;
s.c=3;
s.d=4;
printf("%ld %hhn\n", sizeof(s), &s.a);
printf("%d\n", 8u);

putchar('\n');
uint32_t x = 17;
 printf("%d\n", x);

    x = (x & 0x55555555) + ((x & 0xAAAAAAAA) >> 1);
    printf("%d\n", x);
    x = (x & 0x33333333) + ((x & 0xCCCCCCCC) >> 2);
    printf("%d\n", x);
    x = (x & 0x0F0F0F0F) + ((x & 0xF0F0F0F0) >> 4);
    printf("%d\n", x);
    x = (x & 0x00FF00FF) + ((x & 0xFF00FF00) >> 8);
    printf("%d\n", x);
    x = (x & 0x0000FFFF) + ((x & 0xFFFF0000) >> 16);
    printf("%d\n", x);

    printf("%d\n", x);

x=13;
int i=0, k=1;
    uint32_t y = (x & (1 << i)) >> i;
    // uint32_t y = (x >> i) & 1;
    x = (y << k) | (x & ~(1 << k));
    printf("%d\n", x);
    return 0;
}