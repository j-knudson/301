//This is the main file for a program that uses Kruskal's algorithm to build a Minimum Spanning Tree

#include <iostream>
#include <fstream>
#include <string>
#include "Partition.h"

//DATA MEMBER 
struct Graph       //Data type for storing each of the graph's connections: 2 vertices and their connecting edge weight
{
    int vertex1;    //The first vertex in the connection
    int vertex2;    //the second vertex in the connection
    int edgeWeight;   //the weight of the edge 
};

//function prototypes
void OpenInputFile(std::ifstream& in_f); //for opening a file 
//Postcondition: A file stream has been opened for input 
void heapSort(Graph A[], int size);
//Postcondition: Returns array sorted by value of edgeWeight data field in the Graph  
void reheapDown(Graph A[], int root, int last);
//Precondition: Root is element 0 of array to be converted into heap; last is final element 
//Postcondition: Root was moved down tree and into correct position to maintain heap property in tree
int kruskal(Graph sorted[], Partition tree, int edges);
//Precondition: sorted is an array where edges have been sorted by value small to large; edges is the number of (vertices-1) in the tree  
//Postcondition: MST edge connections printed as they are made; total cost of MST returned



//used in testing; no longer needed in main program 
void printGraph(Graph A[], int size); //for printing the contents of an array of Graphs in format: 'Vertex1 Vertex2 edgeWeight \n' 

int main()
{
    std::ifstream infile; // create an input filestream 
    OpenInputFile(infile); //call OpenInputFile to prompt user for a filename and open it 

    int verticesCount; infile >> verticesCount; //read the first character in the input file to get the count for number of vertices in the file 
    int maxEdges = (verticesCount * (verticesCount - 1)) / 2; // max edges is  [v * (v-1)]/2 
         

    Graph* graph = new Graph[maxEdges];      //create an array of Graphs for holding the values of the graph
    
    int index = 0; int edgeCount = 0;           //variable for the while loop index, and a new variable to find how many edges were in the files graph 
    while (index < maxEdges && infile >> graph[index].vertex1) //store vertex1 and continue loop until all lines in the file have been read; if can't input a value for vertex1 then file is empty  
    {
        //getLine 
        infile >> graph[index].vertex2;         //save vertex 2
        infile >> graph[index].edgeWeight;        //save the cost of their connection
        ++index;                                //move to the next line
        ++edgeCount;                            //keep track of edges (lines) counted in the file 
    }
    
    heapSort(graph, edgeCount);                 //sort the array by edge costs
    //printGraph(graph, edgeCount);
    Partition MST; //create a partition to store our MST 
    std::cout << "Minimum Spanning Tree: \n";
    int totalCost = kruskal(graph, MST, verticesCount);  //totalCost will keep track of the expense to navigate the MST 
    std::cout << "Total Cost: " << totalCost <<std::endl; 
    
    delete []graph;     //return Graph array graph
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

void printGraph(Graph A[], int size)
{
    for (int i = 0; i < size; i++)     //a loop to print the raw graph 
        std::cout << A[i].vertex1 << ' ' << A[i].vertex2 << ' ' << A[i].edgeWeight << '\n';
}


void heapSort(Graph A[], int size)   //A function to sort an array from lowest to highest value 
{
    for (int i = ((size - 2) / 2); i >= 0; --i) //start by making the heap 
    {
        reheapDown(A, i, size - 1);
    }

    for (int i = size - 1; i >= 0; --i)  //Move through all values in the heap 
    {
        std::swap(A[0], A[i]);          //switch last value in heap with the root
        reheapDown(A, 0, i - 1);        //move the new root to its position in the tree that restores heap property 
    }
}

void reheapDown(Graph A[], int root, int last)
{
    int parent;
    int maxChild;
    bool done = false;

    parent = root;
    while (2 * parent < last && !done)  //Check if the child of parent is still in the tree or we are out of values to compare
    {
        maxChild = 2 * parent + 1;      //children of a parent are 2*parent + 1; 2*parent+2 
        if (maxChild < last && A[(maxChild + 1)].edgeWeight>A[maxChild].edgeWeight)  //check if right child (maxChild+1) is the larger of the two children --> Sorting by weights so checking edgeWeight
            ++maxChild;
        if (A[parent].edgeWeight < A[maxChild].edgeWeight)      //if the parent is smaller than the child, swap them
        {
            std::swap(A[parent], A[maxChild]);
            parent = maxChild;

        }
        else
            done = true;

    }
}

int kruskal(Graph sorted[], Partition tree, int vertices)
{
    int edgesAdded = 0; //variable for holding edges added to the MST 
    int nextEdge;       //variable for holding the value of the next edge
    int sortedIndex = 0; //index for the Graph array
    int cost = 0; //value for holding the total spanning cost
    while (edgesAdded < vertices - 1)  //total edges in a MST is one less than the total number of vertices in the MST 
    {
        nextEdge = sorted[sortedIndex].edgeWeight; //get the next lowest cost edge from the sorted edges array 
        if (tree.uf_find(sorted[sortedIndex].vertex1) != tree.uf_find(sorted[sortedIndex].vertex2) ) //make sure adding that edge will not form a cycle 
        {
            tree.uf_union(sorted[sortedIndex].vertex1, sorted[sortedIndex].vertex2); //add the connection to the MST 
            ++edgesAdded;                           //incrementing edges --> keep track of edges added to know when MST is complete
            cost += sorted[sortedIndex].edgeWeight;   //add edge connection to the total spanning cost 
            std::cout << "Edge = (v" << sorted[sortedIndex].vertex1 << ",v" << sorted[sortedIndex].vertex2 << "); cost = " << sorted[sortedIndex].edgeWeight << "\n";  //Print the addition of the edge connection to the MST 
        }
        ++sortedIndex; //increment the index to advance loop and look at next lowest edge in the list 
    }
    return cost; //return the total cost of the MST 
}