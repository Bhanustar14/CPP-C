#include "ring_buffer.h"

void ring_buffer_init(RingBuffer* rb) {
    rb->head = 0; rb->tail = 0; rb->count = 0;
}

bool ring_buffer_push(RingBuffer* rb, uint8_t byte) {
    if (rb->count == MAX_BUFFER_SIZE) return false;
    rb->data[rb->head] = byte;
    rb->head = (rb->head + 1) % MAX_BUFFER_SIZE;
    rb->count++;
    return true;
}

bool ring_buffer_pop(RingBuffer* rb, uint8_t* out_byte) {
    if (rb->count == 0) return false;
    *out_byte = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % MAX_BUFFER_SIZE;
    rb->count--;
    return true;
}
