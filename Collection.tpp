#ifndef __COLLECTION_TPP__
#define __COLLECTION_TPP__

#include <iostream>
#include <stdexcept>

template<typename T>class Collection
{
public:
  static Collection<T>* _pFirstNode;
  static Collection<T>* _pLastNode;
    /** Member **/
    /** Methods **/

    T& get(const unsigned int);

    Collection<T>& add(Collection<T>);
    unsigned int add(const T&, const int);

    unsigned int set(const T&, unsigned int);
    bool remove(const unsigned int);
    bool replace(const unsigned int, const T);
    
    void reverse();
    bool reset();
    bool checkKeyExists(const unsigned int);
    bool checkKeyExists(const std::string);
    bool deleteNode(Collection<T>&);
    
    void setFirstNode(Collection<T>*);
    Collection<T>* getFirstNode(void);

    void setLastNode(Collection<T>*);
    Collection<T>* getLastNode(void);

//     Collection<T>* getActualNode(void);

    void setNext(Collection<T>*);
    Collection<T>* getNext(void);

    void setPrev(Collection<T>*);
    Collection<T>* getPrev(void);

    std::string getStringKey();
    void setKey(const std::string);
    
    int getIntKey();
    void setKey(int);

    void setData(T);
    T& getData(void);
    
    T& operator[] (const unsigned int);
    const T& operator[] (const unsigned int) const;
    Collection<T>& operator=(const T&);
    
    Collection<T>* operator++ ();
    Collection<T>* operator++ (int);
    Collection<T>* operator-- ();
    Collection<T>* operator-- (int);

    Collection();
    ~Collection();
    
  protected:
    /** Member **/
    /** Methods **/
  private:
    /** Member **/
    unsigned int _iCount;
//     Collection<T>* _pNode;
    /** Methods **/
    Collection<T>* _search(const unsigned int);
    Collection<T>* _search(const std::string);
    int _iKey;
    std::string _sKey;
    Collection<T>* _pNext;
    Collection<T>* _pPrev;
    Collection<T>* _pNode;
    T _mData;
};

template<typename T>Collection<T>* Collection<T>::_pFirstNode = 0;
template<typename T>Collection<T>* Collection<T>::_pLastNode = 0;

template<typename T>unsigned int Collection<T>::add(const T& mData, const int iKey = -1) {
  Collection<T>* pNode = new Collection<T>;

  pNode->setPrev(_pNode);

  if (_pNode) {
    _pNode->setNext(pNode);
  }
  
  /** @todo hier noch überarbeiten, wenn iKey übergeben wird, muss gesucht werden, ob replaced werden muss ! **/
  if (iKey >= 0) {
    pNode->setKey(iKey);
  } else {
    pNode->setKey(_iCount);
  }
  pNode->setData(mData);
  
  if (0 == _pFirstNode) {
    _pFirstNode = pNode;
  }
  Collection::setLastNode(pNode);
  _pNode = pNode;
  _iCount++;
  return getIntKey();
}

template<typename T>T& Collection<T>::get(const unsigned int iIndex) {
  Collection<T>* pNode = Collection::_search(iIndex);
  return pNode->getData();
}

template<typename T>Collection<T>* Collection<T>::_search(const unsigned int iKey) {
  Collection<T>* pNode = Collection::getFirstNode();
  while (pNode) {
    unsigned int iTempKey = pNode->getIntKey();
    if (iKey == iTempKey) {
      break;
    }
    pNode = pNode->getNext();
  }
  return pNode;
}

template<typename T>Collection<T>* Collection<T>::_search(const std::string sKey) {
  Collection<T>* pNode = Collection::getFirstNode();
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
    Collection<T>* pActualNode = _search(iIndex);
    Collection<T>* pPrevNode = pActualNode->getPrev();
    Collection<T>* pNextNode = pActualNode->getNext();
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
    Collection<T>* pAcutalNode = _search(iIndex);
    if (pAcutalNode) {
      pAcutalNode->setData(mData);
    }
  } else {
    add(mData, iIndex);
  }
  return true;
}

