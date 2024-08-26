#include "interpreter.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
interpreter::interpreter() {
  this->ip = 0;
  this->tape = {0};
}

std::unordered_map<int, int> interpreter::match_brackets(std::string &program) {
  std::unordered_map<int, int> bracket_map;
  std::stack<int> bracket_stack;
  /*
    ++++[-+]
        5  8 
    it first finds [ at index 5 so now stack has 5
    then it fines ] at index 8 so now i = 8 and 
    bracket_map[i] = stack_value
    bracket_map[stack_value] = i
    so bracket_map of 5 gives you 8 and
    bracket_map of 8 gives you 5
  */
  for (int i = 0; i < program.size(); i++) {
    if (program[i] == OP_BRACK_OPEN)
      bracket_stack.push(i);
    else if (program[i] == OP_BRACK_CLOSE) {
      int index = bracket_stack.top();
      bracket_stack.pop();
      bracket_map[index] = i;
      bracket_map[i] = index;
    }
  }
  return bracket_map;
}
void interpreter::interpret(std::string &program) {
  std::unordered_map<int, int> bracket_map = match_brackets(program);

  for (int i = 0; i < program.size(); i++) {
    switch (program[i]) {
    case OP_INC:
      ip++;
      tape.push_back(0);
      break;
    case OP_DEC:
      ip--;
      break;
    case OP_PLUS:
      tape[ip]++;
      break;
    case OP_MINUS:
      tape[ip]--;
      break;
    case OP_OUT:
      std::cout << static_cast<char>(tape[ip]);
      break;
    case OP_IN:
      std::cin >> tape[ip];
      break;
    case OP_BRACK_OPEN:
      if (tape[ip] == 0)
        i = bracket_map[i];
      break;
    case OP_BRACK_CLOSE:
      if (tape[ip] != 0)
        i = bracket_map[i];
      break;
    default:
      break;
    }
  }
}