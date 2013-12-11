typedef struct{
	void* data;
	int capacity;
	int elementSize;
	int front;
	int rear;
} Queue;

Queue* create(int capacity,int elementSize);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
int enqueue(Queue* queue, void* element);
void* dequeue(Queue* queue);

void dispose(Queue* queue);