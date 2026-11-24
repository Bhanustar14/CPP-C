#include <stdio.h>
#include "ring_buffer.h"
#include "linked_list.h"

int main() {
    RingBuffer rb;
    ring_buffer_init(&rb);
    ring_buffer_push(&rb, 0xAA);
    ring_buffer_push(&rb, 0xBB);
    uint8_t val;
    ring_buffer_pop(&rb, &val);
    printf("Popped: 0x%X\n", val);

    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    print_list(head);
    reverse_list(&head);
    print_list(head);
    free_list(head);
    return 0;
}
