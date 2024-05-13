typedef struct{
	int* array;
	int head, tail, size;
	int capacity;
}queue;



queue* newQueue(int capacity){
	
	queue* myQueue = (queue*) malloc (sizeof(queue));
	myQueue -> capacity = capacity;
	myQueue -> head = 0;
	myQueue -> size = 0;
	myQueue -> tail = capacity - 1;
	myQueue -> array = (int*) malloc(myQueue -> capacity * sizeof(int));
	
	return myQueue;
}
