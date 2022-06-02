#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h> // a header file
// verify assumptions made by the program and print 
//a diagnostic message if this assumption is false
#include "common.h" // what is this ?

int main(int argc, char *argv[]){

     int *p = malloc(sizeof(int));
     assert(p != NULL);
     /*
     expression − This can be a variable or any 
     C expression. If expression evaluates to TRUE, 
     assert() does nothing. If expression evaluates 
     to FALSE, assert() displays an error message 
     on stderr (standard error stream to display 
     error messages and diagnostics) and aborts 
     program execution.
     */
     printf("(%d) address pointed to by p: %p\n", getpid(),p);
     *p = 0;

     while(1){
          Spin(1);
          //To loop, basically. What a spinning 
          //function does is busy-waiting with a loop.
          *p = *p + 1;
          printf("(%d) p: %d\n", getpid(),*p);
     }
     return 0;
}