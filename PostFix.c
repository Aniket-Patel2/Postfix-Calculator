#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//inserts a float onto the stack
void push(float result, float *stack, int *top)
{
  ++(*top);
  stack[*top] = result;

}
//removes the top element from the stack
float pop(float *stack, int *top)
{
  int temp ;
  temp = *top;
  --(*top);
  return stack[(temp)];

}

int main(int argc, char **argv){

  int top = -1;
  float stack[20];

  float num1, num2, result, digit;

  int i=0;

//iterates through command line argument and sorts by digit or operand
  do {

    // if digit, it is then added to stack
    if (isdigit(argv[1][i]))
    {
        digit = (argv[1][i]) - 48;
        push(digit, stack, &top);

      // if operand is discoverd top 2 elements are poped and evaluated
    } else {

        num2 = pop(stack, &top);
        num1 = pop(stack, &top);

        switch (argv[1][i]) {
          case '+':
          {
            result = num1 + num2;
            break;
          }

          case '-':
          {
            result = num1 - num2;
            break;
          }

          case '*':
          {
            result = num1 * num2;
            break;
          }

          case '/':
          {
            result = num1 / num2;
            break;
          }
        }
        //result of operation is pushed back onto stack
        push(result, stack, &top);
    }
    i++;

  } while(argv[1][i]);


  printf("The answer is %.2f\n", pop(stack, &top) );





}

