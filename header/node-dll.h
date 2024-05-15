#ifndef QUEUE_DLL_H
#define QUEUE_DLL_H

#include "ds.h"

// Node
struct Queue_DLL {
	// Address
	Queue_DLL* next = NULL;
	Queue_DLL* prev = NULL;
	// Data
	ProductData productData;
};

#endif // QUEUE_DLL_H