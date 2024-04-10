//
// Created by pavel on 10/04/2024.
//
#include "main.h"

bool test(const string &outputFile) {
    string result = inputText(outputFile);
    string algorithm = inputText("out.txt");
    if (result != algorithm) {
        return false;
    } else {
        return true;
    }
}



