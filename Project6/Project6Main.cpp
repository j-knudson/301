/*
	John Knudson 
	CSCI 301 - Julstrom 
	Project 6 -- Queuing Simulation with a Queue ADT 
*/

#include <iostream>
#include <cstdlib>	//for size_t and rand()
#include <iomanip>  //for set w
#include "QueueADT.h"

//function declarations 

Queue shortestLine(); 


int main()
{
	
	std::cout << "Please enter an integer for the number of queue/server pairs (Minimum value 1): \n";		//prompt user for number of queues and servers 
	int userPairs; 
	std::cin >> userPairs; 

	std::cout << "Please enter an integer for the probability that a customer will arrive in a single tick (1 - 100)\n";  //prompt user for arrival probabilty 
	int arvProb; 
	std::cin >> arvProb;		//percentage chance of a customer arriving in a time interval 

	std::cout << "Please enter an integer for the maximum duration of a transaction in ticks: \n"; //Longest time a customer will stand in line 
	int maxTransTime; 
	std::cin >> maxTransTime; 

	std::cout << "Please enter an integer for the duration of the simulation in ticks: \n"; //Total time for the simulation 
	int simDuration; 
	std::cin >> simDuration; 

	std::cout << "Please enter a random number seed: \n ";
	int seed; 
	std::cin >> seed; 
	
	//Queue qArray[userPairs]; 
	Queue line; 
	int custServedCount = 0;		//number of customers served
	int waitSum = 0;	//sum of waiting times
	int transTime = 0;	//time it takes for a transaction
	int entryTime;		//when each served customer arrived
	srand(seed);		//for use with rand function  

	for (int time = 0; time < simDuration; ++time)
	{
		if (rand() % 100 < arvProb)	//use random number to determine if we add a person to the line 
			line.enqueue(time);
		if (transTime == 0)			//check if the transaction is complete
		{
			if (!line.isEmpty())	//if there are more people in queue
			{
				entryTime = line.dequeue(); //get the time from when the person went into the queue 
				waitSum += (time - entryTime); //subtract entry time from current time to calculate how long person waited in line 
				++custServedCount;						//Increment count of customers served	
				transTime = (rand() % maxTransTime) + 1; //create a random transaction time  
			}
		}
		else				//transaction is still being completed
			--transTime;	//decrement transTime to mimic customer being helped in line 
		std::cout << std::setw(6) << " CT:" << time << std::setw(6) << "||TT:"<< transTime;
		std::cout<< "||RL:" << line << std::endl;  //print details to terminal
	}
	std::cout << custServedCount << " customers waited an average of "; 
	std::cout << waitSum / custServedCount << " ticks." << std::endl; 
	std::cout << line.size() << " customers remain in the line." << std::endl; 
	return EXIT_SUCCESS;
}

