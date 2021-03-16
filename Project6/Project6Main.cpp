#include <iostream>
#include <cstdlib>	//for size_t and rand()
#include <iomanip>  //for setw
#include "QueueADT.h"

//function declarations 
int shortestLine(Queue A[],int B[], int size, int time);		//this function finds the Queue in the array with the fewest number of elements * avg time + currentTime remaining
size_t totalQueue(Queue A[], int size);		//this function calculates and returns the total of the sizes of all Queues within the Queue array

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

	Queue* qArray = new Queue[userPairs];		//dynamically create an array of queues with size based on user input 
	int* servers = new int[userPairs] {};			//dyanmic array for number of servers to pair at 1:1 ratio with number of queues; intialize all values to zero signifying an open server		
	//Queue line; 
	int custServedCount = 0;		//number of customers served
	int waitSum = 0;	//sum of waiting times
	int entryTime;		//when each served customer arrived
	srand(seed);		//for use with rand function  

	for (int time = 0; time < simDuration; ++time)		//create a loop starting at time 0 and ending at user entered simDuration 
	{
		if (rand() % 100 < arvProb)	//use random number to determine if we add a person to the line 
		{
			int lineIndex = shortestLine(qArray, servers, userPairs, maxTransTime);	//call shortest line function to find the shortest line  
			qArray[lineIndex].enqueue(time);					//assign the new person to that line's queue
		}
		for (int i = 0; i < userPairs; i++)		//create a loop to move through queue/server pairs 
		{
			if (servers[i] == 0)			//check if the transaction for the current server is complete and server free
			{
				if (!qArray[i].isEmpty())	//if there are more people in queue
				{
					entryTime = qArray[i].dequeue(); //get the time from when the person went into the queue (value of element at i corresponds to time when i added to that queue)
					waitSum += (time - entryTime); //subtract entry time from current time to calculate how long person waited in line 
					++custServedCount;						//Increment count of customers served	
					servers[i] = (rand() % maxTransTime) + 1; //create a random transaction time  
				}
			}
			else				//transaction is still being completed
				--servers[i];	//decrement current element in severs to mimic that customer being helped in line 
			
			//print details to terminal
			std::cout << std::setw(4) <<"Server:"<< i+1 << std::setw(6) << " CT:" << time << std::setw(6) << "||TT:" << servers[i];			//CT == Current time   TT== Transaction Time  RL == Remaning Customers in line 
			std::cout << std::setw(7) << "||RL:" << qArray[i] << std::endl;  //prints elements of queue at qArray[i] 
		}
	}
	std::cout << custServedCount << " customers waited an average of "; 
	std::cout << waitSum / custServedCount << " ticks." << std::endl; 
	size_t remainLine = totalQueue(qArray, userPairs);
	std::cout << remainLine << " customers remain in the line." << std::endl; 
	
	delete[] qArray;		//remove qArray from heap
	delete[] servers;		//remove servers from heap 
	return EXIT_SUCCESS;
}

int shortestLine(Queue queArr[], int servArr[], int size, int time)
{
	Queue shortest = queArr[0];					//set current shortest line to the first queue
	int shortestIndex = 0;					//set current shortest index to first queue 
	for (int i = 0; i < size; ++i)			//loop to move through elements of queArr allowing us to find the smallest queue 
	{
		if ((queArr[i].size()*(time/2) + servArr[i]) < (shortest.size()*(time/2)+servArr[shortestIndex]))  //[number of people in queue * (maxTime/2) + time left on person checking out]  vs current smallest [queue * avgTime + current time left]
		{																	// is equivalent to QueueSize * ~ Avg Transaction Time + Time left on Transaction 
			shortest = queArr[i];
			shortestIndex = i;
		}
	}
	return shortestIndex; 
}

size_t totalQueue(Queue A[], int size)
{
	size_t total = 0;
	for (int i = 0; i < size; ++i)
	{
		total += A[i].size();
	}
	return total; 
}
