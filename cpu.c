#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h> // a header file
// verify assumptions made by the program and print 
//a diagnostic message if this assumption is false
#include "common.h" // what is this ?

int main(int argc, char *argv[]){

     if (argc != 2){
          // int fprintf(FILE *stream, const char *format, ...)
          // sends formatted output to a stream.
          fprintf(stderr, "usage: cpu <string>\n");
          // stderr is the default file descriptor where a
          // process can write error messages.
     }
     char *str = argv[1];
     while(1){
          Spin(1);
          //To loop, basically. What a spinning 
          //function does is busy-waiting with a loop.
          printf("%s\n", str);
     }
     return 0;
}