#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	struct Node *next;
	int value;
};

struct DoubleLinkedList {
	struct Node *firstNode;
	struct Node *lastNode;
};

int main() {
	struct DoubleLinkedList *DBL = malloc(sizeof(struct DoubleLinkedList));

	struct Node *node = malloc(sizeof(struct Node));
	for(int i = 0; i<=3 ;i++) {
		if(i == 0) {
			// Add the first node
			node->prev = NULL;
			node->value = i;
			DBL->firstNode = node;
		}
    struct Node *next = malloc(sizeof(struct Node));
		node->next = next; 
		if(i == 3) {
			// Add the last node;
			node->next = NULL;
			DBL->lastNode = node;
		}
		node->value = i;
		next->prev = node;
		node = next;
	}

	node = DBL->firstNode;

	while(node->next) {
		printf("Value of current node is %d\n", node->value);
		node = node->next;
		if (node->next == NULL) {
			printf("Last Node Printed\n");
		}
	}

	printf("Hello, World!\n");
	return 0;
}
