#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stddef.h>

void* kalloc_aligned(size_t size, size_t alignment);
void memset(void* dest, int value, size_t size);

#endif
