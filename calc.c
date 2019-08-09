/***
* Name: Jing Xuan Long
* ID: 1022621
* Email: jlong04@uoguelph.ca
* Date: October 15, 2018
* Course: CIS2520
*
* Description: Q2. Postfix calculator
***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node* push(struct node* root,double value);
struct node* pop(struct node *root);

struct node   /*Linked list to implement stack*/
{
  double value;
  struct node* next;
};

struct node* push(struct node* root,double value) /*Pushes values into stack*/
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->value = value;
  temp->next = root;
  root = temp;
  return root;
}

struct node* pop(struct node *root)  /*Pops values out of stack*/
{
  struct node* temp = root;
  root = root->next;
  free(temp);
  return root;
}

int main (int argc, char *argv[]){
  double numOne,numTwo;
  double result;
  struct node* root = NULL;   /*Linked list header*/
  if (argc<2){    /*Check for user command line argument*/
    printf("Error - Missing user argument\n");
    return 0;
  }
  if (argv[1][0]-'0'<=0 || argv[1][0]-'0'>9){   /*Input validation for number 1*/
    printf("Error - Invalid value detected\n");
    return 0;
  }
  else {  /*Else it is a valid number so push it into the stack*/
    root=push(root,argv[1][0]-'0');
  }
  for (int i=1;i<strlen(argv[1]);i++){
    if(argv[1][i]=='+'){   /*If next character is a + perform addition*/
      numOne=root->value;
      root=pop(root);
      numTwo=root->value;
      root=pop(root);
      result=numOne+numTwo;
      root=push(root,result);
      printf("%.2lf + %.2lf = %.2lf\n",numTwo,numOne,result);
    }
    else if(argv[1][i]=='-'){  /*If next character is a - perform subtraction*/
      numOne=root->value;
      root=pop(root);
      numTwo=root->value;
      root=pop(root);
      result=numTwo-numOne;
      root=push(root,result);
      printf("%.2lf - %.2lf = %.2lf\n",numTwo,numOne,result);
    }
    else if(argv[1][i]=='*'){  /*If next character is a * perform multiplication*/
      numOne=root->value;
      root=pop(root);
      numTwo=root->value;
      root=pop(root);
      result=numTwo*numOne;
      root=push(root,result);
      printf("%.2lf * %.2lf = %.2lf\n",numTwo,numOne,result);
    }
    else if(argv[1][i]=='/'){  /*If next character is a / perform division*/
      numOne=root->value;
      root=pop(root);
      numTwo=root->value;
      root=pop(root);
      result=numTwo/numOne;
      root=push(root,result);
      printf("%.2lf / %.2lf = %.2lf\n",numTwo,numOne,result);
    }
    else {   /*else check if the character is a valid number and if so push it into the stack*/
      if (argv[1][i]-'0'<=0 || argv[1][i]-'0'>9){
        printf("Error - Invalid value detected\n");
        return 0;
      }
      else {
        root=push(root,argv[1][i]-'0');
      }
    }
  }
  if (root->next!=NULL){
    printf("Error - Not enough operators or values specified\n");
  }
  else{
    printf("Result: %.2lf\n",root->value);
    free(root);
  }
  return 0;
}
