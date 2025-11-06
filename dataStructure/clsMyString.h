#pragma once
#include "clsMyStack.h"
#include <string>




class clsMyString {

private:

    clsMyStack<std::string> _stack;
    clsMyStack<std::string> _recStack;


public:

    void setValue(const std::string &value) {
        while (!_recStack.isEmpty()) {
            _recStack.pop();
        }
        _stack.push(value);
    }

    std::string getValue() {
        if (_stack.isEmpty()) {
            return "";
        }
        return _stack.top();
    }

    void undo() {
        if (!_stack.isEmpty()) {
            _recStack.push(_stack.top());
            _stack.pop();
        }

    }

    void redo() {
        if (!_recStack.isEmpty()) {
            _stack.push(_recStack.top());
            _recStack.pop();
        }


    }



};