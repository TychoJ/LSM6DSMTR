#include <stdio.h>
#include <stdint.h>
// A normal function with an int parameter
// and void return type
void fun(int a) {
    printf("Value of a is %d\n", a);
}

typedef struct {
    void (*fun_ptr)(int);
}type_t;

void printToTen(type_t type) {
    for (uint8_t i = 0; i < 11; i++) {
        type.fun_ptr(i);
    }
    
}

int main()
{
    // fun_ptr is a pointer to function fun() 
    //void (*fun_ptr)(int) = &fun;
    type_t type;

    type.fun_ptr = &fun;
  
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    //(*fun_ptr)(10);
    //type.fun_ptr(16);
    printToTen(type);
  
    return 0;
}