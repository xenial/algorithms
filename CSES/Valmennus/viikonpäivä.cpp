#include <iostream>
#include "string.h"
#include "math.h"
using namespace std;
int main() {
    string d;
    cin >> d;
    short date[3];
    int buffer = -1;
    int j = 0;
    for (int i = 0; i < d.length(); i++) {
        if (buffer == -1) {
            buffer = (int)(d.at(i) - '0');
        } else if (d.at(i) != '.') {
            buffer = buffer * 10 + (int)(d.at(i) - '0');
        }
        if (d.at(i) == '.' || i == d.length() - 1) {
            date[j] = buffer;
            j++;
            buffer = -1;
            continue;
        }
    }
    int w = ((date[0]                                                      
		+ ((153 * (date[1] + 12 * ((14 - date[1]) / 12) - 3) + 2) / 5) 
		+ (365 * (date[2] + 4800 - ((14 - date[1]) / 12)))
		+ ((date[2] + 4800 - ((14 - date[1]) / 12)) / 4)
		- ((date[2] + 4800 - ((14 - date[1]) / 12)) / 100)
		+ ((date[2] + 4800 - ((14 - date[1]) / 12)) / 400)
		- 32045) + 1) % 7;
    string n[] = {"sunnuntai","maanantai", "tiistai","keskiviikko", "torstai", "perjantai", "lauantai"};
    cout << n[w];
} 