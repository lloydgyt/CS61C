#include <stddef.h>
#include <stdbool.h>
#include "ll_cycle.h"

int advance_hare(node **harep) ;

int ll_has_cycle(node *head) {
	// given a linked list, detect if there is cycle
	// we need two pointers - tortoise and hare

	// advance hare, if hare is NULL return acyclic
	// 
	// advance tortoise
	//
	// if hare catch up with tortoise, then a cycle is deteced
	node *tortoise, *hare;
	tortoise = hare = head;
	while (true) {	

		if (advance_hare(&hare) == 1) { 
			// return 1 means we know it's acyclic
			break;
		}
		if (hare == tortoise) {	
			return 1;
		}
		// advance hare by 2 nodes
		// if nothing happen in the process
		// then advance tortoise by 1 node
		tortoise = tortoise->next;
	}
	// return 0 if there is no cycle
	return 0;
}

int advance_hare(node **harep) {
	if (*harep == NULL) {	
		// return 0 to indicate no cycle
		return 1;
	}
	*harep = (*harep)->next;

	if (*harep == NULL) {	
		// return 0 to indicate no cycle
		return 1;
	}
	*harep = (*harep)->next;

	// return 1 for nothing happen
	return 0;
}
