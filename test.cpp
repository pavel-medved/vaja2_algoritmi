//
// Created by pavel on 10/04/2024.
//
#include "main.h"
#include <iostream>

bool test(const string &algorithm) {
    string testKmp = "18 512 -100000000000";
    string testSunday = "18 512 12410487654121";
    string algorithmResult = inputText("out.txt");

    if (algorithm == "test_kmp") {
        if (testKmp != algorithmResult) {
            std::cout<<algorithmResult<<endl;
            std::cout << "neuspesno";
            return false;
        } else {
            std::cout << "uspesno";
            return true;
        }
    } else if (algorithm == "test_sunday") {
        if (testSunday != algorithmResult) {
            std::cout<<algorithmResult<<endl;
            std::cout << "neuspesno";
            return false;
        } else {
            std::cout << "uspesno";
            return true;
        }
    }
    return false;
}



