/*3. Write a program that prints a table indicating the number of occurrences of each alphabet in the text entered as command line arguments.
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Please provide a single string as a command line argument.\n";
        return 1;
    }

    int count[26] = {0};
    for(int i = 0; argv[1][i] != '\0'; i++) {
        char c = argv[1][i];
        if(c >= 'A' && c <= 'Z') {
            count[c - 'A']++;
        } else if(c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        }
    }

    cout << "Character\tCount\n";
    for(int i = 0; i < 26; i++) {
        if(count[i] > 0) {
            cout << static_cast<char>('A' + i) << "\t\t" << count[i] << "\n";
        }
    }

    return 0;
}
