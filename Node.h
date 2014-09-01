#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include "Entity.cpp"

template<class T> class Node {
public:
  
  void setNext(Node*);
  
  Node* getNext(void);
  
  void setPrev(Node*);
  
  Node* getPrev(void);
  
  void setData(T);
  
  T& getData(void);
  
  std::string getStringKey();
  
  int getIntKey();
  
  void setKey(const std::string);
  
  void setKey(int);
  
  Node* add(Node*);
  
  Node();
  
  ~Node();

private:
  T _mData;
  int _iKey;
  std::string _sKey;
  Node *_pNext;
  Node *_pPrev;
};

#endif