template<typename T>bool Collection<T>::checkKeyExists(const unsigned int iKey) {
  Collection<T>* pNode = Collection::getFirstNode();
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
  Collection<T>* pNode = Collection::getFirstNode();
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

template<typename T>bool Collection<T>::deleteNode(Collection<T>& pNode) {
  
}

template<typename T>void Collection<T>::setFirstNode(Collection<T>* pFirstNode) {
  _pFirstNode = pFirstNode;
}

template<typename T>Collection<T>* Collection<T>::getFirstNode() {
  return _pFirstNode;
}

template<typename T>void Collection<T>::setLastNode(Collection<T>* pLastNode) {
  _pLastNode = pLastNode;
}

template<typename T>Collection<T>* Collection<T>::getLastNode() {
  return _pLastNode;
}

// template<typename T>Collection<T>* Collection<T>::getActualNode() {
//   return *this;
// }

template<typename T>T& Collection<T>::operator[] (const unsigned int iIndex) {
  Collection<T>* pNode = _search(iIndex);
  
  if (pNode) {
    return pNode->getData();
  }
  
  // index wurde nicht gefunden
  // wenn der index kleiner gleich dem aktuellen maxCount, gültig, also setzen
  if (iIndex <= _iCount) {
    T mData;
    add(mData, iIndex);
    Collection<T>* pNode = _search(iIndex);
    return pNode->getData();
  }
  return _pFirstNode->getData();
}

template<typename T>const T& Collection<T>::operator[] (const unsigned int iIndex) const {
  Collection<T>* pNode = _search(iIndex);
  
  if (pNode) {
    return pNode->getData();
  }
  
  // index wurde nicht gefunden
  // wenn der index kleiner gleich dem aktuellen maxCount, gültig, also setzen
  if (iIndex <= _iCount) {
    T mData;
    add(mData, iIndex);
    Collection<T>* pNode = _search(iIndex);
    return pNode->getData();
  }
  return Collection<T>::_pFirstNode->getData();
}

// ++Object
template<typename T>Collection<T>* Collection<T>::operator++ () {
  if (_pNode) {
    std::cout << "intKey : " << _pNode->getIntKey() << std::endl;
    return _pNode->getNext();
  }
}

// Object++
template<typename T>Collection<T>* Collection<T>::operator++ (int iIndex) {
  if (_pNode) {
    Collection<T>* pTemp = _pNode;
    std::cout << "intKey : " << pTemp->getIntKey() << std::endl;
    _pNode = _pNode->getNext();
    return pTemp;
  }
}

// --Object
template<typename T>Collection<T>* Collection<T>::operator-- () {
  if (_pNode) {
    return _pNode->getPrev();
  }
}

// Object--
template<typename T>Collection<T>* Collection<T>::operator-- (int iIndex) {
  if (_pNode) {
    Collection<T>* pTmp = _pNode;
    _pNode = _pNode->getPrev();
    return pTmp;
  }
}

template<typename T>Collection<T>& Collection<T>::operator=(const T& mData) {
  std::cout << "Rufe operator= auf!" << std::endl;
  return *this;
}

/**
 * CTOR
 */
template<typename T>Collection<T>::Collection() {
  _iCount = 0;
  _iKey = 0;
  _sKey = "";
  _pPrev = 0;
  _pNext = 0;
  _pNode = 0;
}

/**
 * DTOR
 */
template<typename T>Collection<T>::~Collection() {
}

template<typename T>std::string Collection<T>::getStringKey() {
  return _sKey;
}

template<typename T>int Collection<T>::getIntKey() {
  return _iKey;
}

template<typename T>void Collection<T>::setData(T mData) {
  _mData = mData;
}

template<typename T>T& Collection<T>::getData() {
  return _mData;
}

template<typename T>void Collection<T>::setNext(Collection<T>* pNextNode) {
  _pNext = pNextNode;
}

template<typename T>Collection<T>* Collection<T>::getNext() {
  return _pNext;
}

template<typename T>void Collection<T>::setPrev(Collection<T>* pPrevNode) {
  _pPrev = pPrevNode;
}

template<typename T>Collection<T>* Collection<T>::getPrev() {
  return _pPrev;
}

template<typename T>void Collection<T>::setKey(const std::string sKey) {
  _sKey = sKey;
}

template<typename T>void Collection<T>::setKey(int iKey) {
  _iKey = iKey;
}

template<typename T>void Collection<T>::reverse() {
  Collection<T>* p = 0; Collection<T>* i = _pFirstNode; Collection<T>* n;
  while (i)
  {
    n = i->next;
    i->next = p;
    p = i;
    i = n;
  }
  _pNode = p;
}
#endif
