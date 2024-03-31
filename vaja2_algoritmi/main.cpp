#include <string>
#include <sstream>
#include <fstream>
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

void izpis_KMPnext(const int* polje, int len) {
	for (int i = 0; i < len; ++i) {
		out << polje[i] << ' ';
	}
	out << endl;
}

void KMP(const string& text, const string& vzorec) {
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

	 int *polje=new int[index.size()];
    for(int i=0;i<index.size();i++)
    {
        polje[i]=index[i];
    }
    izpis_KMPnext(polje, index.size());

    delete[]polje;
}

int main(int argc, const char *const argv[]) {
	if (argc != 4) {
		return -1;
	}

	string text = inputText(argv[3]);
	string vzorec = argv[2];
	out.open("out.txt");

	if (!out) {
		return -2;
	}

	if (argv[1][0] == '0') {
		KMP(text, vzorec);
	}
	else {
		//Sunday
	}

	
	return 0;
}