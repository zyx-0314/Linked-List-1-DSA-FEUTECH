#ifndef DLL_H
#define DLL_H

#include "node-dll.h"
#include <iostream>

class Dll
{
public:
  void Starting();

private:
  void MainMenu(int &);

  ProductData SetProductData();

  void SetProduct_Queue(Node_DLL *&tail, Node_DLL *&head);
  void SetProduct_Stack(Node_DLL *&tail, Node_DLL *&head);
  void Traversal_Queue(Node_DLL *&head);
  void Traversal_Stack(Node_DLL *&tail);
  void DeleteNode_Queue(Node_DLL*& tail, Node_DLL*& head);
  void DeleteNode_Stack(Node_DLL*& tail, Node_DLL*& head);
};

#endif // DLL_H