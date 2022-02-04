#include <stdio.h>
#include <string.h>

#include "Stack.h"

int main(int argc, char **argv){
  int i,j,k,v;
  char c1,c2;
  STACK s;
  s.top=NULL;
  s.size=0;
  //count of input
  for(i=1;i<argc;i++){
    //what input look like and v repersent answer
    for(j=0;j<strlen(argv[i]);j++){
      c1 = '\0';
      v = 1;
      k = 0; // k will check what char is
      switch(argv[i][j]){
        case '{': 
        case '[': push_s(&s,argv[i][j]); break;

        case '}': k = 1;
        case ']': c1 = pop_s(&s); break;
      }
      if(c1){
        if(k){
          if(argv[i][j] != '{'){
            v = 0;
            break;
          }
        }else{
            if(argv[i][j] != '['){
            v = 0;
            break;
          }
        } 
      }
      else{
        v = 0;
        break;
      } 
    }

    if(!isEmpty(&s)){
      clear(&s);
      v = 0;
    }

  }  
  
}



/*
    if(strcmp(argv[i],"x")==0){
      v = pop(&top); 
      printf("we pop ");
      if(v) printf("%d\n",v);
      else printf("Bruh\n");
    }
    else push(&top, atoi(argv[i]));

*/