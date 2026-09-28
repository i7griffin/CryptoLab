#include "fiestalaes.h"

int main()
{
    string plaintext;
    string key;

    cout << "Enter 16-byte plaintext (32 hex digits): ";
    cin >> plaintext;

    cout << "Enter 16-byte AES key (32 hex digits): ";
    cin >> key;

    try
    {
        // Encryption
        string ciphertext = encryption(plaintext, key);
        cout << "Ciphertext: " << ciphertext << endl;

        // Decryption
        string decrypted = decryption(ciphertext, key);
        cout << "Decrypted plaintext: " << decrypted << endl;
    }
    catch(const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
