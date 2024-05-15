#ifndef QUEUE_H
#define QUEUE_H

/* Queue
 * - LILO
 * - tail <- node
 * 		Data is being pulled from tail and data is being pushed in the tail
*/

#include "node-dll.h"
#include <iostream>

class Queue_dll
{
public:
  void Starting();

private:
  void MainMenu(int &);
  int MainMenu();

  ProductData SetProductData();

  void SetProduct(Queue_DLL *&tail);
  void DeleteNode(Queue_DLL *&head);
  void Traversal(Queue_DLL *&head);
};

#endif // QUEUE_H