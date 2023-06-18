#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Note: Comments are for my own notes, please don't mind them. Thanks!

void initList(List *list);
List newList();
NodeType createNode(DATA data);
void displayList(List list);
bool insertFront(List *list, DATA item);
bool insertRear(List *list, DATA item);
bool insertAt(List *list, DATA item, int loc);
bool insertSorted(List *list, DATA data);
bool searchItem(List list, DATA key);
int getItem(List list, DATA key);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAt(List *list, int loc);
bool deleteItem(List *list, DATA key);
int deleteAllItem(List *list, DATA key);

/* List params here is a double pointer
*
	List is a datatype pointer
*	@params = &list; // Please refer to the function call
*
*/
void initList(List *list){
	*list = NULL;
};

List newList(){
	List list;
	
	list = NULL;
	
	return list;
};

void displayList(List list){
	NodePtr head, current;

	if(!list){
		printf("Linked list is empty.\n");
		return;
	}	
	
	head = list;
	current = head;
	
	printf("Traversing the linked list now\n");
	while(current != NULL){
		printf("Data: %d\n", current->data);
		current = current->next;
	}
};

/* List params here is a double pointer
*
	@params = &list; // Please refer to the function call
	@params = int // any int value
*
*/
bool insertFront(List *list, DATA item){
	NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
	
	if(!newNode) return false;
	
	newNode->data = item;
	newNode->next = NULL;
	
	newNode->next = *list;
	*list = newNode;
	
	return true;
};

/* List params here is a double pointer
*
	@params = &list; // Please refer to the function call
	@params = int // any int value
*
*/
bool insertRear(List *list, DATA item){
	NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
	
	if(!newNode) return false;
	
	newNode->data = item;
	newNode->next = NULL;
	
	if(*list){
		NodePtr head = *list;
		
		while(head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
	}else {
		newNode->next = *list;
		*list = newNode;
	}
	
	return true;
	
};
/* List params here is a double pointer
*
	@params = &list; // Please refer to the function call
	@params = int // any int value
	@params = int // any int value as to where to put data
*
*/
bool insertAt(List *list, DATA item, int loc){
	NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
	
	if(!newNode) return false;
	
	newNode->data = item;
	newNode->next = NULL;
	
	if(*list){
		NodePtr head = *list;
		// i is used for counting nodes, this is used for loc
		int i = 1, previousNodeCount = loc - 1;
		
		while(head->next != NULL && i != previousNodeCount){
			head = head->next;
			i++;
		}
		
		if(i == previousNodeCount) {
			newNode->next = head->next;
			head->next = newNode;
		}else return false;
		
	}else{
		newNode->next = *list;
		*list = newNode;
	}
	
	return true;
};

/* List params here is a double pointer
*
	@params = &list; // Please refer to the function call
	@params = int // any int value
	
	// Assuming this function will be used on a sorted linked list due to its function name
*
*/
bool insertSorted(List *list, DATA data){
	NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
	
	if(!newNode) return false;
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(*list) {
		NodePtr head = *list;
		
		// If the head node is greater than new node
		if(head->data > newNode->data){
			newNode->next = head;
			*list = newNode;
			
			return true;
		}
		
		// For nodes in between, study to fully understand it
		while(head->next != NULL && head->next->data < newNode->data){
			head = head->next;
		}
		
		newNode->next = head->next;
		head->next = newNode;
	
	}else {
		newNode->next = *list;
		*list = newNode;
	}
	
	return true;
};

bool searchItem(List list, DATA key){
	bool checker;
	NodePtr head = list;
	
	while(head != NULL && head->data != key) {
		head = head->next;
	}
	
	if(head == NULL) {
		return false;
	}else if(head->data == key) {
		return true;
	}
};

int getItem(List list, DATA key){
	NodePtr head = list;
	
	while(head != NULL && head->data != key) {
		head = head->next;
	}
	
	if(head == NULL) {
		return -1;
	}else if(head->data == key) {
		return key;
	}
};

bool deleteFront(List *list){
	if(!*list) return false;
	
	NodePtr head = *list;
	
	head = head->next;
	free(*list);
	*list = head;
	
	return true;
};

bool deleteRear(List *list){
	if(!*list) return false;
	
	NodePtr head = *list;
	
	while(head->next->next != NULL){
		head = head->next;
	}
	
	free(head->next);
	head->next = NULL;
	
	return true;
};

int deleteAt(List *list, int loc){
	if(!*list) return 0;
	
	NodePtr head = *list, temp = head;
	int i = 1, previousNodeCount = loc - 1;
	
	// When location is first
	if(loc == 1) {
		*list = head->next;
		free(head);
		
		return loc;
	}
	
	while(head->next != NULL && i != previousNodeCount) {
		head = head->next;
		i++;
	}
	
	if(i == previousNodeCount) {
		temp = head->next->next;
		free(head->next);
		head->next = temp;
	}
	
	return loc;
};

bool deleteItem(List *list, DATA key){
	if(!*list) return false;
	
	NodePtr head = *list, temp = head;
	
	// If the key is the first node
	if(head->data == key){
		temp = head->next;
		free(*list);
		*list = temp;
		
		return true;
	}
	
	while(head->next != NULL && head->next->data != key){
		head = head->next;
	}
	
	if(head->next == NULL) return NULL;
	else if(head->next->data == key){
		temp = head->next->next;
		free(head->next);
		head->next = temp;
	}
	
	return true;
};

int deleteAllItem(List *list, DATA key){
	if(!*list) return -1;
	
	NodePtr head = *list;
	int deleteCounter = 0;
	
	// For suceeding equivalent nodes starting from the first node
	while(head != NULL && head->data == key){
		*list = head->next;
		free(head);
		head = *list;
		deleteCounter++;
	}
	
	// For equivalant in between
	if(!head) return deleteCounter;
	
	NodePtr prev = head; 
	head = head->next;
	while(head != NULL){
		if(head->data == key){
			prev->next = head->next;
			free(head);
			head = prev->next;
			deleteCounter++;
		}else {
			prev = head;
			head = head->next;
		}
	}
	
	return deleteCounter ? key : -1;
};
