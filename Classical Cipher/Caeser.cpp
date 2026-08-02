// Program to implement Caesar Cipher
#include <iostream>
using namespace std;

// Function for encryption
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

    int key;
    cout << "Enter the key to encrypt the message : " << endl;
    cin >> key;

    /*
        Encryption Logic:
        1. Convert character into range 0-25 by subtracting 97 ('a').
        2. Add the key (shift).
        3. Apply modulo 26 to wrap around the alphabet.
        4. Add 97 to convert back to lowercase characters.
    */

    for (int i = 0; i < plainText.length(); ++i)
    {
        int value = ((static_cast<int>(plainText[i]) - 97 + key) % 26) + 97;
        plainText[i] = static_cast<char>(value);
    }

    cout << "\nEncrypted message" << endl;
    cout << plainText << endl;
}

// Function for decryption
void decryption()
{
    
}

int main()
{
    int choice;

    do
    {
        cout << "\n Caesar Cipher " << endl;
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
}
