#ifndef STACK_H
#define STACK_H

/* Stack
 * - FILO
 * - tail <- node
 * 		Data is being pulled from tail and data is being pushed in the tail
*/

#include "node-sll.h"
#include <iostream>

class Stack_sll
{
public:
  void Starting();

private:
  void MainMenu(int &);
  int MainMenu();

  ProductData SetProductData();

  void SetProduct(Stack_SLL *&tail);
  void DeleteNode(Stack_SLL *&tail);
  void Traversal(Stack_SLL *&tail);
};

#endif // STACK_H