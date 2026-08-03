// Program to implement vigenere cipher encryption
#include <iostream>

using namespace std;

// generating the key to match the plainText size
string generateKey(string Text, string key)
{
    int keyLength = key.length();
    string finalKey;
    int i = 0;
    while (i < Text.length())
    {
        finalKey += key[i % keyLength];
        i++;
    }
    return finalKey;
}

void decryption()
{
    string cryptoText;
    string temp = "";

    // Getting the cryptotext from the user
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, cryptoText);

    // Getting the input of key string
    string key;
    cin >> key;
    key = generateKey(cryptoText, key);

    string plainText ;

    for ( int i = 0 ; i < key.size() ; i++){
        int value = ((( ( static_cast<int>(cryptoText[i]) - 'A' ) - (( static_cast<int>(key[i])) - 'a')  ) + 26 )% 26 ) + 97 ;
        plainText += static_cast<char>(value) ;
    }

    cout << "\nDecrypted text" << endl ;
    cout << plainText << endl ;
    
}


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

    string cryptoText ;

    for ( int i = 0 ; i < key.size() ; i++){
        int value = (( ( static_cast<int>(plainText[i]) - 97 ) + ( static_cast<int>(key[i])) - 97  ) % 26 ) + 65 ;
        cryptoText += static_cast<char>(value) ;
    }

    cout << "\nEncrypted text" << endl ;
    cout << cryptoText << endl ;
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
}
