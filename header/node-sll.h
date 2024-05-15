#ifndef STACK_SLL_H
#define STACK_SLL_H

#include "ds.h"

// Node
struct Stack_SLL {
	// Address
	Stack_SLL* next = NULL;
	// Data
	ProductData productData;
};

#endif // STACK_SLL_H