#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    cout << "Enter the string:\n";
    cin.getline(str, 1000);

    int suvo = 0, suvojit = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == 'S' && str[i + 1] == 'U' && str[i + 2] == 'V' && str[i + 3] == 'O') {
            if (str[i + 4] == 'J' && str[i + 5] == 'I' && str[i + 6] == 'T')
                suvojit++;
            else
                suvo++;
        }
    }

    cout << "SUVO = " << suvo << ", SUVOJIT = " << suvojit << endl;
    return 0;
}
