#include <stdio.h>
#include "list.h"

int main()
    {
        Node* head = NULL;

        push(head, 5);
        push(head, 3);
        push(head, 2);
        push(head, 7);
        push(head, 9);

        printLinkedList(head);

        dell(head, 4);

        printLinkedList(head);

        Node* finded;
        finded = search(head, 9);
        printf("%d\n", finded->value);


        return 0;
    }