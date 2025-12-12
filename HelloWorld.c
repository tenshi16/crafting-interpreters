#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	struct Node *next;
	char *value;
};

struct DoubleLinkedList {
	struct Node *firstNode;
	struct Node *lastNode;
};

struct Node *search_node(char val, struct Node *target) {
	while(target) {
		if(*target->value == val) {
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
		char *as_string = malloc(2);
		as_string[0] = i + '0';
		as_string[1] = '\0';
		struct Node *next_node = malloc(sizeof(struct Node));
		if(i == 0) {
			// Add the first node
			current_node->value = as_string;
			current_node->prev = NULL;
			current_node->next = next_node;
			DBL->firstNode = current_node;
			current_node = next_node;
			continue;
		}
		if(i == 3) {
			// Add the last node;
			current_node->value = as_string;
			current_node->next = NULL;
			DBL->lastNode = current_node;
			break;
		} 
		current_node->value = as_string;
		current_node->next = next_node; 
		next_node->prev = current_node;
		current_node = next_node;
	}

	current_node = DBL->firstNode;


	while (current_node) {
		printf("Value of current node is %c\n", *current_node->value);
		current_node = current_node->next;
	};
	

	printf("Search of node #3 starting\n");
	char to_search = '3';
	struct Node *searched = search_node(to_search, DBL->firstNode);

	if(searched == DBL->firstNode) {
		printf("First Node found\n");
	}
	else if(searched == DBL->lastNode) {
		printf("Last Node found\n");
	}
	printf("Result Node value = %c\n", *searched->value);

	return 0;
}
