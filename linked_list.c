#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(Node** head, int data) {
    Node* new_node = create_node(data);
    if (!*head) { *head = new_node; return; }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
}

void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void free_list(Node* head) {
    Node* temp;
    while (head) {
        temp = head; head = head->next; free(temp);
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

