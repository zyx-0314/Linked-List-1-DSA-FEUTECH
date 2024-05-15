#ifndef NODE_SLL_H
#define NODE_SLL_H

#include "ds.h"

// Node
struct Node_SLL {
	// Address
	Node_SLL* next = NULL;
	// Data
	ProductData productData;
};

#endif // NODE_SLL_H