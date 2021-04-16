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
void printRecord(Record A[], int size); //for printing the contents of an array of Records in format: 'Vertex1 Vertex2 EdgeCost \n' 
void heapSort(Record A[], int size);
void reheapDown(Record A[], int root, int last);


int main()
{
    std::ifstream infile; // create an input filestream 
    OpenInputFile(infile); //call OpenInputFile to prompt user for a filename and open it 
    Partition p; //a new parition which will hold values for making a MST with Kruskal's

    int verticesCount; infile >> verticesCount; //read the first character in the input file to get the count for number of vertices in the file 
    int maxEdges = (verticesCount * (verticesCount - 1)) / 2; // max edges is  [v * (v-1)]/2 
    //TEST: 
    //std::cout << verticesCount; 
    // \test
    


        
    Record* graph = new Record[maxEdges];      //create an array of records for holding the values of the graph
    
    int index = 0; int edgeCount = 0;           //variable for the while loop index, and a new variable to find how many edges were in the files graph 
    while(index < maxEdges && !infile.eof())    //Loop to store values in the input file into the Record array named graph
    {
        //getLine 
        infile >> graph[index].vertex1;
        infile >> graph[index].vertex2;
        infile >> graph[index].edgeCost;
        ++index; 
        ++edgeCount; 
    }
    
    //TEST: 
    //std::cout << graph[0].vertex1 << ' ' << graph[0].vertex2 << ' ' << graph[0].edgeCost <<'\n'; 
    // \Test


    //for (int i = 0; i < edgeCount; i++)     //a loop to print the raw graph 
       // std::cout << graph[i].vertex1 << ' ' << graph[i].vertex2 << ' ' << graph[i].edgeCost << '\n';
    heapSort(graph, edgeCount);         //sort the array by edge costs
    printRecord(graph, edgeCount);
    
    delete []graph; 
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