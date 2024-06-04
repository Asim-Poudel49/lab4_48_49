
#include <random>
#include <iostream>
using namespace std;

int main(){
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> dis(0, 999);
     cout << "Using MT:\n" <<  endl;
    for(int i = 0; i < 100; i++) {
         cout << dis(gen) <<  endl;
    }
     cout <<  endl;
    return 0;
}





















/*#include <iostream>
#include <random>

int main() {
    // Create a Mersenne Twister engine
     mt19937 mt_engine( random_device{}());

    // Generate a random number between 0 and 99
     uniform_int_distribution<int> dist(0, 99);
    int random_number = dist(mt_engine);

    // Print the random number
     cout << "Random number: " << random_number <<  endl;

    return 0;
}*/