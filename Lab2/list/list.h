typedef struct Node {
	int value;
	struct Node *next;
} Node;

void push(Node **head, int data);

int pop(Node **head);

Node* search(Node **head, int data);

int dell(Node **head, int n);

Node* getNth(Node* head, int n);

void printLinkedList(const Node *head);
