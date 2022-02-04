#include <stdio.h>
#include <string.h>

#include "Stack.h"

int main(int argc, char **argv){
  int i,j,k,v;
  char c;
  STACK s;
  s.top=NULL;
  s.size=0;

  printf("Checking the parentheses in argv arguments\n");
  //count of input
  for(i=1;i<argc;i++){
    //what input look like and v repersent answer
    for(j=0;j<strlen(argv[i]);j++){
      c = '\0';
      v = 1;
      k = 0; // k will check what char is
      switch(argv[i][j]){
        case '{': 
        case '[': v++; push_s(&s,argv[i][j]); break;
        case '}': k = 1;
        case ']': c = pop_s(&s); break;
        default: ;
      }
      if(c){
        if(k){
          if(c != '{'){
            v --;
            break;
          }
        }else{
            if(c != '['){
            v --;
            break;
          }
        } 
      }
      else{
        if(isEmpty(&s)){
          v = 0;
          break;
        }else v --;  
      } 
    }

    if(!isEmpty(&s)) v = 0;
    if(v) printf("The parentheses match successfully for %s\n",argv[i]);
    else printf("The parentheses do not match for %s\n",argv[i]);
    clear(&s);
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