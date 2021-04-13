//File Partition.h
//This is the header file for a Partition class which will be used to make a minimum spanning tree with Kruskal's algorithm


#ifndef PARTITION
#define PARTITION

class Partition
{
	public: 
		//Member Constant 
		static const int VERTICES = 42; //this can be any number; it is the possible number of vertices in the spanning tree
		
	
		//Default Constructor
		Partition(); //intitialize a partition to all singletons
	
		//Member Functions
		int uf_find(int x); 
		void uf_union(int x, int y); 
		//Precondition: x and y are not in the same partition tree

	private: 
		//Data Member --> The array of partitions 
		int partArr[VERTICES]; 
};

#endif 