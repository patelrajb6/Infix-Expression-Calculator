#ifndef myClassesGuards
#define myClassesGuards

// libaries
#include <iostream>
using namespace std;

#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>

// node class for adjacent list in air port
class Node {

    public:
        int data;
        Node *next;
};

// use for file
class Filenode {
    public:
        string name;
        Filenode *next;
};

//-------------------------------------------------------------------------------------------------------------------

class MyLinkList {

    public:

        // constructor to set it to null
        MyLinkList ();

        // deconstructor to delete
        ~MyLinkList();

        // add to back of list
        void pushBack (int x);

        // find the specify number and delete it
        void deleteNode (int x);

        // get entire length of list
        int findLengthOfNodes ( );

        // see if the number is in the list
        bool contains( int x);

        // print entire list
        void printList ( );

        // delete entire list
        void deleteList ( );

        // retrieve head
        Node* getHead ();
        //adds node in the front
        ///////////////////////////////////////////////////////////////////////////
        void addToFront(int c);
        //gets the value from the front node
        int getFrontVal();
            //removes the front node
        void removeFrontval();
        //check if the list is empty or not
        bool isListEmpty();

      private:
        Node *head;

};

//------------------------------------------------------------------------------------------------------------
class Airport {

    public:

        // constructor
        Airport ();

        //deconstructor
        ~Airport();

        // add edge
        void addEdge (int x);

        // delete edge
        void deleteEdge ( int x);

        // see if its edge
        bool findEdge ( int x);

        //display all the numbers in list
        void displayAirports();

        // delete entire aiarports
        void deleteAllEdges ();

        // mark airport as visisted
        void markVisited();

        // mark airport as unvisisted
        void markUnVisited();

        // get the visit status
        bool getVisitStatus ( );

        // get the head of the list to traverse it
        Node *getHeadPointer();
        int getprev();////////////////////////////////////////
        void setprev(int c);////////////////////////////////

    private:
        bool visited;
        MyLinkList list;
        int prev; //////////////////////////////////////////// to keep track of its previous airport

};

//---------------------------------------------------------------------------------------------------------------------------------
class MyFileList {

    public:

        // construccotr
        MyFileList();

        // deconstructor
        ~MyFileList();

        // add to list
        void addFileName (string x);

        // remove from list
        void removeFileName (string x);

        // check if already exists
        bool checkAlreadyExists( string x);

        // delete all nodes
        void deleteAllFileNames ( );

    private:
        Filenode *head;

};


#endif