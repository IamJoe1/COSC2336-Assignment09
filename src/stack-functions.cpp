/** @file stack-functions.cpp
 * @brief Stack function declarations for assignment
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * @description Assignment Stacks: applications of stacks.  Use the
 *   given Stack ADT to implement a set of functions/algorithms.  This
 *   implementation file is for the functions you are to write for
 *   this assignment.  You should modify this file by adding
 *   implementations of the 4 functions you are to write.  You need to
 *   use the Stack ADT given to you, and included for you, for the
 *   Stack instances for your functions.  It is incorrect to include
 *   STL stacks or other containers here to use for this assignment.
 */
#include "AStack.hpp"
#include "LStack.hpp"
#include "Stack.hpp" // only use the Stack ADT given, do not use STL stacks

/**
 * @brief is parenthesis expression balanced.
 *  Test if the string consisting of parenthesis
 * is balanced or not. Return true if its balanced.
 * Return false if it's not
 *
 * @param expression a string of parenthesis
 *
 * @return bool true if balanced, false if not.
 *
 */
bool doParenthesisMatch(string expression)
{
  // Declaraing a stack.
  AStack<char> s;
  char top;
  int length = expression.size();
  if (length == 0)
  {
    return true;
  }

  for (int i = 0; i < length; i++)
  {
    if (expression[i] == '(')
    {
      s.push(expression[i]);
      continue;
    }
    if (s.isEmpty())
    {
      return false;
    }
    switch (expression[i])
    {
    case ')':

      top = s.top();
      s.pop();
      if (top == '{' || top == '[')
      {
        return false;
      }
      break;

    case ']':
      top = s.top();
      s.pop();
      if (top == '(')
        return false;
      break;
    }
  }
  return (s.isEmpty());
}
/**
 * @brief Decode a a sequence.
 *This function takes a string as the input sequence,
 *so it will need to iterate over the sequences character by character again.
 And it returns a new string which is a minimum number.
 *
 * @param sequence a string of I's and D's
 *
 * @return result - A minimum number.
 *
 */
string decodeIDSequence(string sequence)
{
  string result = "";
  LStack<int> sequenceStack;
  int length = sequence.size();

  for (int i = 0; i <= length; i++)
  {
    sequenceStack.push(i + 1);
    if (i == length || sequence[i] == 'I')
    {
      while (!sequenceStack.isEmpty())
      {
        result += to_string(sequenceStack.top());
        sequenceStack.pop();
      }
    }
  }
  return result;
}
/**
 * @brief Inserts an item in a sorted stack.
 *
 *This void function inserts an item in an ascending order stack.
 *The item should be inserted into the correct position on the sorted
 *stack to keep it sorted.
 *
 * @param item to be inserted into the stack.
 *
 * @param sortedStack reference as the second parameter.
 *
 */
template<class T>
void insertItemOnSortedStack(T item, Stack<T>& sortedStack)
{
  LStack<T> temporaryStack;
  while (!sortedStack.isEmpty())
  {
    if (item < sortedStack.top())
    {
      temporaryStack.push(sortedStack.top());
      sortedStack.pop();
    }
    else
    {
      break;
    }
  }
  sortedStack.push(item);

  while (!temporaryStack.isEmpty())
  {
    sortedStack.push(temporaryStack.top());
    temporaryStack.pop();
  }
}
/**
 * @brief Sorts a Stack.
 *
 *The function, as the name implies, will take an unsorted stack,
 *and will sort them in the same order we used previously, e.g. in ascending
 *order with the smallest item at the bottom of the stack, and the largest at the top.
 *
 * @param lStack a reference to a Stack of <int> types
 *
 */
template<class T>
void sortStack(Stack<T>& lStack)
{
  LStack<T> temporaryStack;
  if (lStack.isEmpty())
  {
    return;
  }
  temporaryStack.push(lStack.top());
  lStack.pop();
  sortStack(lStack);
  insertItemOnSortedStack(temporaryStack.top(), lStack);
}
/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Stack<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
// uncomment the following when working on task 4 to implement the insertItemOnSortedStack() template function
template void insertItemOnSortedStack<int>(int item, Stack<int>& sortedStack);
template void insertItemOnSortedStack<string>(string item, Stack<string>& sortedStack);

// uncomment the following when working on task 5 to implement the sortStack() template function
template void sortStack<int>(Stack<int>& aStack);
template void sortStack<string>(Stack<string>& aStack);
