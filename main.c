#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Note: Comments are for my own notes, please don't mind them. Thanks!

int main(int argc, char *argv[]) {
	// List here is a pointer and thus means it points to the first node of the list
	List list;
	int key;
	bool checker;
	
	initList(&list);
	list = newList();
	displayList(list);
	checker = insertFront(&list, 1);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertFront(&list, 2);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertRear(&list, 4);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertFront(&list, 6);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertRear(&list, 5);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertRear(&list, 1);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertRear(&list, 9);
	checker ? displayList(list) : printf("Something went wrong");
	checker = insertAt(&list, 8, 10);
	checker ? displayList(list) : printf("Something went wrong or the list hasn't reached to that location yet\n");
	checker = searchItem(list, 8);
	checker ? printf("Key Found\n") : printf("Key not found");
	key = getItem(list, 8);
	(key != -1) ? printf("Key Retrieved: %d\n", key) : printf("Key not found");
	checker = deleteFront(&list);
	checker ? displayList(list) : printf("Something went wrong or linked list is already empty");
	checker = deleteRear(&list);
	checker ? displayList(list) : printf("Something went wrong or linked list is already empty");
	key = deleteAt(&list, 1);
	if(key){
		printf("Node at location %d has been removed\n", key);
		displayList(list);
	}else printf("Something went wrong or linked list is already empty");
	checker = deleteItem(&list, 2);
	checker ? displayList(list) : printf("Something went wrong, key not found or linked list is already empty\n");
	key = deleteAllItem(&list, 1);
	if(key != -1){
		printf("Key/s %d has been removed\n", key);
		displayList(list);
	}else printf("Something went wrong, key not found or linked list is already empty");


// For Insert Sorted Function
//	checker = insertSorted(&list, 4);
//	checker ? displayList(list) : printf("Something went wrong");
//	checker = insertSorted(&list, 5);
//	checker ? displayList(list) : printf("Something went wrong");
//	checker = insertSorted(&list, 10);
//	checker ? displayList(list) : printf("Something went wrong");
//	checker = insertSorted(&list, 6);
//	checker ? displayList(list) : printf("Something went wrong");
//	checker = insertSorted(&list, 2);
//	checker ? displayList(list) : printf("Something went wrong");
	
	free(list);
	return 0;
}
