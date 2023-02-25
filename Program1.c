/* CS261- HW1 - Program1.c*/
/* Name: Benjamin Anderson II
 * Date: 1/10/2023
 * Solution description:
    Initializes integer variables x, y, and z to random numbers ranging from 0 to 10.
    These are variables are then passed into a function that increments the first term,
    decrements the second, and sets the third to the difference between the first and second.
    The third value is them returned, and set to a different variable. Afterward a conclusion
    is printed to the screen.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    *a = *a + 1;

    /* Decrement  b */
    *b = *b - 1;

    /* Assign a-b to c */
    c = *a - *b;

    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z;
    x = rand() % 11;
    y = rand() % 11;
    z = rand() % 11;

    /* Print the values of x, y and z */
    printf("x: %d\ny: %d\nz: %d\n",x,y,z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    int* x_ptr = &x;
    int* y_ptr = &y;
    int val = foo(x_ptr, y_ptr, z);

    /* Print the values of x, y and z */
    printf("x:%d\ny:%d\nz:%d\n",x,y,z);


    /* Print the value returned by foo */
    printf("Value returned by foo: %d\n",val);

    /* Is the return value different than the value of z?  Why? */
    printf("The return value is different from the value of z, because z passed by value, meaning it was copied into the function, not given to the function.\n");
    return 0;
}
    
    
