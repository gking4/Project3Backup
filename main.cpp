#include "stack.h"
#include "list.cpp"
#include <iomanip>
#include <cmath>
#include <stdio.h>

void isOperator(char op, Stack<double> ast);
void nextCheck(Stack<double> ast);
bool powerCheck(double lhs, double rhs);

void nextCheck(Stack<double> ast)
{
  double num = 0;
  if(isdigit(cin.peek()) == true || cin.peek() == '.')
  {
    cin>>num;
    ast.push(num);
    return;
  }
  else if(isspace(cin.peek() == true))
  {
    cin.ignore();
    nextCheck(ast);
  }
  else
  {
    char op;
    cin>>op;
    isOperator(op, ast);
  }
}

void isOperator(char op, Stack<double> ast)
{
  double lhs = 0;
  double rhs = 0;
  if(op == '+')
  {
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs + rhs;
    ast.push(rhs);
  }//if +
  else if(op == '-')
  {
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs - rhs;
    ast.push(rhs);
  }//if -
  else if(op == '*')
  {
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs * rhs;
    ast.push(rhs);
  }//if *
  else if(op == '/')
  {
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    if(rhs == 0)
    {
    //  cout<<"Error: Tried to divide by 0."<<endl;
      cerr<<"Error: Invalid expression."<<endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      rhs = lhs / rhs;
      ast.push(rhs);
    }
  }//if /
  else if(op == '^')
  {
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    if(powerCheck(lhs, rhs) == true)
    {
      rhs = pow(lhs, rhs);
      ast.push(rhs);
    }
  }//if ^
}

bool powerCheck(double lhs, double rhs)
{
  if(lhs < 0 && floor(rhs) != rhs)
  {
  //  cout<<"Error: Trying to square root a negative number."<<endl;
    cerr<<"Error: Invalid expression."<<endl;
    exit(EXIT_FAILURE);
    return false;
  }
  else if(lhs == 0 && rhs < 0)
  {
  //  cout<<"Error: trying to divide by 0."<<endl;
    cerr<<"Error: Invalid expression."<<endl;
    exit(EXIT_FAILURE);
    return false;
  }
  else
  {
    return true;
  }
}

int main()
{
    Stack<double> ast;
    double result;
    while(cin.peek() != EOF)
    {
      nextCheck(ast);

    }//while
    if(ast.empty() == true)
    {
    //  cout<<"Error: Stack is empty."<<endl;
      cerr<<"Error: Invalid expression."<<endl;
      exit(EXIT_FAILURE);
    }//if
    else
    {
      result = ast.top();
      ast.pop();
      cout<<result<<endl;
    }//else
    return 0;
}//main
