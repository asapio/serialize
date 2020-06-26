
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "serialize.h"

// Uncomment either one of these, or neither if endianness is unknown.
// If both are commented out, this file will generate code
// that is correct, but has no performance optimization
// #define CPU_IS_BIG_ENDIAN       // Routines will be optimized, assuming CPU is big endian
#define CPU_IS_LITTLE_ENDIAN    // Routines will be optimized, assuming CPU is little endian

static inline void ordered_memcpy(uint8_t* p_dest, const uint8_t* p_src, size_t len, bool reverse_order)
{
    // Copy byte wise in case output is an unaligned address
    uint8_t n_dest;
    uint8_t n_src = reverse_order ? len-1 : 0;

    for(n_dest=0; n_dest<len; n_dest++)
    {
        p_dest[n_dest] =  p_src[n_src];

        if (reverse_order)
        {
            n_src--;
        }
        else
        {
            n_src++;
        }
    }
}

uint32_t deserialize_u32_big(uint8_t const * p_in)
{
    uint32_t x = 0;

#if defined(CPU_IS_BIG_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint32_t), false);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint32_t), true);

#else
    x |= p[0] << 24;
    x |= p[1] << 16;
    x |= p[2] <<  8;
    x |= p[3];
#endif

    return x;
}

uint16_t deserialize_u16_little(uint8_t const* p_in)
{
    uint16_t x = 0;

#if defined(CPU_IS_BIG_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint16_t), true);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint16_t), false);

#else
    x |= p[0] <<  8;
    x |= p[1];
#endif

    return x;
}

uint16_t deserialize_u16_big(uint8_t const* p_in)
{
    uint16_t x = 0;

#if defined(CPU_IS_BIG_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint16_t), false);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    ordered_memcpy((uint8_t*)&x, p_in, sizeof(uint16_t), true);

#else
    x |= p[0] <<  8;
    x |= p[1];
#endif

    return x;
}

void serialize_u64_big(uint8_t * p_out, uint64_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint64_t), false);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint64_t), true);

#else
#error "Not implemented yet."
//    p[0] = (uint8_t)((x >> 24) & 0xFF);
//    p[1] = (uint8_t)((x >> 16) & 0xFF);
//    p[2] = (uint8_t)((x >>  8) & 0xFF);
//    p[3] = (uint8_t)((x      ) & 0xFF);
#endif
}

void serialize_u32_big(uint8_t * p_out, uint32_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint32_t), false);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint32_t), true);

#else

    p[0] = (uint8_t)((x >> 24) & 0xFF);
    p[1] = (uint8_t)((x >> 16) & 0xFF);
    p[2] = (uint8_t)((x >>  8) & 0xFF);
    p[3] = (uint8_t)((x      ) & 0xFF);
#endif
}

void serialize_u64_little(uint8_t * p_out, uint64_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint64_t), true);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint64_t), false);

#else
    #error "Needs work"
#endif
}

void serialize_u32_little(uint8_t * p_out, uint32_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint32_t), true);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint32_t), false);

#else
    #error "Needs work"
#endif
}

void serialize_u16_big(uint8_t * p_out, uint16_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint16_t), false);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint16_t), true);

#else
    p[0] = (uint8_t)((x >>  8) & 0xFF);
    p[1] = (uint8_t)((x      ) & 0xFF);
#endif
}

void serialize_u16_little(uint8_t* p_out, uint16_t x)
{
#if defined(CPU_IS_BIG_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint16_t), true);

#elif defined(CPU_IS_LITTLE_ENDIAN)

    // Copy byte wise in case output is an unaligned address
    ordered_memcpy(p_out, (const uint8_t*)&x, sizeof(uint16_t), false);

#else
    #error "Needs work"
#endif
}

