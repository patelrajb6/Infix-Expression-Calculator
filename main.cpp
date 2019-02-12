#include "myClass.h"
#include <vector>

/*
    PUT SOME HASHTAGS IN THE TEXT FILES WHEN IT IS ONLY  ONE LETTER, (EXAMPLE l #) SO THE F COMMAND WORKS AND READS THE L PROPERLY OTHERWISE
    IT WILL GO *l COMMAND IS NOT KNOWN FOR SOME REASON
    ALSO PUT A HASHTAG AFTER EACH FILE NAME IN THE TEXT FILE SO IT READS THE FILE NAME PROPERLY
    EX; f proj6data5.txt #
    NOT SURE IF A ERROR ON MY END ON READING FILE FUNCTION OR ERROR ON PAT TROY END IN PROCESSCOMMANDLOOP INPUT,BUFFER,ETC
    ALL I KNOW IS PUTTING HASTAGS FIXES IT
*/

class TravelNetwork
{
  private:
    // Create the Data Members for the Travel Network here

    // used to make array of airports
    Airport *network;
    int maxNumOfAirports; // number of airports to be made
    MyFileList fileLists; // link list of file names for f command
    //MyLinkList AirQueue;
   // MyLinkList pathlist;

  public:
    // Use a constructor to initialize the Data Members for Travel Network
    TravelNetwork()
    {
        //intilize 10 aiports
        maxNumOfAirports = 10;
        network = new Airport[maxNumOfAirports + 1]; // we add +1 because we want 1-10 not 0-9. we will ignore the 0
    }

    //------------------------------------------------------------------------------------------------------------------------
    // deconstructor
    ~TravelNetwork()
    {
        delete[] network;
        fileLists.deleteAllFileNames();
    }

    //---------------------------------------------------------------------------------------------------------------------------------------
    // The main loop for reading in input
    void processCommandLoop(FILE *inFile)
    {
        char buffer[300];
        char *input;

        input = fgets(buffer, 300, inFile); // get a line of input

        // loop until all lines are read from the input
        while (input != NULL)
        {
            // process each line of input using the strtok functions
            char *command;
            command = strtok(input, " \n\t");

            printf("*%s*\n", command);

            if (command == NULL)
                printf("Blank Line\n");

            else if (strcmp(command, "q") == 0)
                exit(1);

            else if (strcmp(command, "?") == 0)
                showCommands();

            else if (strcmp(command, "t") == 0)
                doTravel();

            else if (strcmp(command, "r") == 0)
                doResize();

            else if (strcmp(command, "i") == 0)
                doInsert();

            else if (strcmp(command, "d") == 0)
                doDelete();

            else if (strcmp(command, "l") == 0)
                doList();

            else if (strcmp(command, "f") == 0)
                doFile();

            else if (strcmp(command,"s")==0)  /////////////////////////////////////////////////////////////////////
                dobfs();

            else if (strcmp(command, "#") == 0)
                ;

            else
                printf("Command is not known: %s\n", command);

            input = fgets(buffer, 300, inFile); // get the next line of input
        }
    }

    //---------------------------------------------------------------------------------------------------------------------------------------
    void showCommands()
    {
        printf("The commands for this project are:\n");
        printf("  q \n");
        printf("  ? \n");
        printf("  # \n");
        printf("  t <int1> <int2> \n");
        printf("  r <int> \n");
        printf("  i <int1> <int2> \n");
        printf("  d <int1> <int2> \n");
        printf("  l \n");
        printf("  f <filename> \n");
        printf("  s <int1> <int2> \n");/////////////////////////////////////////////////////////////////
    }

