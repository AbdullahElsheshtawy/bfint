#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

enum OP {
  OP_INC = '>',
  OP_DEC = '<',
  OP_PLUS = '+',
  OP_MINUS = '-',
  OP_OUT = '.',
  OP_IN = ',',
  OP_BRACK_OPEN = '[',
  OP_BRACK_CLOSE = ']',
};

class interpreter {
public:
  interpreter();
  void interpret(std::string &program);
  
private:
  std::unordered_map<int, int> match_brackets(std::string &program);

private:
  uint64_t ip;
  std::vector<uint8_t> tape;
};