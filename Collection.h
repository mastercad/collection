#ifndef __COLLECTION_H__
#define __COLLECTION_H__

#include "Node.h"

template<typename T>class Collection
{
  public:
    /** Member **/
    /** Methods **/

    T& get(const unsigned int);
    unsigned int add(const T&, const int);
    unsigned int set(const T&, unsigned int);
    bool remove(const unsigned int);
    bool replace(const unsigned int, const T);
    
    bool reset();
    bool checkKeyExists(const unsigned int);
    bool checkKeyExists(const std::string);
    bool deleteNode(Node<T>*);
    
    void setFirstNode(Node<T>*);
    Node<T>* getFirstNode(void);
    void setLastNode(Node<T>*);
    Node<T>* getLastNode(void);
    Node<T>* getActualNode(void);
    
    T& operator[] (const unsigned int);
    const T& operator[] (const unsigned int) const;
    Node<T>& operator=(const T&);
    
    Node<T>* operator++ ();
    Node<T>* operator++ (int);
    Node<T>* operator-- ();
    Node<T>* operator-- (int);

    Collection();
    ~Collection();
    
  protected:
    /** Member **/
    /** Methods **/
  private:
    /** Member **/
    unsigned int _iCount;
    Node<T>* _pNode;
    Node<T>* _pFirstNode;
    Node<T>* _pLastNode;
    /** Methods **/
    Node<T>* _search(const unsigned int);
    Node<T>* _search(const std::string);
};

#endif