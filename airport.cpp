#include "myClass.h"


// BOTH MY LINKLIST FUNCTIONS AND AIRPORTS FUNCTIONS ARE IN HERE AND FILE NAME

// functions for link list

// constructor
MyLinkList::MyLinkList () {
    head = NULL;
}

//deconstructor delete all nodes
MyLinkList::~MyLinkList( ) {
    // if already empty error
    if (head == NULL) {
        return;
    }

    Node *temp = head;
    Node *fetcher;

    while (temp != NULL) {
        fetcher = temp->next;
        delete temp;
        temp = fetcher;
    }

    //finally make head to null pointer
    head = NULL;
}

//-----------------------------------------------------------------------------------------------
// add to link list
void MyLinkList::pushBack ( int x) {
    // new node
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    // if list is empty
    if(head == NULL) {
        head = temp;
        return;
    }

    // get to the last spot
    Node *walker = head;
    while (walker->next != NULL) {
        walker = walker->next;
    }

    // connect it
    walker->next = temp;

}

//-----------------------------------------------------------------------------------------------
// delete specific number from node
void MyLinkList::deleteNode( int x) {

    // if its empty nothing happens
    if (head == NULL) {
        cout << "Error these airports are not connected" << endl;
        return;
    }

    // if the head is the one we want to delete
    if (head->data == x) {
        Node *deleteNode = head;
        head = deleteNode->next;
        delete deleteNode;
        return;
    }

    // declare temp and a lagger
    Node *temp = head;
    Node *lagger;

    while (temp != NULL && temp->data != x) {
        lagger = temp;
        temp = temp->next;
    }

    // check if found if not then delete
    if (temp == NULL) {
        cout << "Error these airports are not connected" << endl;
        return;
    }
    else {
        lagger->next = temp->next;
        delete temp;
    }
}

//---------------------------------------------------------------------------------------------------
int MyLinkList::findLengthOfNodes( ) {

    // if empty return 0
    if (head == NULL) {
        return 0;
    }

    int count = 0;  // intilize to 0

    Node *temp = head;

    // walk through the list
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

//--------------------------------------------------------------------------------------------------------
bool MyLinkList::contains(int x) {

    // if empty return false
    if (head == NULL) {
        return false;
    }

    Node *temp = head;
    while (temp != NULL) {

        // if we find a match return true
        if (temp->data == x) {
            return true;
        }

        // walk the list
        temp = temp->next;
    }

    return false;      // nothing found
}

//------------------------------------------------------------------------------------------------------------
void MyLinkList::printList () {

    // if empty cant do ntohing
    if (head == NULL) {
        cout << "No airports available" << endl;
        return;
    }

    Node *temp = head;

    // traverse through the list
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

}

//----------------------------------------------------------------------------------------------------------
void MyLinkList::deleteList() {

    // if already empty error
    if (head == NULL) {
        return;
    }

    Node *temp = head;
    Node *fetcher;

    while (temp != NULL) {
        fetcher = temp->next;
        delete temp;
        temp = fetcher;
    }

    //finally make head to null pointer
    head = NULL;
}

//-----------------------------------------------------------------------------------------------------
Node *MyLinkList::getHead() {
    if (head == NULL) {
        return NULL;
    }

    return head;
}

void MyLinkList::addToFront(int c)
{
    Node *temp = new Node;
    temp->data = c;
    temp->next = head;
    head = temp;
}


    //gets the value from the front node
 int MyLinkList::getFrontVal()
{
        return head->data;
}
//removes the front node
void MyLinkList::removeFrontval()
{
    Node *temp = head;
    head = temp->next;
    delete temp;
}
//check if the list is empty or not
bool MyLinkList::isListEmpty()////////////////////////////////////
{
    if(head==NULL)
    {return true;}
    return false;
}

//----------------------------------------------------------------------------------------------------

// airport functions

// constructor
Airport::Airport ( ) {
    visited = false;
    prev=0;////////////////////////////////////////
}

//deconstructor
Airport::~Airport() {
    list.deleteList();
}

void Airport::setprev(int p)/////////////////////////////////////
{
    this->prev=p;
}

int Airport::getprev()////////////////////////////////////////
{
    return this->prev;
}
// add a edge piece
void Airport::addEdge ( int x) {
    list.pushBack( x);
}

// delete an edge piece
void Airport::deleteEdge( int x) {
    list.deleteNode( x);
}

// see if its an edge
bool Airport::findEdge ( int x) {
    return list.contains(x);
}

void Airport::displayAirports ( ) {
    list.printList();
}

void Airport::deleteAllEdges ( ) {
    list.deleteList();
}

void Airport::markVisited() {
    this->visited = true;
}

void Airport::markUnVisited() {
    this->visited = false;
}

bool Airport::getVisitStatus() {
    return this->visited;
}

Node *Airport::getHeadPointer() {
    return list.getHead();
}



//------------------------------------------------------------------------------------------------------
// file name node functions

MyFileList::MyFileList() {
    head = NULL;
}

MyFileList::~MyFileList() {
    // if already empty error
    if (head == NULL) {
        return;
    }

    Filenode *temp = head;
    Filenode *fetcher;

    while (temp != NULL) {
        fetcher = temp->next;
        delete temp;
        temp = fetcher;
    }

    //finally make head to null pointer
    head = NULL;
}

//-----------------------------------------------------------------------------------------------------
void MyFileList::addFileName( string x) {

    // new node
    Filenode *temp = new Filenode;
    temp->name = x;
    temp->next = NULL;

    // if list is empty
    if(head == NULL) {
        head = temp;
        return;
    }

    // get to the last spot
    Filenode *walker = head;
    while (walker->next != NULL) {
        walker = walker->next;
    }

    // connect it
    walker->next = temp;
}

//---------------------------------------------------------------------------------------------------------
void MyFileList::removeFileName( string x) {

    // if its empty nothing happens
    if (head == NULL) {
        cout << "Error file name not found" << endl;
        return;
    }

    // if the head is the one we want to delete
    if (head->name.compare(x) == 0) {
        Filenode *deleteNode = head;
        head = deleteNode->next;
        delete deleteNode;
        return;
    }

    // declare temp and a lagger
    Filenode *temp = head;
    Filenode *lagger;

    while (temp != NULL && temp->name.compare(x) != 0) {
        lagger = temp;
        temp = temp->next;
    }

    // check if found if not then delete
    if (temp == NULL) {
        cout << "Error name not found" << endl;
        return;
    }
    else {
        lagger->next = temp->next;
        delete temp;
    }
}

//-------------------------------------------------------------------------------------------------------------
bool MyFileList::checkAlreadyExists( string x) {

    // if empty return false
    if (head == NULL) {
        return false;
    }

    Filenode *temp = head;
    while (temp != NULL) {

        // if we find a match return true
        if (temp->name.compare(x) == 0) {
            return true;
        }

        // walk the list
        temp = temp->next;
    }

    return false;      // nothing found

}

//--------------------------------------------------------------------------------------------------------------------
void MyFileList::deleteAllFileNames() {

    // if already empty error
    if (head == NULL) {
        return;
    }

    Filenode *temp = head;
    Filenode *fetcher;

    while (temp != NULL) {
        fetcher = temp->next;
        delete temp;
        temp = fetcher;
    }

    //finally make head to null pointer
    head = NULL;
}