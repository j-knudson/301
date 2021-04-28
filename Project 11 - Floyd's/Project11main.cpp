//This is the main file for a program to tests Floyd's algorithm finding the shortest path between vertices 

#include <iostream>
#include <fstream>
#include <limits>   //for max value
#include <iomanip> //for setw

//function prototypes 
void OpenInputFile(std::ifstream& in_f); //for opening a file 
//Postcondition: A file stream has been opened for input 
void PrintGraph(double* graph[], int size);
//Precondition: the graph is an array of arrays representing a square n x n matrix
//Postcondition: Then contents of the graph were printed to the terminal
void floyd(double* graph[], double* results[], double* path[], int size);
//Precondition: all three arrays are arrays of arrays representing a square n x n matrix
//Postcondition: the shortest path was calculated between all pairs of vertices represented by the matrix graph; 
    //the path weights are stored in results and the route is stored in path
void path(double* p[], int vertex1, int vertex2);
//Precondition: the graph p is an array of arrays representing a square n x n matrix
//Postcondition: the intermediate vertices on a connecting route was printed to the terminal 
void GetVertices(double* p[]);
//Precondition: the graph p is an array of arrays representing a square n x n matrix
//Postcondition: the user was prompted to input vertices and the shortest path between them was printed to the terminal 

int main()
{
    std::ifstream infile; // create an input filestream 
    OpenInputFile(infile); //call OpenInputFile to prompt user for a filename and open it 

    int verticesCount; infile >> verticesCount; //read the first character in the input file to get the count for number of vertices in the file 

    double** adjacencyMatrix = new double*[verticesCount]; //make an array to store the vertex and connection values from data file into an array
    
    //now a loop to turn the array into a dynamic 2d array to hold adjacency matrix 
    for (int i = 0; i < verticesCount; ++i)    //range from 0 to number of vertices in the graph              
    {
        adjacencyMatrix[i] = new double[verticesCount];  //this adds the columns to the rows 
    }

    double** resultsMatrix = new double* [verticesCount]; //now do the same thing to make a second matrix to hold the results  
    for (int i = 0; i < verticesCount; ++i)    //range from 0 to number of vertices in the graph              
    {
        resultsMatrix[i] = new double[verticesCount];  //this adds the columns to the rows 
    }

    double** shortestPathMatrix = new double* [verticesCount]; //now do the same thing to make a third matrix to hold the shortest path details  
    for (int i = 0; i < verticesCount; ++i)    //range from 0 to number of vertices in the graph              
    {
        shortestPathMatrix[i] = new double[verticesCount];  //this adds the columns to the rows 
    }  
     
    const double PATHMAX = std::numeric_limits<double>::max();  //create a max value constant used in the results matrix 

    //now read input from file and store in adjacencyMatrix while initializing shortestPathMatrix
    for (int m = 0; m < verticesCount; ++m)         //for rows of m x n matrix   (square matrix so they are the same)           
        for (int n = 0; n < verticesCount; ++n)     //for columns of m x n matrix 
        {
            infile >> adjacencyMatrix[m][n];        //store the value from the file (value = edgeCost between vertex m and n 
            resultsMatrix[m][n] = PATHMAX;          //set default connections to max value for finding shortest path 
            shortestPathMatrix[m][n] = -1;           //initialize values in shortestPathMatrix to -1
        }
    std::cout << "Here is the initial data: \n";
    PrintGraph(adjacencyMatrix, verticesCount); 
    std::cout << "Calling Floyd's algorithm and printing results: \n";
    floyd(adjacencyMatrix, resultsMatrix, shortestPathMatrix, verticesCount);  //call floyds to update shortestPathMatrix 
    PrintGraph(resultsMatrix, verticesCount);              //print results of shortestPathMatrix
    
    std::cout << "This is a display of P \n";
    PrintGraph(shortestPathMatrix, verticesCount);

    std::cout << "This graph has 1-" << verticesCount << " total vertices\n";
    GetVertices(shortestPathMatrix);


    //return dynamic arrays
    for (int i = 0; i < verticesCount; ++i)
    {
        delete[] adjacencyMatrix[i]; //delete columns
        delete[] resultsMatrix[i]; //delete columns
        delete[] shortestPathMatrix[i]; //delete columns
    }
  
    delete[] adjacencyMatrix; 
    delete[] resultsMatrix; 
    delete[] shortestPathMatrix;
    return EXIT_SUCCESS;
}

//******************************************************//
// ------- Function Definitions ---------// 


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
void PrintGraph(double* graph[], int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << " _ _ ";
    std::cout << '\n'; 
    std::cout << '\n';

    for (int m = 0; m < size; ++m)         //for rows of m x n matrix   (square matrix so they are the same)           
    {
        for (int n = 0; n < size; ++n)     //for columns of m x n matrix 
        {
            std::cout << std::setw(4) << graph[m][n] << ' ';        //store the value from the file (value = edgeCost between vertex m and n     
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


void floyd(double* graph[], double* results[], double* path[], int size)
{
    int i, j, k;  //vertex numbers and loop indices  
    for (i = 0; i < size; ++i)             //this copies original graph matrix into results matrix starting at vertex 0
        for (j = 0; j < size; ++j)
            results[i][j] = graph[i][j];        //results is now updated with the initial values of the adjacency matrix in graph 
    
    for (k = 0; k < size; ++k)            //We need to build the predecessor n-1 times; predecessor is updated results matrix using new intermediate vertex               
        for (i = 0; i < size; ++i)              //loop for rows  (m) 
            for (j = 0; j < size; ++j)               //loop for columns (n)
                if (results[i][k] + results[k][j] < results[i][j])  //check if path through intermediate vertex (K) is better than current path ([i][j])
                {
                    results[i][j] = results[i][k] + results[k][j];  //if the intermediate path is better update matrix to new weight ([i][k]+[k][j])
                    path[i][j] = k;                             //this is our shortest path matrix showing the route; update it to include the intermediate vertex
                }
}

void path(double* p[], int vertex1, int vertex2)
{
    int k; 

    k = p[vertex1][vertex2];
    if (k > -1)  //all non vertices are listed as -1
    {
        path(p, vertex1, k); 
        std::cout << k+1 << ' '; 
        path(p, k, vertex2); 
    }
}

void GetVertices(double* p[])
{
    std::cout << "Enter two vertex numbers for the path between them or '-1' to quit: \n";
    int v1, v2, userVert; 
    std::cin >> userVert; 
    while (userVert != -1)
    {
        v1 = userVert; 
        std::cin >> userVert; 
        v2 = userVert; 
        std::cout << "     Shortest path: ";
        std::cout << v1 << " "; 
        path(p, v1-1, v2-1);
        std::cout << v2; 
        std::cout << "\nEnter two vertex numbers or '-1' to quit: \n";
        std::cin >> userVert;
    }
}