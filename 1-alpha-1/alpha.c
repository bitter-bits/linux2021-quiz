#include <stdio.h>

#include <stdint.h>

#define __DECLARE_ROTATE(bits, type)                   \
    static inline type rotl##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v << c) | (v >> (bits - c));           \
    }                                                  \
                                                       \
    static inline type rotr##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v >> c) | (v << (bits - c));           \
    }

#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)

DECLARE_ROTATE(64);

int main(void)
{
    int n = 7;
    int m = rotl64(n, 2);
    printf("%d -> %d\n", n, m);

    int q = rotr64(n, 1);
    printf("%d -> %d\n", n, q);

    return 0;
}
