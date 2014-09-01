#include <iostream>
#include <string>
#include <sstream>

#include "Collection.cpp"

using namespace std;

int main(int argc, char **argv) {
  Collection<Entity> oCollection;
  
  for (int i = 0; i <= 100; i++) {
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
  
  Node<Entity>* pNode = oCollection.getFirstNode();
  
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
  for (i = 0; i < 1; i++) {
    Entity oEntity;
    oSecCollection.add(oEntity);
  }
  
  // test des überladenen operator=
  Collection<Entity> oNewCollection;
  oNewCollection = oSecCollection;
  
  i = 0;
  pNode = oNewCollection.getFirstNode();
  while (pNode) {
    std::cout << pNode << std::endl;
    pNode = pNode->getNext();
  }
  
  // die neue Art Collections zu iterieren 
  oNewCollection.reset();
  
  while (oNewCollection++) {
    Node<Entity>* pNode = oNewCollection.getActualNode();
    Entity oEntity = pNode->getData();
    std::cout << "DATA: " << std::endl;
    std::cout << oEntity.getName() << std::endl;
  }
  
  return 0;
}
