Time limit: 5000ms
Memory limit: 256mb

Description:
Given a series of queue operations, please complete the queue ADT to output for respective operations.

-------------------------Copy the following code, complete it and submit-------------------------

/*
I, <Your Full Name>, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {enqueue = 1, dequeue, end, isfull, isempty} Operation;

struct Queue {
    int * arr;
    int capacity;
    int front;
    int rear;
};

struct Queue * Create(int capacity) {
    struct Queue * queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->arr = (int*)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int IsFull(struct Queue * queue) {
    // write your code here
}

int IsEmpty(struct Queue * queue) {
    // write your code here
}

int Enqueue(struct Queue * queue, int x) {
    // write your code here
}

int Dequeue(struct Queue * queue) {
    // write your code here
}

Operation Getop() {
    char str[10];
    scanf("%s", str);
    if (strcmp(str, "Enqueue") == 0) {
        return 1;
    }
    else if (strcmp(str, "Dequeue") == 0) {
        return 2;
    }
    else if (strcmp(str, "End") == 0) {
        return 3;
    }
    else if (strcmp(str, "Isfull") == 0) {
        return 4;
    }
    else if (strcmp(str, "Isempty") == 0) {
        return 5;
    }
    else {
        return 0;
    }
}

void printArray(struct Queue * queue) {
    int curr;
    curr = queue->front;
    if (!IsEmpty(queue)){
        while((curr+1)%queue->capacity != queue->rear){
            printf("%d ", queue->arr[curr]);
            curr = (curr + 1)%queue->capacity;
        }
        printf("%d\n", queue->arr[curr]);
    }
}

int main(void) {
    int X;
    int capacity;
    struct Queue * queue;
    int flag = 0;

    scanf("%d", &capacity);
    queue = Create(capacity);
    while (!flag) {
        switch(Getop()) {
            case enqueue:
                scanf("%d", &X);
                if (Enqueue(queue, X) == 1e5) {
                    printf("Queue is full\n");
                }
                break;
            case dequeue:
                X = Dequeue(queue);
                if (X == 1e5) {
                    printf("Queue is empty\n");
                }
                break;
            case end:
                printArray(queue);
                flag = 1;
                break;
            case isfull:
                if (IsFull(queue)){
                    printf("Queue is full\n");
                }
                else{
                    printf("Queue is not full\n");
                }
                break;
            case isempty:
                if (IsEmpty(queue)){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is not empty\n");
                }
                break;
        }
    }
    return 0;
}

-------------------------------------------End of Code-------------------------------------------

Input:
The first line is a positive integer N, which denotes the capacity of the queue, followed by M lines of queue operations, each chosen from one of the followings: Enqueue x(an integer), Dequeue, Isfull and Isempty, except the last of which, which is End.
1 <= N <= 1,000,000;
1 <= M <= 20,000.

Output:
A line per Dequeue (if queue is empty), Isfull or Isempty operation, each denoting the output of the specified operation, following by a line of remaining elements in the queue from head to tail upon End.

Sample Input 1:
4
Dequeue
Enqueue 1
Enqueue 2
Dequeue
End

Sample Output 1:
Queue is empty
2

Sample Input 2:
2
Isempty
Enqueue 1
Isfull
Enqueue 2
End

Sample Output 2:
Queue is empty
Queue is full
Queue is full
1
