#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TASKS 10
//#define TIME_SLICE 10

typedef struct {
int id;
void (*taskFunc)(void);
bool ready;
} TCB;

TCB tasks[MAX_TASKS];
int taskCount = 0;
int currentTask = 0;

void assertIntEquals(int expected, int actual, const char* testName) {
printf("%s: %s\n", testName, expected == actual ? "PASSED" : "FAILED");
}
/*
void assertBoolEquals(bool expected, bool actual, const char* testName) {
printf("%s: %s\n", testName, expected == actual ? "PASSED" : "FAILED");
}
*/
void addTask(void (*taskFunc)(void)) {
if (taskCount < MAX_TASKS) {
tasks[taskCount].id = taskCount;
tasks[taskCount].taskFunc = taskFunc;
tasks[taskCount].ready = true;
taskCount++;
}
}

void schedule(void) {
if (taskCount == 0) return;
if (tasks[currentTask].ready) {
tasks[currentTask].taskFunc();    // run task 1
}
currentTask = (currentTask + 1) % taskCount;
}
// Sample task

int task1Counter = 0;

void task1(void)
{
       	task1Counter++;
}
// Unit tests
void main()
{
task1Counter = 0;
addTask(task1);
addTask(task1);
addTask(task1);

schedule();
schedule();
//schedule();
assertIntEquals(2, task1Counter, "Test 451.1 - Task executed");
}

