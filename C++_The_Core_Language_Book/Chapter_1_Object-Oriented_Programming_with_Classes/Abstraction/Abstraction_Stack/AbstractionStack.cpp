// Dylan Nelson
// September 12, 2025
// AbstractionStack.cpp

#include <iostream>

// This is an anonymous struct with the alias of Stack. 
typedef struct {
	int items[10];
	int top;
} Stack;

// The more common approach is this:
/*struct Stack {
	int items[STACKSIZE];
	int top;
};*/

// Definining the methods of the Stack;
void init(Stack* s) { s->top = 0; } // Pointer access of top.
void push(Stack* s, int i) { s->items[s->top++] = i; } // Assigning i with pointer access of items using top as the index accessor with post-increment;
int pop(Stack* s) { return s->items[--s->top]; } // Return the value of top in items with pointer access.
void cleanup(Stack* s) {} // no cleanup needed for static stack.

typedef struct {
	Stack basicStack;
} StatStack;

/* New to StatStack */
int mean(StatStack* s) {/*some implementation*/ }
int median(StatStack* s) {/*some implementation*/ }
int mode(StatStack* s) {/*some implementation*/ }

/* in Stack, using Stack's predefined functions to implement with StatStack*/
void ss_init(StatStack* s) { init(&s->basicStack); }
void ss_push(StatStack* s, int i) { push(&s->basicStack, i); }
int ss_pop(StatStack* s) { return pop(&s->basicStack); }
void ss_cleanup(StatStack* s) { cleanup(&s->basicStack); }


int main() {

	// const declares a constant, STACKSIZE's size cannot be changed.
	const int STACKSIZE = 10;

	// This creates three int items: stack_items = an array of ints size of STACKSIZE, stacktop = 0, and x with no value.
	int stack_items[STACKSIZE], stack_top = 0, x = 1;

	// This sets stack_top (0++) to x. This uses the post-increment of ++ using the value of stack_top then incrementing it. 
	//	Effectively assigning index 0 as x. stack_top is now 1.
	stack_items[stack_top++] = x;

	// This sets x to be equal to stack_top with the pre-decrement of stack_top. Using the current calue of stack_top then 
	//	decrementing it.
	x = stack_items[--stack_top];

	int t = 5;
	Stack stack1;

	// This is a function call by pointer, sending the memory address of stack1 not a copy.
	init(&stack1);
	// Push t onto the stack by utilizing the function defined above.
	push(&stack1, t);
	push(&stack1, 2);
	push(&stack1, 50);
	// assign a variable to f off the top of the stack.
	int f = pop(&stack1);
	// Multiple ways to pop.
	std::cout << "Stack top: " << f << std::endl;
	std::cout << "Next top: " << pop(&stack1) << std::endl;
	std::cout << "Next top: " << pop(&stack1) << std::endl;
	cleanup(&stack1);
	
	return 0;
}