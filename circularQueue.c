#include "circularQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Queue* create(int capacity, int elementSize){
	Queue* queue = calloc(1, sizeof(Queue));
	queue->data = calloc(capacity, elementSize);
	queue->capacity = capacity;
	queue->elementSize = elementSize;
	queue->front = -1;
	queue->rear = 0;
	return queue;
}


int isFull(Queue* queue){
	if(queue->front == queue->rear) return 1;
	return 0;
}

int isEmpty(Queue* queue){
	if(queue->front == -1) return 1;
	return 0;
}

int enqueue(Queue* queue, void* element){
	if(isFull(queue)) return 0;
	if(queue->front == -1) queue->front = 0;
	memcpy(queue->data+(queue->rear*queue->elementSize),element,queue->elementSize);
	queue->rear =(queue->rear + 1)%queue->capacity;
	return 1;
}

void* dequeue(Queue *queue){
	void *result;
	if(isEmpty(queue)) return NULL;
	result = calloc(1, queue->elementSize);
	memcpy(result, queue->data+(queue->front*queue->elementSize),queue->elementSize);
	queue->front = (queue->front + 1)%queue->capacity;
	if(queue->front == queue->rear){
		queue->front = -1;
		queue->rear = 0;
	}
	return result;
}

void dispose(Queue* queue){
	free(queue->data);
	free(queue);
}