#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((used)) __attribute__((visibility ("default")))

char * WASM_EXPORT allocate_test(uint32_t v)
{
    // TOTAL_MEMORY
    size_t n = 33554432;
    char * x = malloc(n);

    for (size_t i = 0; i < n; i++)
    {
        x[i] = v;
    }
    return x;
}

uint32_t WASM_EXPORT test(char * buf, uint32_t size)
{
    uint32_t res = 0;
    for (size_t i = 0; i < size; i++)
    {
        res += (uint32_t)buf[i];
    }
    return res;
}
