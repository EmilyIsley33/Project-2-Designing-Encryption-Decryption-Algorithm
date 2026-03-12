#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function prototypes
string encrypt(string text, int key);
string decrypt(string text, int key);
void encryptFile(string inputFileName, string outputFileName, int key);
void decryptFile(string inputFileName, string outputFileName, int key);

// ---------------- MAIN MENU ----------------

int main() {
    int choice;
    string inputFile, outputFile;
    int key;

    cout << "===== Encryption Program =====\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    cout << "Enter encryption key (number): ";
    cin >> key;

    if (choice == 1) {
        encryptFile(inputFile, outputFile, key);
        cout << "File encrypted successfully.\n";
    }
    else if (choice == 2) {
        decryptFile(inputFile, outputFile, key);
        cout << "File decrypted successfully.\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}

// ---------------- ENCRYPTION FUNCTION ----------------

string encrypt(string text, int key) {

    // METHOD 1: SHIFTING (Caesar shift using key)
    for (char &c : text) {
        c = c + key;
    }

    // METHOD 2: SUBSTITUTION (replace vowels with symbols)
    for (char &c : text) {
        if (c == 'a') c = '@';
        else if (c == 'e') c = '#';
        else if (c == 'i') c = '$';
        else if (c == 'o') c = '%';
        else if (c == 'u') c = '&';
    }

    // METHOD 3: TRANSPOSITION (reverse the string)
    reverse(text.begin(), text.end());

    return text;
}

// ---------------- DECRYPTION FUNCTION ----------------

string decrypt(string text, int key) {

    // Reverse TRANSPOSITION first
    reverse(text.begin(), text.end());

    // Reverse SUBSTITUTION
    for (char &c : text) {
        if (c == '@') c = 'a';
        else if (c == '#') c = 'e';
        else if (c == '$') c = 'i';
        else if (c == '%') c = 'o';
        else if (c == '&') c = 'u';
    }

    // Reverse SHIFTING
    for (char &c : text) {
        c = c - key;
    }

    return text;
}

// ---------------- FILE ENCRYPTION ----------------

void encryptFile(string inputFileName, string outputFileName, int key) {

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open()) {
        cout << "Error opening input file.\n";
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << encrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}

// ---------------- FILE DECRYPTION ----------------

void decryptFile(string inputFileName, string outputFileName, int key) {

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open()) {
        cout << "Error opening input file.\n";
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << decrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}