#ifndef __SERIALIZE_H__
#define __SERIALIZE_H__

// Serialize / Deserialize routines

// Helper functions for common byte manipulations in serial communications routines

// Allows for byte arrays to start at unaligned addresses

// Does not allow for overlapping memory locations between inputs and outputs

#include <stdint.h>

void serialize_u64_big    (uint8_t* p, uint64_t x);
void serialize_u64_little (uint8_t* p, uint64_t x);
void serialize_u32_big    (uint8_t* p, uint32_t x);
void serialize_u32_little (uint8_t* p, uint32_t x);
void serialize_u16_big    (uint8_t *p, uint16_t x);
void serialize_u16_little (uint8_t* p, uint16_t x);

uint16_t deserialize_u16_little (uint8_t const* p);
uint16_t deserialize_u16_big    (uint8_t const* p);
uint32_t deserialize_u32_big    (uint8_t const* p);

#endif //__SERIALIZE_H__
