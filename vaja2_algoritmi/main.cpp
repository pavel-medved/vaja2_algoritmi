#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <iostream>
#include <cstring>

using namespace std;

ofstream out;

string inputText(const string &pot) {
    ifstream input(pot);
    stringstream sstream;

    if (!input.is_open()) {
        return string();
    }

    sstream << input.rdbuf();
    return sstream.str();
}

void izpis_KMPnext(const int *polje, int len) {
    for (int i = 0; i < len; ++i) {
        out << polje[i] << ' ';
    }

}

void KMP(const string &text, const string &vzorec) {
    vector<int> kmpNext;
    vector<int> index;
    kmpNext.push_back(-1);
    kmpNext.push_back(0);

    int prefix = 1;

    for (int i = 2; i < vzorec.size(); i++) {
        vector<char> firstPrefix;
        vector<char> secondPrefix;

        for (int j = 1; j <= prefix; j++) {

            firstPrefix.push_back(vzorec[j - 1]);
            secondPrefix.insert(secondPrefix.begin(), vzorec[i - j]);

        }
        for (int j = i; j > 0; j--) {
            string firstString(firstPrefix.begin(), firstPrefix.end());
            string secondString(secondPrefix.begin(), secondPrefix.end());
            if (firstString == secondString) {
                kmpNext.push_back(firstString.size());
                break;
            }
            secondPrefix.erase(secondPrefix.begin());
            firstPrefix.pop_back();
            if (j == 1) {
                kmpNext.push_back(0);
            }
        }
        prefix++;
    }

    int j = 0;
    while (j + vzorec.size() <= text.size()) {
        for (int i = 0; i < vzorec.size(); i++) {
            if (vzorec[i] != text[j + i]) {

                j += (i - kmpNext[i]);
                break;
            }
            if (i + 1 == vzorec.size()) {
                index.push_back(j);
                j += vzorec.size();
            }
        }
    }

    int *polje = new int[index.size()];
    for (int i = 0; i < index.size(); i++) {
        polje[i] = index[i];
    }
    izpis_KMPnext(polje, index.size());
    for (int i = 0; i < kmpNext.size(); i++) {
        out << kmpNext[i];

    }
    out.close();
    delete[]polje;
}

void sundaySearch(const string &text, const string &vzorec) { //priprava tabele
    std::vector<uint32_t> BCH(256, vzorec.size() + 1);
    vector<int> index;
    for (int i = 0; i < vzorec.size(); i++) {
        BCH[static_cast<uint8_t>(vzorec[i])] = vzorec.size() - i;
    }
    int j = 0;

    while (j + vzorec.size() <= text.size()) {
        for (int i = 0; i < vzorec.size(); i++) {
            if (vzorec[i] != text[j + i]) {

                j += BCH[static_cast<uint8_t>(text[j + vzorec.size()])];
                break;
            }
            if (i + 1 == vzorec.size()) {
                index.push_back(j);
                j += vzorec.size();
            }
        }
    }
    int *polje = new int[index.size()];
    for (int i = 0; i < index.size(); i++) {
        polje[i] = index[i];
    }
    izpis_KMPnext(polje, index.size());
    for (int i = 0; i < vzorec.size(); i++) {
        out << BCH[static_cast<uint8_t>(vzorec[i])];
    }
    out.close();
    delete[] polje;
}

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

int main(int argc, const char *const argv[]) {

    string text;
    string vzorec;
    if (argc == 4) {
        text = inputText(argv[3]);
        vzorec = argv[2];
    } else if (argc == 2) {
        text = inputText("test-besedilo.txt");
        vzorec = "znanstveniki";
    }
    out.open("out.txt");

    if (!out) {
        return -2;
    }

    if (argv[1][0] == '0') {
        KMP(text, vzorec);
    } else if (argv[1][0] == '1') {
        sundaySearch(text, vzorec);//Sunday
    } else if (strcmp(argv[1], "test_kmp") == 0) {
        KMP(text, vzorec);
        test("rezultat-kmpNext.txt");
    } else if (strcmp(argv[1], "test_sunday") == 0) {
        sundaySearch(text, vzorec);
        test("rezultat-sundaySearch.txt");
    }
    return 0;
}