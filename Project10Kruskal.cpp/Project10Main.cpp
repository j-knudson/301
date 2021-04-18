//This is the main file for a program that uses Kruskal's algorithm to build a Minimum Spanning Tree

#include <iostream>
#include <fstream>
#include <string>
#include "Partition.h"

//DATA MEMBER 
struct Record       //Data type for storing each of the graph's connections:2 vertices and their connecting edge weight
{
    int vertex1;    //The first vertex in the connnection
    int vertex2;    //the second vertext in the connection
    int edgeCost;   //the weight of the edge 
};

//function prototypes
void OpenInputFile(std::ifstream& in_f); //for opening a file 
//Postcondition: A file stream has been opened for input 
void heapSort(Record A[], int size);
//Postcondition: Returns array sorted by value of edgeCost data field in the Record  
void reheapDown(Record A[], int root, int last);
//Precondition: Root is element 0 of array to be converted into heap; last is final element 
//Postcondition: Root was moved down tree and into correct position to maintain heap property in tree
int kruskal(Record sorted[], Partition tree, int edges);
//Precondition: sorted is an array where edges are sorted by value small to large; edges is the number of (vertices-1) in the tree  
//Postcondition: MST edge connections printed as they are made; total cost of MST returned



//used in testing; no longer needed in main program 
void printRecord(Record A[], int size); //for printing the contents of an array of Records in format: 'Vertex1 Vertex2 EdgeCost \n' 

int main()
{
    std::ifstream infile; // create an input filestream 
    OpenInputFile(infile); //call OpenInputFile to prompt user for a filename and open it 

    int verticesCount; infile >> verticesCount; //read the first character in the input file to get the count for number of vertices in the file 
    int maxEdges = (verticesCount * (verticesCount - 1)) / 2; // max edges is  [v * (v-1)]/2 
         

    Record* graph = new Record[maxEdges];      //create an array of records for holding the values of the graph
    
    int index = 0; int edgeCount = 0;           //variable for the while loop index, and a new variable to find how many edges were in the files graph 
    //while(index < maxEdges && !infile.eof())    //Loop to store values in the input file into the Record array named graph
    while (index < maxEdges && infile >> graph[index].vertex1) //store vertex1 and continue loop until all lines in the file have been read; if can't input a value for vertex1 then file is empty  
    {
        //getLine 
        infile >> graph[index].vertex2;         //save vertex 2
        infile >> graph[index].edgeCost;        //save the cost of their connection
        ++index;                                //move to the next line
        ++edgeCount;                            //keep track of edges (lines) counted in the file 
    }
    
    heapSort(graph, edgeCount);                 //sort the array by edge costs
    //printRecord(graph, edgeCount);
    Partition MST; //create a partition to store our MST 
    std::cout << "Minimum Spanning Tree: \n";
    int totalCost = kruskal(graph, MST, verticesCount);  //totalCost will keep track of the expense to navigate the MST 
    std::cout << "Total Cost: " << totalCost <<std::endl; 
    
    delete []graph;     //return Record array graph
    return EXIT_SUCCESS; 
}

void OpenInputFile(std::ifstream& in_f)    //function to open an input file
{
    std::string input_filename;              //filename to be opened stored as string
    do {                                //do while to ensure file opens
        in_f.close();
        in_f.clear();
        std::cout << "Please enter an input file name: \n";
        std::cin >> input_filename;
        in_f.open(input_filename.c_str());
    } while (in_f.fail());
}

void printRecord(Record A[], int size)
{
    for (int i = 0; i < size; i++)     //a loop to print the raw graph 
        std::cout << A[i].vertex1 << ' ' << A[i].vertex2 << ' ' << A[i].edgeCost << '\n';
}


void heapSort(Record A[], int size)
{
    for (int i = ((size - 2) / 2); i >= 0; --i) //make the heap 
    {
        reheapDown(A, i, size - 1);
    }

    for (int i = size - 1; i >= 0; --i)
    {
        std::swap(A[0], A[i]);
        reheapDown(A, 0, i - 1);
    }
}

void reheapDown(Record A[], int root, int last)
{
    int parent;
    int maxChild;
    bool done = false;

    parent = root;
    while (2 * parent < last && !done)  //Check if the child of parent is still in the tree or we are out of values to compare
    {
        maxChild = 2 * parent + 1;      //children of a parent are 2*parent + 1; 2*parent+2 
        if (maxChild < last && A[(maxChild + 1)].edgeCost>A[maxChild].edgeCost)  //check if right child (maxChild+1) is the larger of the two children --> Sorting by weights so checking edgeCost
            ++maxChild;
        if (A[parent].edgeCost < A[maxChild].edgeCost)      //if the parent is smaller than the child, swap them
        {
            std::swap(A[parent], A[maxChild]);
            parent = maxChild;

        }
        else
            done = true;

    }
}

int kruskal(Record sorted[], Partition tree, int vertices)
{
    int edgesAdded = 0; //variable for holding edges added to the MST 
    int nextEdge;       //variable for holding the value of the next edge
    int sortedIndex = 0; //index for the Record array
    int cost = 0; //value for holding the total spanning cost
    while (edgesAdded < vertices - 1)  //total edges in a MST is one less than the total number of vertices in the MST 
    {
        nextEdge = sorted[sortedIndex].edgeCost; //get the next lowest cost edge from the sorted edges array 
        if (tree.uf_find(sorted[sortedIndex].vertex1) != tree.uf_find(sorted[sortedIndex].vertex2) ) //make sure adding that edge will not form a cycle 
        {
            tree.uf_union(sorted[sortedIndex].vertex1, sorted[sortedIndex].vertex2); //add the connection to the MST 
            ++edgesAdded;                           //incrementing edges --> keep track of edges added to know when MST is complete
            cost += sorted[sortedIndex].edgeCost;   //add edge connection to the total spanning cost 
            std::cout << "Edge = (v" << sorted[sortedIndex].vertex1 << ",v" << sorted[sortedIndex].vertex2 << "); cost = " << sorted[sortedIndex].edgeCost << "\n";  //Print the addition of the edge connection to the MST 
        }
        ++sortedIndex; //increment the index to advance loop and look at next lowest edge in the list 
    }
    return cost; //return the total cost of the MST 
}