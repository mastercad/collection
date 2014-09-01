#include <iostream>
#include <stdexcept>
#include "Collection.h"
#include "Entity.h"
#include "Node.cpp"

template<typename T>unsigned int Collection<T>::add(const T& mData, const int iKey = -1) {
  Node<T>* pNode = new Node<T>;
  pNode->setPrev(_pNode);
  pNode->setNext(0);
  
  if (iKey >= 0) {
    pNode->setKey(iKey);
  } else {
    pNode->setKey(_iCount);
  }
  pNode->setData(mData);
  
  if (_pNode) {
    _pNode->setNext(pNode);
  }
  
  if (0 == _pFirstNode) {
    _pFirstNode = pNode;
  }
  Collection::setLastNode(pNode);
  _pNode = pNode;
  _iCount++;
  return pNode->getIntKey();
}

template<typename T>T& Collection<T>::get(const unsigned int iIndex) {
  Node<T>* pNode = Collection::_search(iIndex);
  return pNode->getData();
}

template<typename T>Node<T>* Collection<T>::_search(const unsigned int iKey) {
  Node<T>* pNode = Collection::getFirstNode();
  while (pNode) {
    unsigned int iTempKey = pNode->getIntKey();
    if (iKey == iTempKey) {
      break;
    }
    pNode = pNode->getNext();
  }
  return pNode;
}

template<typename T>Node<T>* Collection<T>::_search(const std::string sKey) {
  Node<T>* pNode = Collection::getFirstNode();
  while (pNode) {
    if (sKey == pNode->getStringKey()) {
      break;
    }
    pNode = pNode->getNext();
  }
  return pNode;
}

template<typename T>unsigned int Collection<T>::set(const T& mData, unsigned int iIndex = -1) {
  if (-1 == iIndex) {
    add(mData);
  } else {
    replace(iIndex, mData);
  }
  return true;
}

template<typename T>bool Collection<T>::remove(const unsigned int iIndex) {
  if (0 < iIndex 
    && iIndex <= _iCount
  ) {
    Node<T>* pActualNode = _search(iIndex);
    Node<T>* pPrevNode = pActualNode->getPrev();
    Node<T>* pNextNode = pActualNode->getNext();
    pPrevNode->setNext(pNextNode);
    pNextNode->setPrev(pPrevNode);
    
    delete pActualNode;
  } else {
    return false;
  }
  
  return true;
}

template<typename T>bool Collection<T>::replace(const unsigned int iIndex, T mData) {
  if (0 < iIndex 
    && iIndex <= _iCount
  ) {
    Node<T>* pAcutalNode = _search(iIndex);
    if (pAcutalNode) {
      pAcutalNode->setData(mData);
    }
  } else {
    add(mData, iIndex);
  }
  return true;
}

template<typename T>bool Collection<T>::checkKeyExists(const unsigned int iKey) {
  Node<T>* pNode = Collection::getFirstNode();
  while (pNode) {
    if (iKey == pNode->getIntKey()
    ) {
      return true;
    }
    pNode = pNode->getNext();
  }
  return false;
}

template<typename T>bool Collection<T>::checkKeyExists(const std::string sKey) {
  Node<T>* pNode = Collection::getFirstNode();
  while (pNode) {
    if (sKey == pNode->getStringKey()) {
      return true;
    }
    pNode = pNode->getNext();
  }
  return false;
}

template<typename T>bool Collection<T>::reset() {
  _pNode = _pFirstNode;
}

template<typename T>bool Collection<T>::deleteNode(Node<T>* pNode) {
  
}

template<typename T>void Collection<T>::setFirstNode(Node<T>* pFirstNode) {
  _pFirstNode = pFirstNode;
}

template<typename T>Node<T>* Collection<T>::getFirstNode() {
  return _pFirstNode;
}

template<typename T>void Collection<T>::setLastNode(Node<T>* pLastNode) {
  _pLastNode = pLastNode;
}

template<typename T>Node<T>* Collection<T>::getLastNode() {
  return _pLastNode;
}

template<typename T>Node<T>* Collection<T>::getActualNode() {
  return _pNode;
}

template<typename T>T& Collection<T>::operator[] (const unsigned int iIndex)
{
  Node<T>* pNode = _search(iIndex);
  
  if (pNode) {
    return pNode->getData();
  }
  
  // index wurde nicht gefunden
  // wenn der index kleiner gleich dem aktuellen maxCount, gültig, also setzen
  if (iIndex <= _iCount) {
    T mData;
    add(mData, iIndex);
    Node<T>* pNode = _search(iIndex);
    return pNode->getData();
  }
  return _pFirstNode->getData();
}

template<typename T>const T& Collection<T>::operator[] (const unsigned int iIndex) const
{
  Node<T>* pNode = _search(iIndex);
  
  if (pNode) {
    return pNode->getData();
  }
  
  // index wurde nicht gefunden
  // wenn der index kleiner gleich dem aktuellen maxCount, gültig, also setzen
  if (iIndex <= _iCount) {
    T mData;
    add(mData, iIndex);
    Node<T>* pNode = _search(iIndex);
    return pNode->getData();
  }
  return _pFirstNode->getData();
}

// ++Object
template<typename T>Node<T>* Collection<T>::operator++ () {
  if (_pNode) {
    _pNode = _pNode->getNext();
  }
  return _pNode;
}

// Object++
template<typename T>Node<T>* Collection<T>::operator++ (int iIndex) {
  Node<T>* pTmp = _pNode;
  if (_pNode) {
    _pNode = _pNode->getNext();
  }
  return pTmp;
}

template<typename T>Node<T>* Collection<T>::operator-- () {
  if (_pNode) {
    _pNode = _pNode->getPrev();
  }
  return _pNode;
}

template<typename T>Node<T>* Collection<T>::operator-- (int iIndex) {
  Node<T>* pTmp = _pNode;
  if (_pNode) {
    _pNode = _pNode->getPrev();
  }
  return pTmp;
}

template<typename T>Node<T>& Collection<T>::operator=(const T& mData) {
  std::cout << "Rufe operator= auf!" << std::endl;
  return *this;
}

/**
 * CTOR
 */
template<typename T>Collection<T>::Collection() {
  _iCount = 0;
  _pFirstNode = 0;
  _pLastNode = 0;
  _pNode = 0;
}

/**
 * DTOR
 */
template<typename T>Collection<T>::~Collection() {
}