    //-------------------------------------------------------------------------------------------------------------------------------
    void doTravel()
    {
        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char *next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if (val1 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if (val2 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // check if val1 is valid
        // greater than number of apirports or a negative value
        if (val1 > this->maxNumOfAirports || val1 <= 0)
        {
            cout << "Error " << val1 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if val2 is valid
        if (val2 > this->maxNumOfAirports || val2 <= 0)
        {
            cout << "Error " << val2 << " is not a valid airport. Please try again" << endl;
            return;
        }

        printf("Performing the Travel Command from %d to %d\n", val1, val2);

        // use DFS
        depthFirstSearchHelper(val1, val2);
    }

    //--------------------------------------------------------------------------------------------------------------------
    void doResize()
    {
        int val1 = 0;

        // get an integer value from the input
        char *next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if (val1 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // make sure val1 is bigger than 0
        if (val1 <= 0)
        {
            cout << "Error. Cannot resize with 0 or less than" << endl;
            return;
        }

        // delete entire list
        int i;
        for (i = 0; i < maxNumOfAirports + 1; i++)
        {
            network[i].deleteAllEdges();
        }

        // delete array
        delete[] network;

        // resize and rebuild the array
        this->maxNumOfAirports = val1;
        network = new Airport[maxNumOfAirports + 1];

        printf("Performing the Resize Command with %d\n", val1);
    }

    //-------------------------------------------------------------------------------------------------------------
    void doInsert()
    {

        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char *next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if (val1 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if (val2 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // check if val1 is valid
        // greater than number of apirports or a negative value
        if (val1 > this->maxNumOfAirports || val1 <= 0)
        {
            cout << "Error " << val1 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if val2 is valid
        if (val2 > this->maxNumOfAirports || val2 <= 0)
        {
            cout << "Error " << val2 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if val2 is already an edge of val 1
        if (network[val1].findEdge(val2) == true)
        {
            cout << "Error " << val2 << " already exists. No duplicates allowed" << endl;
            return;
        }

        // passes all error check so push it onto the list
        network[val1].addEdge(val2);

        printf("Performing the Insert Command from %d to %d\n",
               val1, val2);
    }

    //----------------------------------------------------------------------------------------------------------------------
    void doDelete()
    {

        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char *next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if (val1 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if (val2 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // check if val1 is valid
        // greater than number of apirports or a negative value
        if (val1 > this->maxNumOfAirports || val1 <= 0)
        {
            cout << "Error " << val1 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if val2 is valid
        if (val2 > this->maxNumOfAirports || val2 <= 0)
        {
            cout << "Error " << val2 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if edge exists
        if (network[val1].findEdge(val2) == true)
        {

            // delete the edge
            network[val1].deleteEdge(val2);

            printf("Performing the Delete Command from %d to %d\n",
                   val1, val2);
        }

        else
        {
            cout << "Error these airports are not connected" << endl;
        }
    }

    //----------------------------------------------------------------------------------------------------------------------------------------
    void doList()
    {
        int i; // loop counter
        for (i = 1; i < this->maxNumOfAirports + 1; i++)
        { // +1 because were not counting 0 we want 1 to max to show
            cout << "Airport " << i << ": ";
            network[i].displayAirports();
        }
    }

    //----------------------------------------------------------------------------------------------------------------------------------------
    void doFile()
    {
        // get a filename from the input
        char *fname = strtok(NULL, " \n\t");
        if (fname == NULL)
        {
            printf("Filename expected\n");
            return;
        }

        printf("Performing the File command with file: %s\n", fname);

        // next steps:  (if any step fails: print an error message and return )
        //  1. verify the file name is not currently in use......inside link list ..contains op?
        //  2. open the file using fopen creating a new instance of FILE* .. open file and read and create new file*
        //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
        //  4. close the file when processCommandLoop() returns..........fclose and remove from link  list

        // check if file name exists
        if (fileLists.checkAlreadyExists(fname) == true)
        {
            cout << "Error filename already in use " << endl;
            return;
        }

        // create new instance
        FILE *myFileName;
        myFileName = fopen(fname, "r");

        if (myFileName == NULL)
        {
            cout << "Error couldnt open file or find it" << endl;
            return;
        }

        // add to link list
        fileLists.addFileName(fname);

        // recursive call
        processCommandLoop(myFileName);

        // close file
        fclose(myFileName);

        // remove name from link list
        fileLists.removeFileName(fname);
    }


    void dobfs() ///////////////////////////////////////////////////////////////////////////////////////////
    {
        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char *next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val1 = atoi(next);
        if (val1 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok(NULL, " \n\t");
        if (next == NULL)
        {
            printf("Integer value expected\n");
            return;
        }
        val2 = atoi(next);
        if (val2 == 0 && strcmp(next, "0") != 0)
        {
            printf("Integer value expected\n");
            return;
        }

        // check if val1 is valid
        // greater than number of apirports or a negative value
        if (val1 > this->maxNumOfAirports || val1 <= 0)
        {
            cout << "Error " << val1 << " is not a valid airport. Please try again" << endl;
            return;
        }

        // check if val2 is valid
        if (val2 > this->maxNumOfAirports || val2 <= 0)
        {
            cout << "Error " << val2 << " is not a valid airport. Please try again" << endl;
            return;
        }

        printf("Performing the shortest path Command from %d to %d\n", val1, val2);

    MyLinkList print= breathFirstSearch(val1,val2);
        
       Node* temp= print.getHead();
      // cout<<temp->data;
     //  cout<<temp->next->data;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
        cout<<endl;
        
    }

    //---------------------------------------------------------------------------------------------------------------------------------------------
    void depthFirstSearchHelper(int x, int y)
    {

        // mark all airports unvisisted
        int i;

        for (i = 0; i < maxNumOfAirports + 1; i++)
        {
            network[i].markUnVisited();
        }

        if (dfs(x, y) == true)
        {
            cout << "You can get from airport " << x << " to airport " << y << " in one or more flights" << endl;
        }
        else
        {
            cout << "You can NOT get from airport " << x << " to airport " << y << " in one or more flights" << endl;
        }
    }

    //---------------------------------------------------------------------------------------------------------------------------------------------
    bool dfs(int a, int b)
    {

        // traverse through the list for the current location
        Node *temp = network[a].getHeadPointer();

        // base case
        if (temp == NULL)
        {
            return false;
        }

        for (; temp != NULL; temp = temp->next)
        {

            // found it
            if (temp->data == b)
            {
                return true;
            }

            // mark visit or not
            if (network[temp->data].getVisitStatus() == false)
            {

                // mark it as visisted
                network[temp->data].markVisited();

                // recursive call
                if (dfs(temp->data, b) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    public: ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    MyLinkList breathFirstSearch(int x, int y)
    {
        MyLinkList AirQueue;  //a queue 
        MyLinkList pathlist;  // a stack to store the path
        int currentAirport=0;  //integer value to set the current path
        
        for (int i = 0; i < maxNumOfAirports + 1; i++)
        {
            network[i].setprev(-1);
            network[i].markUnVisited();// 
        }
       
        
        AirQueue.pushBack(x);
       

        if (bfs(y, AirQueue) == false)
        {
            cout << "You can NOT get from airport " << x << " to airport " << y << " in one or more flights"<<endl;
            
            return pathlist  ;
        }

        else
        {

            cout << "You can get from airport " << x << " to airport " << y << "  in one or more flights"<<endl;
            pathlist.deleteList();
             currentAirport = y;
            pathlist.addToFront(currentAirport);
            do{
                currentAirport=network[currentAirport].getprev();
                pathlist.addToFront(currentAirport);
            }
          
            while (currentAirport != x);
           

           return pathlist;
        }
        
      
    }
 private: ////////////////////////////////////////////////////////////////////////////////////////////////
    bool bfs(int b, MyLinkList &Apt)   //bool function which checks if the path is possible or not
    {

        while (Apt.isListEmpty() == false)   //while the queue is not empty pop the front value and process it.
        {
            int a = Apt.getFrontVal();
            
            Node *temp = network[a].getHeadPointer();
            Apt.removeFrontval();
            
            for (; temp != NULL; temp = temp->next)
            {
                if (network[temp->data].getVisitStatus() == false && network[temp->data].getprev()==-1)
                {
                    network[temp->data].markVisited();
                    
                    network[temp->data].setprev(a);
                   
                    if (temp->data == b)
                    {
                        return true;
                    }
                    Apt.pushBack(temp->data);
                    
                }
            }
        }
        return false;
    }

}; // end of travelnetwork class

//----------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // set up the variable inFile to read from standard input
    FILE *inFile = stdin;

    // set up the data needed for the airport adjcency list
    TravelNetwork airportData;
    airportData.showCommands();
        // call the method that reads and parses the input
        airportData.processCommandLoop(inFile);

    printf("Goodbye\n");
    return 1;
}