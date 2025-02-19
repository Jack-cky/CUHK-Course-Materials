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

typedef enum {enqueue = 1, dequeue, end} Operation;

typedef struct Node * PtrToNode;

struct Node{
    int element;
    PtrToNode next;
    PtrToNode prev;
};

typedef struct ListRecord * List;

struct ListRecord {
    PtrToNode head;
    PtrToNode tail;
};

List Create() {
    List L;
    L = (List)malloc(sizeof(struct ListRecord));
    L->head = (PtrToNode)malloc(sizeof(struct Node));
    L->head->prev = NULL;
    L->tail = (PtrToNode)malloc(sizeof(struct Node));
    L->head->next = L->tail;
    L->tail->prev = L->head;
    L->tail->next = NULL;
    return L;
}

void Insertion(int x, List L) {
    // write your code here
}

int Deletion(List L) {
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
    else {
        return 3;
    }
}

void printList(List L) {
    PtrToNode ptr;
    ptr = L->head->next;
    while(ptr != L->tail) {
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
}

int main(void) {
    int X;
    List L;
    int flag = 0;

    L = Create();
    while (!flag) {
        switch(Getop()) {
            case enqueue:
                scanf("%d", &X);
                Insertion(X, L);
                break;
            case dequeue:
                X = Deletion(L);
                if (X == 1e5) {
                    printf("Queue is empty\n");
                }
                break;
            case end:
                printList(L);
                flag = 1;
                break;
        }
    }
    return 0;
}

-------------------------------------------End of Code-------------------------------------------

Input:
M lines of queue operations, each chosen from one of the followings: Enqueue x(an integer) and Dequeue, except the last of which, which is End.

Output:
A line per Dequeue (if queue is empty) operation, denoting the queue is empty, following by a line of remaining elements in the queue from head to tail upon End

Sample Input 1:
Dequeue
Enqueue 1
Enqueue 2
Dequeue
End

Sample Output 1:
Queue is empty
2

Sample Input 2:
Dequeue
Enqueue 1
Dequeue
End

Sample Output 2:
Queue is empty
