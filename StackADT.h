//This is the header file for program that uses an array stack ADT 

//file StackADT.h
//CLASS Provided: Stack    

#include <iostream>  //provides ostream
#include <cstdlib>   //provides size_t

#ifndef STACK
#define STACK

class Stack
{
    public:
        typedef char Item;          //Typedef for the stack, currently set to a char
       
                                    
        //member constant
        static const int CAPACITY = 100;        //Max size for stack array; currently 100 

        //constructor
        Stack() {used = 0; }           //INLINE: Starts an empty stack where used is 0 

        //Modification member functions
        void push(Item entry);  //this function adds (pushes) an item onto the stack 
        //Precondition: size() < capacity --> there is room in the stack for a new item
        //Postcondition: entry was pushed onto the stack
        Item pop(); //this function removes (pops) an item from the stack 
        //Precondition: the stack is not empty 
        //Postcondition: The top (highest/most recently added) item in the stack was returned

        //constant member functions
        size_t size() { return used; }  //Return the number of items in the stack
        //Postcondition: The quantity of items in the stack was returned 

        bool empty() { return used == 0; }  //INLINE: Reports whether the stack is empty (TRUE) or not empty (FALSE)
        //Postcondition: Reports whether the stack is empty (TRUE) or not empty (FALSE)

    private:
        // Data members
        Item data[CAPACITY];        //this creates an array with size set by our constant CAPACITY 
        int used;       //this variable holds the count of items in a stack 

		

};

#endif

