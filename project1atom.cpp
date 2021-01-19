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
#include <iostream>

using namespace std;

//function declarations:

void OpenInputFile(ifstream& in_f);
//Opens for input a file named from the terminal
//Postcondition: A file stream has been opened for input
int Store(int A[], int size, ifstream& infile);
//reads values and stores them in array A
//Precondition: Infile is open and contains sorted values, aSize <=30
//Postcondition: Array A is updated with the read values, and total numbers
   //read by the array are returned
int MergeSorted(int A[], int B[], int C[], int sizeA, int sizeB);
//merges arrays A and B into C[]
//Precondition: A[] and B[] contain sorted values; C[] total size <=60;
    //sizeA, sizeB <= 30
//Postcondition: C[] updates to sort and include all unique values from
    //A[] and B[]  Total number of values in C[] is returned
void display(int A[], int low, int high, ostream& outfile);
//displays contents of an array
//Precondition: low and high are positive integers with low < high
//Postcondition: Contents of A[] were printed to selected output


int main()
{
    ifstream infile;  //Variable for holding input file
    OpenInputFile(infile);  //call function to open first input file

    const int INPUT_ARRAY_SIZE = 30; //Const variable for input arrays
    int A[INPUT_ARRAY_SIZE]; //create array A for storing values from first file

    int numbersProcessedFile1 = Store(A, INPUT_ARRAY_SIZE, infile); //call store function to read values from input file, store them in A,
                                                              //and record total number of values stored in numbersProcessed
    //TEST:
    //display(A, 0, numbersProcessedFile1, cout); //call display and  print values of array to terminal

    OpenInputFile(infile); //call function to open second input filename
    int B[INPUT_ARRAY_SIZE];
    int numbersProcessedFile2 = Store(B, INPUT_ARRAY_SIZE, infile);

    //TEST:
    //display(B,0, numbersProcessedFile2, cout);

    const int MERGED_ARRAY_SIZE = 60;           //const variable for merged array sized
    int C[MERGED_ARRAY_SIZE];                   //create an array to hold our merged values
    int totalNumbers = MergeSorted(A, B, C, numbersProcessedFile1, numbersProcessedFile2); //call function to merge arrays A and B into C
    display(C, 0, totalNumbers, cout);          //call function to display merged array
    cout <<endl;
    cout << "There are " <<totalNumbers << " distinct values\n"; //ouput total number of values stored in C

    return 0;
}

void OpenInputFile(ifstream& in_f)    //function to open an input file
{
    string input_filename;              //filename to be opened stored as string
    do {                                //do while to ensure file opens
        in_f.close();
        in_f.clear();
        cout << "Please enter an input file name: \n";
        cin >> input_filename;
        in_f.open(input_filename.c_str());
    } while (in_f.fail());
}

int Store(int A[], int size, ifstream& infile) //function to store values in array
{
    int counter = 0;
    while (counter < size && infile >> A[counter])
    {
        counter++;
    }
    return counter;
}

void display(int A[], int low, int high, ostream& outfile) //function to print contents of an array
{
    for (int i = low; i < high; i++)
    {
        outfile << A[i] << endl;
    }
}
int MergeSorted(int A[], int B[], int C[], int sizeA, int sizeB)
{
  int A_count = 0, B_count = 0, C_count = 0;    //counter variables to increment position in arrays
  while (A_count < sizeA && B_count < sizeB){   //loop while there are still elements in both A[] and B[]
    if (A[A_count]<=B[B_count]){                // check if A <=B determine if next element in C is from A
      if(A[A_count] == C[C_count-1]){             // if element is from A, check if it is already in C to prevent duplicates
          A_count++;                            //increment A
          continue;}
      else
      {
        C[C_count]=A[A_count];                  //if it is not already in C then it becomes next element in C
        A_count++; C_count++;                   //increment A and C
      }
    }
    else{                                       // B < A then B becomes next value in C
      if(B[B_count]== C[C_count-1]){               // Check if B value is a duplicate already in C
        B_count++;                              // increment B to move to next element in B
        continue;}
      else                                      //If B is not already in C place it there and increment B and C
      {
          C[C_count] = B[B_count];
          B_count++;
          C_count++;
      }
    }
  }
  while (A_count < sizeA)                       //If all elements of B complete but not A
  {
      if(A[A_count] == C[C_count-1]){             // if element is from A, check if it is already in C to prevent duplicates
        A_count++;                              //increment A
        continue;}
      else{
        C[C_count]=A[A_count];                  //if it is not already in C then it becomes next element in C
        A_count++;                              //increment A
        C_count++;                              //increment C
      }
  }
  while (B_count < sizeB)                       //If all elements of A complete but not B
  {

      if(B[B_count] == C[C_count-1]){             //Check if it is already in C to prevent duplicates
        B_count++;                              //increment B
        continue;}
      else
      {
        C[C_count]=B[B_count];                  //if it is not already in C then it becomes next element in C
        B_count++;                              //increment B
        C_count++;                              //increment C
      }
  }
  return C_count;                               //return count of number of values in C
}
