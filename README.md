Collection
==========
eine Collection Klasse auf Basis einer doppelt verketteten Liste in Anlehnung an das Entity/Collection Pattern


Collection ist eine kleine Fingerübung für mich um in C++ nach all der Zeit wieder rein zu kommen und um eine Vergleichbare Funktionalität an der Hand zu haben, wie es Array in PHP bietet.

Collection ist eine template Klasse, der man einen beliebigen Datentyp, also auch jede Klasse, übergeben kann.

Initialisiert wird die Collection per
-------------------------------------

<code>Collection<DATENTYP></code>

wobei DATENTYP jeden möglichen Datentyp repräsentiert.

gefüllt wird die Collection per

<code>oCollection.add(DATENTYP);</code>

oder per

<code>oCollection[0] = DATENTYP;</code>

Iteriert werden kann die Collection per

<code>oCollection.reset();

while (oCollection++) {
  Node<DATENTYP>* pNode = oCollection.getActualNode();
  DATENTYP oEntity = pNode->getData();
}
</code>

oder per

<code>
Node<DATENTYP>* pNode = oCollection.getFirstNode();

while(pNode) {
  DATENTYP oEntity = pNode->getData();
  pNode = pNode->getNext();
}
</code>
