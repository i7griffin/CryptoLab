// Program to implement vigenere cipher encryption
#include <iostream>

using namespace std;

void encryption()
{
    string plainText;
    string temp = "";

    // Getting the plaintext from the user
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, plainText);

    // Remove all special characters and keep only alphabets
    for (int i = 0; i < plainText.length(); ++i)
    {
        if ((plainText[i] >= 'a' && plainText[i] <= 'z') ||
            (plainText[i] >= 'A' && plainText[i] <= 'Z'))
        {
            temp = temp + plainText[i];
        }
    }

    plainText = temp;
    temp = "";

    // Convert all characters to lowercase
    for (auto x : plainText)
    {
        temp += (char)tolower(x);
    }

    plainText = temp;

    // Getting the input of key string
    string key;
    cin >> key;
    key = generateKey(plainText, key);

    for ()
}

void decryption()
{
}

// generating the key to match the plainText size
string generateKey(string plainText, string key)
{
    int keyLength = key.length();
    string finalKey;
    int i = 0;
    while (i < plainText.length())
    {
        finalKey += key[i % keyLength];
        i++;
    }
    return finalKey;
}

int main()
{
    int choice;

    do
    {
        cout << "\n Vigenere Cipher " << endl;
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            encryption();
            break;

        case 2:
            decryption();
            break;

        case 3:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 3);

    return 0;
