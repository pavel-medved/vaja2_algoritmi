//
// Created by pavel on 10/04/2024.
//

#ifndef VAJA2_MAIN_H
#define VAJA2_MAIN_H
#include <string>
using namespace std;
string inputText(const string &pot);

void izpis_KMPnext(const int *polje, int len);

void KMP(const string &text, const string &vzorec);

void sundaySearch(const string &text, const string &vzorec);

#endif //VAJA2_MAIN_H
