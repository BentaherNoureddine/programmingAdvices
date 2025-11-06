#pragma once
#include "clsMyStack.h"
#include <string>




class clsMyString {

private:

    clsMyStack<std::string> _redo;
    clsMyStack<std::string> _undo;

    std::string _value;


public:

    void setValue(const std::string &value) {
       _undo.push(_value);
        _value=value;
    }

    std::string getValue() {
       return _value;
    }

    void undo() {
        if (!_undo.isEmpty()) {
            _redo.push(_value);
            _value=_undo.top();
            _undo.pop();
        }
    }

    void redo() {
        if (!_redo.isEmpty()) {
            _undo.push(_value);
            _value=_redo.top();
            _redo.pop();
        }
    }



};