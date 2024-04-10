//
// Created by pavel on 10/04/2024.
//
#include "main.h"
#include <fstream>
void test(const string &outputFile) {
    string result = inputText(outputFile);
    string algorithm = inputText("out.txt");
    ofstream errorFile("napaka.txt");
    if (result != algorithm) {
        if (errorFile.is_open()) {
            errorFile << "napaka" << endl;
            errorFile.close();
        } else {
            if (errorFile.is_open()) {
                errorFile << "pravilno" << endl;
                errorFile.close();
            }
        }
    }
}
