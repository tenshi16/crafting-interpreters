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

void insert_head(struct Node *node, struct Node *original, struct DoubleLinkedList *dbl) {
	node->prev = NULL;
	node->next = original;
	original->prev = node;
	dbl->firstNode = node;
}
void insert_tail(struct Node *node, struct Node *original, struct DoubleLinkedList *dbl) {
	while(original) {
		if(original->next == NULL) {
			original->next = node;
			node->prev = original;
			node->next = NULL;
			dbl->lastNode = node;
		}
		original = original->next;
	}
}
void insert_after(struct Node *target_node, char *value, struct Node *current_node) {
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->value = value;
	while(current_node) {
		if(current_node == target_node) {
			new_node->prev = current_node;
			new_node->next = current_node->next;
			if(current_node->next) {
				current_node->next->prev = new_node;
			}
			current_node->next = new_node;
			break;
		}
		current_node = current_node->next;
	}
}

void insert_before(struct Node *target_node, char *value, struct Node *current_node) {
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->value = value;
	while(current_node) {
		if(current_node == target_node) {
			if(current_node->prev) {
				new_node->prev = current_node->prev;
				current_node->prev->next = new_node;
			}
			current_node->prev = new_node;
			new_node->next = current_node;
			break;
		}
		current_node = current_node->next;
	}
}

void delete_node(struct Node *target_node, struct DoubleLinkedList *dbl) {
	if(target_node->prev) {
		target_node->prev->next = target_node->next;
	} else {
		dbl->firstNode = target_node->next;
	}
	if(target_node->next) {
		target_node->next->prev = target_node->prev;
	} else {
		dbl->lastNode = target_node->prev;
	}
	free(target_node);
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
			next_node->prev = current_node;
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


	/*	while (current_node) {
			printf("Value of current node is %c\n", *current_node->value);
			current_node = current_node->next;
			};
			*/

	/* 
		 Search Test

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
		 */

	// Insert Head Test
	/* struct Node *new_head = malloc(sizeof(struct Node));
		 char *new_string = malloc(2);
		 new_string[0] = '9';
		 new_string[1] = '\0'; 
		 new_head->value = new_string;
		 printf("new head addrs %p\n", new_head);
		 insert_head(new_head, DBL->firstNode, DBL);
		 printf("New Head value is %c\n", *DBL->firstNode->value);
		 */

	//Insert Tail Test
	/* printf("prevous tail addrs %p\n", DBL->lastNode);
		 printf("prevous tail value %c\n", *DBL->lastNode->value);
		 struct Node *new_tail = malloc(sizeof(struct Node));
		 char *new_string = malloc(2);
		 new_string[0] = '9';
		 new_string[1] = '\0'; 
		 new_tail->value = new_string;
		 insert_tail(new_tail, DBL->lastNode, DBL);
		 printf("new tail addrs %p\n", DBL->lastNode);
		 printf("New Tail value is %c\n", *DBL->lastNode->value);
		 */

	// Test Insert After
/*	char *new_string = malloc(2);
	new_string[0] = '9';
	new_string[1] = '\0'; 
	printf("Second node value before insertion %c\n", *DBL->firstNode->next->value);
	printf("Third node value before insertion %c\n", *DBL->firstNode->next->next->value);
	insert_after(DBL->firstNode->next,new_string, DBL->firstNode);
	printf("Second node value after insertion %c\n", *DBL->firstNode->next->value);
	printf("Third node value after insertion %c\n", *DBL->firstNode->next->next->value);

	struct Node *displayNode = DBL->firstNode;
	while (displayNode) {
		printf("Value of current node is %c\n", *displayNode->value);
		displayNode = displayNode->next;
	};
*/

/* char *new_string = malloc(2);
	new_string[0] = '9';
	new_string[1] = '\0'; 
	printf("Second node value before insertion %c\n", *DBL->firstNode->next->value);
	printf("Third node value before insertion %c\n", *DBL->firstNode->next->next->value);
	insert_before(DBL->firstNode->next,new_string, DBL->firstNode);
	printf("Second node value after insertion %c\n", *DBL->firstNode->next->value);
	printf("Third node value after insertion %c\n", *DBL->firstNode->next->next->value);

	struct Node *displayNode = DBL->firstNode;
	while (displayNode) {
		printf("Value of current node is %c\n", *displayNode->value);
		displayNode = displayNode->next;
	};
	*/
	struct Node *displayNode = DBL->firstNode;
	while (displayNode) {
		printf("Value of current node is %c\n", *displayNode->value);
		displayNode = displayNode->next;
	};
	printf("\n\n\n");
	delete_node(DBL->firstNode, DBL);
	struct Node *displayNode2 = DBL->firstNode;
	while (displayNode2) {
		printf("Value of current node is %c\n", *displayNode2->value);
		displayNode2 = displayNode2->next;
	};
	return 0;
}
