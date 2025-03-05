#include <stdio.h> // for input/output
#include <stdlib.h> // for malloc

struct Person {
    char *name;
    int age;
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

    return 0;
}