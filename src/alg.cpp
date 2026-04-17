// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool isNumber(char c) {
  return (c >= '0' && c <= '9');
}

bool isOper(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string result;
  for (int i = 0; i < inf.length(); i++) {
    char c = inf[i];
    if (c == ' ') continue;
    if (isNumber(c)) {
      while (i < inf.length() && isNumber(inf[i])) {
        result += inf[i];
        i++;
      }
      result += ' ';
      i--;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        result += stack.pop();
        result += ' ';
      }
      if (!stack.isEmpty()) stack.pop();
    } else if (isOper(c)) {
      int p = getPriority(c);
      while (!stack.isEmpty() && stack.top() != '(' &&
        getPriority(stack.top()) >= p) {
        result += stack.pop();
        result += ' ';
      }
      stack.push(c);
    }
  }

  while (!stack.isEmpty()) {
    char op = stack.pop();
    if (op != '(' && op != ')') {
      result += op;
      result += ' ';
    }
  }
  if (!result.empty() && result.back() == ' ') {
    result.pop_back();
  }
  return result;
}

int eval(const std::string& pref) {
TStack<int, 100> stack;
  for (int i = 0; i < pref.length(); i++) {
    char c = pref[i];
    if (c == ' ') continue;
    if (isNumber(c)) {
      int num = 0;
      while (i < pref.length() && isNumber(pref[i])) {
        num = num * 10 + (pref[i] - '0');
        i++;
      }
      stack.push(num);
      i--;
    } else if (isOper(c)) {
      int b = stack.pop();
      int a = stack.pop();
      if (c == '+') stack.push(a + b);
      else if (c == '-') stack.push(a - b);
      else if (c == '*') stack.push(a * b);
      else if (c == '/') stack.push(a / b);
    }
  }
  return stack.pop();
}
