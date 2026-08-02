// Program to implement Affine cipher
#include <iostream>
using namespace std;

int gcd(int a, int b)
{

    int r0 = a;
    int r1 = b;
    while (r1 != 0)
    {
        int q = r0 / r1;
        int n = r1;
        r1 = r0 - q * r1;
        r0 = n;
    }

    return r0;
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

    int a;
    int b;
    cout << "Enter multiplicative key (a): ";
    cin >> a;

    cout << "Enter additive key (b): ";
    cin >> b;
    // mod 26 of a inverse exists only if the gcd of a with 26 is 1
    if (gcd(26, a) != 1)
    {
        cout << "Not suitable value for a " << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < plainText.length(); ++i)
    {
        int value = ((((static_cast<int>(plainText[i]) - 97) * a) + b) % 26) + 65;
        plainText[i] = static_cast<char>(value);
    }

    cout << "\nEncrypted message" << endl;
    cout << plainText << endl;
}

int extendedEuclidean(int a, int b)
{
    int r0 = a;
    int r1 = b;

    int u0 = 1;
    int u1 = 0;

    int v0 = 0;
    int v1 = 1;

    int r2, v2, u2;

    while (r1 != 0)
    {
        int q = r0 / r1;
        r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;

        v2 = v0 - q * v1;
        v0 = v1;
        v1 = v2;

        u2 = u0 - q * u1;
        u0 = u1;
        u1 = u2;
    }
    // converting the inverse value of a to be positive if it is negative in any case
    return (v0 % 26 + 26) % 26;
}

void decryption()
{
    string cryptoText;
    string temp = "";

    // Getting the cryptotext from the user
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, cryptoText);

    int a;
    int b;
    cout << "Enter multiplicative key (a): ";
    cin >> a;

    cout << "Enter additive key (b): ";
    cin >> b;
    // mod 26 of a inverse exists only if the gcd of a with 26 is 1
    if (gcd(26, a) != 1)
    {
        cout << "Not suitable value for a " << endl;
        exit(EXIT_FAILURE);
    }

    int a_inverse = extendedEuclidean(26, a);

    for (int i = 0; i < cryptoText.length(); ++i)
    {
        int value = (((static_cast<int>(cryptoText[i]) - 65 - b + 26) * a_inverse) % 26) + 97;
        cryptoText[i] = static_cast<char>(value);
    }

    cout << "\nDecrypted message" << endl;
    cout << cryptoText << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n Affine Cipher " << endl;
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
