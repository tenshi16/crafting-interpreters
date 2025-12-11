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

struct Node *search_node(int val, struct Node *target) {
	struct Node *aux = target;
	while(target) {
		if(target->value == val) {
			printf("Node found, exiting search \n");
			return target;
		}
		target = target->next;
	}
}


int main() {
	struct DoubleLinkedList *DBL = malloc(sizeof(struct DoubleLinkedList));

	struct Node *current_node = malloc(sizeof(struct Node));
	for(int i = 0; i<4; i++) {
		printf("i value = %d\n", i);
		struct Node *next_node = malloc(sizeof(struct Node));
		if(i == 0) {
			// Add the first node
			current_node->value = i;
			current_node->prev = NULL;
			current_node->next = next_node;
			DBL->firstNode = current_node;
			current_node = next_node;
			continue;
		}
		if(i == 3) {
			// Add the last node;
			current_node->value = i;
			current_node->next = NULL;
			DBL->lastNode = current_node;
			printf("Memory Add of lastNode %p\n", current_node);
			break;
		} 
		current_node->value = i;
		current_node->next = next_node; 
		next_node->prev = current_node;
		current_node = next_node;
	}

	current_node = DBL->firstNode;

	while (current_node) {
		printf("Value of current node is %d\n", current_node->value);
		current_node = current_node->next;
	};
	

	printf("Search of node #3 starting\n");
	struct Node *searched = search_node(3, DBL->firstNode);

	if(searched == DBL->firstNode) {
		printf("First Node found\n");
	}
	else if(searched == DBL->lastNode) {
		printf("Last Node found\n");
	}
	printf("Memory Add of the found last address %p\n", searched);
	printf("Result Node value = %d\n", searched->value);
	return 0;
}
