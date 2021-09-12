#include <iostream>
#include <algorithm>

using namespace std;

string pilihanComputer() {
    int random = 1 + (rand() % 3);
    if (random == 1) {
        return "batu";
    } else if (random == 2) {
        return "gunting";
    } else if (random == 3) {
        return "kertas";
    }
    return "";
}

string hasil(string player, string computer) {
    if (player == computer) {
        return "DRAW";
    } else if (computer == "batu") {
        if (player == "gunting") {
            return "YOU LOSE";
        } else if (player == "kertas") {
            return "YOU WIN";
        }
    } else if (computer == "gunting") {
        if (player == "batu") {
            return "YOU WIN";
        } else if (player == "kertas") {
            return "YOU LOSE";
        }
    } else if (computer == "kertas") {
        if (player == "batu") {
            return "YOU LOSE";
        } else if (player == "gunting") {
            return "YOU WIN";
        }
    }
    return "";
}

int main() {
    bool mainLagi = true;
    string player;
    string comp;
    while (mainLagi) {
        cout << "Masukkan pilihan(batu, gunting, kertas) : ";
        cin >> player;
        transform(player.begin(), player.end(), player.begin(), ::tolower);

        if (player == "batu" || player == "gunting" || player == "kertas") {
            comp = pilihanComputer();
            cout << "========================================" << endl;
            cout << "Pilihan player : " << player << endl;
            cout << "Pilihan computer : " << comp << endl;
            cout << "Hasilnya adalah : " << hasil(player, comp) << endl;
            cout << "========================================" << endl;
        } else {
            cout << "Harus batu, gunting, kertas!" << endl;
            continue;
        }

        char yn;
        bool benar = true;
        while (benar) {
            cout << "Main lagi? (y/n) : ";
            cin >> yn;
            if (yn == 'y') {
                benar = false;
                mainLagi = true;
            } else if (yn == 'n') {
                benar = false;
                mainLagi = false;
            } else {
                cout << "pilih y atau n!" << endl;
                benar = true;
            }
        }
    }
    return 0;
}
