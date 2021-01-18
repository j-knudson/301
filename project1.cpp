//Project 1
//John Knudson
//CSCI 301 Comp Sci 2 - Julstrom

/* This program will prompt the user for two filenames and read
up to 30 sorted values from each file. It will then merge those
values into a sorted array while ignoring duplicate values.

It will then print the final array and display the total values stored
in that array */

 #include <iomanip>
 #include <cstring>
 #include <fstream>
 #include <cstdlib>

 using namespace std;

//function declarations:

 void OpenInputFile(ifstream& infile)
 //Opens for input a file named from the terminal
 //Postcondition: A file stream has been opened for input
 int Store(int A[], int aSize,)
 //reads values and stores them in array A
 //Precondition: An file is open and contains sorted values, aSize <=30
 //Postcondition: Array A is updated with the read values, and total numbers
    //read by the array are returned
int MergeSorted(int A[], int B[], int C[], int sizeA, int sizeB)
//merges arrays A and B into C[]
//Precondition: A[] and B[] contain sorted values; C[] total size <=60;
    //sizeA, sizeB <= 30
//Postcondition: C[] updates to sort and include all unique values from
    //A[] and B[]  Total number of values in C[] is returned
void display(int A[], int low, int high, ostream& outfile)
//displays contents of an array
//Precondition: low and high are positive integers with low < high
//Postcondition: Contents of A[] were printed to selected output
