#include <iostream>
using namespace std;
const int size = 100;// initializing size of stack 
class stack//class declaration 
{
private: // data declaration
	int top;	//top element 
	char data[size]; //stack array 
public: // function declaration
	int number; //to get the position of element
	void createStack();//create array stack
	void push(char newitem); // insert operation
	char StackTop();//to get top element of stack
	void pop(); // delete operation
	bool isFull(); // check if stack is Full
	bool isEmpty(); // check if stack is empty
	void checkParenthesis(char c[]);//to check the parenthesis of the input
	bool matching(char open, char close);//to check whether the parenthesis detected is matched with one present on stack
	int checkPlace(char c[]);//check the place where the bracket is whose closing bracket is not present
};
//main
	int main(int argc, const char *argv[])
	{
		stack s;//instance of class
		s.createStack();//creating the array
		char in[size];//array to store the input
		cout << "Enter the expression" << endl;// output to tell the use to enter the expression 
		cin >> in; //taking input
		s.checkParenthesis(in); //Calling the checking parrenthesis method
	}//main ends

	void stack::checkParenthesis(char c[])
	{
		int i = 0;
		while (c[i]!=0) // while the array has elements we check each element
		{
			if (c[i] == '{' || c[i] == '(' || c[i] == '[')		//if a opening bracket is encountered
				push(c[i]);										//push it into the stack
			if (c[i] == '}' || c[i] == ')' || c[i] == ']')		//if  closing bracket is encountered
				{
					if (!matching(StackTop(), c[i]))  //if the match function returns false then output error statement
						cout << "This expression is NOT correct. Error at character #" << checkPlace(c) << "'" << StackTop() << "'" << "- not closed." << endl;
					else
						pop();// else pop the closing bracket
				}//if ends
			i++;//move on to next element
		}//while ends
		if (isEmpty()) //if the array stack is now empty then expression entered is correct
			cout << "This expression is Correct" << endl;
		else// else the expression is incorrect
			cout << "This expression is NOT correct. Error at character #"<<checkPlace(c)<<"'"<< StackTop()<<"'" << "- not closed."<< endl;
	}//checkparenthesis ends
	
	int stack:: checkPlace(char c[])
	{
		int i = 0;
		int number; //store the element number
		while (c[i] != 0) //while array is not null
		{
			if (c[i] == StackTop())//if the element of the stack and the element of the expression matches
				number = i + 1;//store that index number in 'number' adding 1 because array starts from 0;
			i++; // moving onto next element
		}
		return number;//retrn the position number
	}//check place ends
	bool stack:: matching(char open, char close)
		{
			if (open == '(' && close == ')') return true; //if opening and closing parenthesis match the return true otherwise false
			else if (open == '{' && close == '}') return true;
			else if (open == '[' && close == ']') return true;
			return false;
		}//matching ends
		
		void stack::createStack()
		{
			top = -1; // initializing the top to -1 
		}//createStack ends
	void stack::push(char newitem)
	{ 
		if (isFull())//if the stack gets full show an error
			cout << "ERROR: stack is full" << endl;
		else //else increase the top position and insert the element in there
		{
			top = top + 1;
			data[top] = newitem;
		}//else ends
	}//push ends
	
	bool stack::isEmpty()
	{
		return (top == -1); //if top is =-1 then list is empty
	}//isEmpty ends
	void stack::pop()
	{
		if (isEmpty())//if the stack is empty show an erroe
			cout << "ERROR: Stack is empty" << endl;
		else//else decrease the position of top 
			top = top - 1;
	}//pop ends
	
	bool stack::isFull()
	{
		return (top == size - 1); //if one less than size is equal to the top then the stack is full
	}//isfull ends
	char stack::StackTop() 
	{
		if (isEmpty())//if the stack is empty show error message
			cout << "ERROR: Stack is Empty" << endl;
		else
			return data[top];//else return the element at the index top
	}//StackTop ends

