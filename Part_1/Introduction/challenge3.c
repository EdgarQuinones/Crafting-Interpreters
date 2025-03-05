#include <stdio.h> // for input/output
#include <stdlib.h> // for malloc
#include <string.h> // for strcpy

// practice struct
struct Person {
    char *name;
    int age;
};

/*
    Challenge: Doubly-linked list, of heap-allocated strings
    functions: insert, find, delete

    struct: 
    - pointer to previous node,
    - pointer to next node,
    - string, made from heap
*/
struct Node {
    struct Node *previousNode;
    struct Node *nextNode;
    char *data;
};

int main() {
    printf("hello, world!\n"); // Part 1, done

    struct Person p1; 
    p1.age = 2;
    // printf("%d\n",p1.age);

    // Integers 
    printf("int size: %d bytes\n",(int)sizeof(int));
    printf("short size: %d bytes\n",(short)sizeof(short));
    printf("long size: %ld bytes\n",(long)sizeof(long));
    printf("long long size: %lld bytes\n",(long long)sizeof(long long));

    // Floats 
    printf("float size: %f bytes\n",(float)sizeof(float));
    printf("double size: %f bytes\n",(double)sizeof(double));
    printf("long double size: %Lf bytes\n",(long double)sizeof(long double));

    // Char, use %c for characters
    printf("char size: %d byte\n",(int)sizeof(char));

    // malloc
    int *ptr = (int *) malloc(sizeof(int)); // allocates 4 byts for an int
    *ptr = 10;
    printf("The value of the pointer is %d\n",*ptr);
    free(ptr);

    // Array of size 4
    int size = 4;
    int *intArray = (int *)(malloc(sizeof(int) * size));
    intArray[1] = 2;
    printf("index 0 POINTER: %p\n", &intArray[0]);
    printf("index 1 POINTER: %p\n", &intArray[1]);
    free(intArray);
    // Testing doubly-linked list
    /*
    struct Node {
    struct *Node previousNode;
    struct *Node nextNode;
    char *data;
    }    
    */

    int strSize = 5;

    struct Node node1;
    // + 1 for null terminator
    node1.data = (char *) (malloc(sizeof(char) * (strSize + 1)));
    
    if (node1.data != NULL) {
        strcpy(node1.data, "hello");
    }
    else {
        printf("Malloc failed.");
        return 1;
    }
    printf("String: %s\n", node1.data);
    free(node1.data);
    
    // 3 pointers, at 8 bytes each is 24 bytes 
    printf("Node size: %d bytes\n",(int)sizeof(struct Node));
    char *string1 = "Hello";
    char *string2 = "World!";
    char *string3 = "UM!";

    struct Node *nodeA = (struct Node *) malloc(sizeof(struct Node));
    struct Node *nodeB = (struct Node *) malloc(sizeof(struct Node));
    struct Node *nodeC = (struct Node *) malloc(sizeof(struct Node));

    // setting up nodes 
    //A
    nodeA->data = (char*) malloc(sizeof(char) * (strlen(string1) + 1));
    strcpy(nodeA->data, string1);
    nodeA->nextNode = nodeB;
    nodeB->previousNode = nodeA;
    //B
    nodeB->data = (char*) malloc(sizeof(char) * (strlen(string2) + 1));
    strcpy(nodeB->data, string2);
    nodeB->nextNode = nodeC;
    nodeC->previousNode = nodeB;
    //C
    nodeC->data = (char*) malloc(sizeof(char) * (strlen(string3) + 1));
    strcpy(nodeC->data, string3);
    
    // Print the strings stored in each node
    printf("Node A data: %s\n", nodeA->data);
    printf("Node B data: %s\n", nodeB->data);
    printf("Node C data: %s\n", nodeC->data);

    //Testing if they are linked.
    char* aStr = nodeC->previousNode->previousNode->data;
    printf("This should be 'Hello', actual answer: %s\n", aStr);

    //free the items inside the struct pointers
    free(nodeA->data);
    free(nodeB->data);
    free(nodeC->data);

    // free the struct pointers 
    free(nodeA);
    free(nodeB);
    free(nodeC);

    return 0;
}