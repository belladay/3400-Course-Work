#include <iostream>
#include <vector>

using namespace std;

bool primechecker(int number) {
    
    if (number == 2) {
        return true;
        }
    if (number == 1) {
        return false;
    }

    else {

        for (int j = 2; j < number; j++ ) {
            if ((number % j) == 0) {
                return false;
            }
        }
        return true;
    }  
}

void primefinder(int limit) {

    for (int i = 1; i <= limit; i++)

    if (primechecker(i) == true) {
        cout << i << endl;
    }

}

int main() {

    int limit;

    cout<< "Enter the limit for the range of prime numbers you would like me to generate: ";
    cin >> limit;

    primefinder(limit);

    return 0;
}
