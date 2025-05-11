#include "memory.h"

// Set by your bootloader or kernel init code
extern uint8_t* kernel_heap_start;
extern uint8_t* kernel_heap_end;

static uint8_t* heap_curr = NULL;

void init_kernel_heap(uint8_t* start, uint8_t* end) {
    kernel_heap_start = start;
    kernel_heap_end = end;
    heap_curr = start;
}

void* kalloc_aligned(size_t size, size_t alignment) {
    if (!heap_curr) return NULL;

    uintptr_t addr = (uintptr_t)heap_curr;
    if (addr % alignment != 0) {
        addr = (addr + alignment - 1) & ~(alignment - 1); // align up
    }

    if (addr + size > (uintptr_t)kernel_heap_end) {
        return NULL; // outta memory bro 💀
    }

    heap_curr = (uint8_t*)(addr + size);
    return (void*)addr;
}

void memset(void* dest, int value, size_t size) {
    unsigned char* d = (unsigned char*)dest;
    while (size--) {
        *d++ = (unsigned char)value;
    }
}
