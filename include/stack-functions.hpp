/** @file stack-functions.hpp
 * @brief Stack function declarations for assignment
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Stacks
 * @date   June 1, 2021
 *
 * @description Assignment Stacks: applications of stacks. Use the
 *   given Stack ADT to implement a set of functions/algorithms.  This
 *   header file is for the function prototypes you are to write for
 *   this assignment.  You should modify this file by adding
 *   prototypes/signatures of your 4 functions where indicated below.
 */
#include "Stack.hpp" // only use the Stack ADT given, do not use STL stacks
#include <string>
using namespace std;

#ifndef _STACK_FUNCTIONS_H_
#define _STACK_FUNCTIONS_H_

// put your function prototypes for the assignment here
bool doParenthesisMatch(string expression);
string decodeIDSequence(string sequence);
template<class T>
void insertItemOnSortedStack(T item, Stack<T>& sortedStack);
template<class T>
void sortStack(Stack<T>& aStack);
#endif // _STACK_FUNCTIONS_H_
