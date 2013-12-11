#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "testUtils.h"
#include "circularQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue* integerQueue;

void setup(){
	integerQueue = create(3, sizeof(int));
}

void tearDown(){
	dispose(integerQueue);
}

int areQueueEqual(Queue* expected,Queue* actual){
	int result = expected->elementSize == actual->elementSize
					&& expected->capacity == actual->capacity 
					&& expected->front	== actual->front 
					&& expected->rear	== actual->rear;
	if(!result) return result;
	if(isEmpty(expected)) return result;
	return 0 == memcmp(expected->data, actual->data,(expected->capacity-1)*(expected->elementSize));
}

void test_create_an_circular_queue_with_initial_value_as_zero(){
	Queue* actual = create(3,sizeof(int));
	int data[3] = {0,0,0};
	Queue expected = {&data,3,sizeof(int),-1,0};
	ASSERT(areQueueEqual(&expected, actual));
}

void test_inserting_element_in_integer_queue(){
	int data[3] = {8,0,0};
	int _8 = 8;
	Queue expected = {&data,3,sizeof(int),0,1};
	ASSERT(enqueue(integerQueue, &_8));
	ASSERT(areQueueEqual(&expected,integerQueue));
}

void test_inserting_element_in_queue_having_rear_equals_to_capacity_minus_1(){
	int data[3] = {0,0,8};
	Queue expected = {&data,3,sizeof(int),0,0};
	int _8 = 8;
	integerQueue->rear = 2;
	integerQueue->front = 0;
	ASSERT(enqueue(integerQueue, &_8));
	ASSERT(areQueueEqual(&expected,integerQueue));
}


void test_inserting_integer_in_full_queue(){
	int data[3] = {0,0,0};
	int _8 = 8;
	Queue expected = {&data,3,sizeof(int),0,0};
	integerQueue->front = 0;
	integerQueue->rear = 0;
	ASSERT(0 == enqueue(integerQueue, &_8));
	ASSERT(areQueueEqual(&expected,integerQueue));
}


void test_deleting_integer_from_queue(){
	int data[3] = {8,4,0};
	int _8 = 8,_4 = 4;
	Queue expected = {&data,3,sizeof(int),1,2};
	enqueue(integerQueue, &_8);
	enqueue(integerQueue, &_4);
	ASSERT(8 == *(int*)dequeue(integerQueue));
	ASSERT(areQueueEqual(&expected,integerQueue));
}


void test_deleting_integer_from_an_empty_queue(){
	int data[3] = {0,0,0};
	Queue expected = {&data,3,sizeof(int),-1,0};
	ASSERT(NULL == dequeue(integerQueue));
	ASSERT(areQueueEqual(&expected,integerQueue));
}

void test_deleting_integer_from_queue_having_only_one_element(){
	int data[3] = {8,0,0};
	int _8 = 8;
	Queue expected = {&data,3,sizeof(int),-1,0};
	enqueue(integerQueue, &_8);
	ASSERT(8 == *(int*)dequeue(integerQueue));
	ASSERT(areQueueEqual(&expected,integerQueue));
}


void test_deleting_integer_from_queue_where_front_is_eual_to_rear_minus_one(){
	int data[3] = {8,0,0};
	int _8 = 8;
	Queue expected = {&data,3,sizeof(int),-1,0};
	enqueue(integerQueue, &_8);
	ASSERT(8 == *(int*)dequeue(integerQueue));
	ASSERT(areQueueEqual(&expected,integerQueue));
}

void test_deleting_integer_from_queue_having_front_equals_to_capacity_minus_one(){
	int data[3] = {4,0,8};
	int _8 = 8,_4 = 4;
	Queue expected = {&data,3,sizeof(int),0,1};
	integerQueue->rear = 2;
	integerQueue->front = 1;
	enqueue(integerQueue, &_8);
	enqueue(integerQueue, &_4);
	dequeue(integerQueue);
	ASSERT(8 == *(int*)dequeue(integerQueue));
	ASSERT(areQueueEqual(&expected,integerQueue));
}

