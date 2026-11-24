#ifndef RING_BUFFER_H
#define RING_BUFFER_H
#include <stdint.h>
#include <stdbool.h>
#define MAX_BUFFER_SIZE 256

typedef struct {
    uint8_t data[MAX_BUFFER_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

void ring_buffer_init(RingBuffer* rb);
bool ring_buffer_push(RingBuffer* rb, uint8_t byte);
bool ring_buffer_pop(RingBuffer* rb, uint8_t* out_byte);
#endif
