#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

int main(int argc, char **argv) {
   int i,v;
   NodePtr top=NULL;
   
   for(i=1;i<argc;i++){
    if(strcmp(argv[i],"x")==0){
      v = pop(&top); 
      printf("we pop ");
      if(v) printf("%d\n",v);
      else printf("Bruh\n");
    }
    else push(&top, atoi(argv[i]));

   }
  printf("\nOur stack is\n");
  printStack(&top);
  printf("\n");
}