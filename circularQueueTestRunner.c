#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_an_circular_queue_with_initial_value_as_zero");
	setup();
		test_create_an_circular_queue_with_initial_value_as_zero();
	tearDown();
	testEnded();
	testStarted("test_inserting_element_in_integer_queue");
	setup();
		test_inserting_element_in_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_inserting_element_in_queue_having_rear_equals_to_capacity_minus_1");
	setup();
		test_inserting_element_in_queue_having_rear_equals_to_capacity_minus_1();
	tearDown();
	testEnded();
	testStarted("test_inserting_integer_in_full_queue");
	setup();
		test_inserting_integer_in_full_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_integer_from_queue");
	setup();
		test_deleting_integer_from_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_integer_from_an_empty_queue");
	setup();
		test_deleting_integer_from_an_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_deleting_integer_from_queue_having_only_one_element");
	setup();
		test_deleting_integer_from_queue_having_only_one_element();
	tearDown();
	testEnded();
	testStarted("test_deleting_integer_from_queue_where_front_is_eual_to_rear_minus_one");
	setup();
		test_deleting_integer_from_queue_where_front_is_eual_to_rear_minus_one();
	tearDown();
	testEnded();
	testStarted("test_deleting_integer_from_queue_having_front_equals_to_capacity_minus_one");
	setup();
		test_deleting_integer_from_queue_having_front_equals_to_capacity_minus_one();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
