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
    cout<<"starting isdigit check"<<endl;
    cin>>num;
    ast.push(num);
    cout<<"ending isdigit check"<<endl;
    if(cin.peek() == '.')
    {
      cerr<<"Error: Invalid expression."<<endl;
      exit(EXIT_FAILURE);
    }
    return;
  }
  else if(isspace(cin.peek()))
  {
    cout<<"starting space skip"<<endl;
    cin.ignore();
    nextCheck(ast);
    cout<<"ending space skip"<<endl;
  }
  else
  {
    cout<<"operator start"<<endl;
    char op;
    cin>>op;
    isOperator(op, ast);
    cout<<"operator stop"<<endl;
  }
}

void isOperator(char op, Stack<double> ast)
{
  double lhs = 0;
  double rhs = 0;
  if(op == '+')
  {
    cout<<"+ operator start"<<endl;
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs + rhs;
    ast.push(rhs);
    cout<<"+ operator stop"<<endl;
  }//if +
  else if(op == '-')
  {
    cout<<"- operator start"<<endl;
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs - rhs;
    ast.push(rhs);
    cout<<"- operator stop"<<endl;
  }//if -
  else if(op == '*')
  {
    cout<<"* operator start"<<endl;
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    rhs = lhs * rhs;
    ast.push(rhs);
    cout<<"* operator stop"<<endl;
  }//if *
  else if(op == '/')
  {
    cout<<"divide operator start"<<endl;
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
      cout<<"divide operator stop"<<endl;
    }
  }//if /
  else if(op == '^')
  {
    cout<<"power operator start"<<endl;
    rhs = ast.top();
    ast.pop();
    lhs = ast.top();
    ast.pop();
    if(powerCheck(lhs, rhs) == true)
    {
      rhs = pow(lhs, rhs);
      ast.push(rhs);
      cout<<"power operator stop"<<endl;
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
      cout<<"while loop start"<<endl;
      nextCheck(ast);
      cout<<"while loop stop"<<endl;
    }//while
    if(ast.empty() == true)
    {
    //  cout<<"Error: Stack is empty."<<endl;
      cerr<<"Error: Invalid expression."<<endl;
      exit(EXIT_FAILURE);
    }//if
    else
    {
      cout<<"starting result print"<<endl;
      result = ast.top();
      ast.pop();
      cout<<result<<endl;
      cout<<"ending result print"<<endl;
    }//else
    return 0;
}//main
