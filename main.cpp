#include <iostream>
#include <string>
#include <sstream>

#include "Collection.h"
#include "Entity.h"

using namespace std;

int main(int argc, char **argv) {
  Collection<Entity> oCollection;
  
  for (int i = 0; i <= 30; i++) {
    Entity oEntity;
    string a;
    std::ostringstream convert;
    convert << i;
    a = convert.str();
    oEntity.setName("ID " + a);
    oCollection.add(oEntity);
  }
  
  Entity oEntity = oCollection.get(28);
  cout << oEntity.getName() << endl;

  oEntity.setName("BLAH!");
  oCollection.set(oEntity, 28);
  
  oEntity = oCollection.get(28);
  cout << oEntity.getName() << endl;
  
  Collection<Entity>* pNode = oCollection.getFirstNode();
  
  int i = 0;
  while (pNode && i < 20) {
    oEntity = pNode->getData();
    cout << "I : " << i << " - Name : " << oEntity.getName() << " Adresse : " << pNode << " - ID " << pNode->getIntKey() << endl;
    pNode = pNode->getNext();
    i++;
  }
  
  cout << endl << "Remove 4 !" << endl << endl;
  
  oCollection.remove(4);
  
  cout << "Existiert Key 4 ? " << oCollection.checkKeyExists(4) << endl;
  
  i = 0;
  pNode = oCollection.getFirstNode();
  
  while (pNode && i < 20) {
    oEntity = pNode->getData();
    cout << "I : " << i << " - Name : " << oEntity.getName() << " Adresse : " << pNode << " - ID " << pNode->getIntKey() << endl;
    pNode = pNode->getNext();
    i++;
  }
  
  cout << endl << "Setze Data von Key 6 auf FOO-BAR!" << endl << endl;
  oEntity.setName("FOO-BAR!");
  oCollection[6] = oEntity;
  
  i = 0;
  pNode = oCollection.getFirstNode();
  
  while (pNode && i < 20) {
    oEntity = pNode->getData();
    cout << "I : " << i << " - Name : " << oEntity.getName() << " Adresse : " << pNode << " - ID " << pNode->getIntKey() << endl;
    pNode = pNode->getNext();
    i++;
  }
  
  oEntity.setName("Ich Soll Key 4 werden!");
  cout << endl << "Setze Data von Key 4 auf 'Ich Soll Key 4 werden!'" << endl << endl;
  oCollection[4] = oEntity;
  cout << "Existiert Key 4 ? " << oCollection.checkKeyExists(4) << endl;
  
  oCollection[2] = oCollection[7];
  
  i = 0;
  pNode = oCollection.getFirstNode();
  
  while (pNode && i < 20) {
    oEntity = pNode->getData();
    cout << "I : " << i << " - Name : " << oEntity.getName() << " Adresse : " << pNode << " - ID " << pNode->getIntKey() << endl;
    pNode = pNode->getNext();
    i++;
  }
  
  pNode = oCollection.getLastNode();
  oEntity = pNode->getData();
  cout << "Letzter Knoten in der Collection - Name : " << oEntity.getName() << " Adresse : " << pNode << " - ID : " << pNode->getIntKey() << endl;
  
  Collection<Entity> oSecCollection;

  i = 0;
  for (i = 0; i < 10; i++) {
    Entity oEntity;
    oEntity.setName("1. Entity der SecCollection");
    oSecCollection.add(oEntity);
  }
  
  // test des überladenen operator=
  Collection<Entity> oNewCollection;
  oNewCollection = oSecCollection;
  
  i = 0;
//   pNode = oNewCollection.getFirstNode();
  oNewCollection.reset();
//   while (Collection<Entity>* pNode = oNewCollection++) {
  while (oNewCollection++) {
    std::cout << "PostKrement IntKey : " << oNewCollection.getIntKey() << std::endl;
//     std::cout << &oNewCollection << std::endl;
//     pNode = pNode->getNext();
  }
  
  // die neue Art Collections zu iterieren 
//   oNewCollection.reset();
  
  while (Collection<Entity>* pNode = --oNewCollection) {
    Entity oEntity = pNode->getData();
    std::cout << "DATA: " << std::endl;
    std::cout << oEntity.getName() << std::endl;
  }
  
  return 0;
}
