#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(Node **head, int data){
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    if(head)
    tmp->next = (*head);
    (*head) = tmp;
};

int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

Node* search(Node **head, int data){
    while(head != NULL){
        if( (*head)->value && (*head)->value == data)
            return (Node *) head;
        else
            head = (Node **) (*head)->next;
    }
    return NULL;
};

int dell(Node **head, int n){
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
};


Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
};

void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
