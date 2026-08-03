// Program to implement Hill Cipher
#include <iostream>
using namespace std;


void encrypt2x2()
{
    string plainText;
    string cipherText = "";

    cout << "Enter the plaintext: ";
    cin.ignore();
    getline(cin, plainText);

    plainText = preprocessText(plainText, 2);

    int key[2][2];
    inputKey2x2(key);

    int det = determinant2x2(key);

    if (gcd(det, 26) != 1)
    {
        cout << "Invalid Key Matrix!" << endl;
        return;
    }

    int plain[2];
    int cipher[2];

    for (int i = 0; i < plainText.length(); i += 2)
    {
        plain[0] = plainText[i] - 'a';
        plain[1] = plainText[i + 1] - 'a';

        multiply2x2(key, plain, cipher);

        cipherText += (char)(cipher[0] + 'A');
        cipherText += (char)(cipher[1] + 'A');
    }

    cout << "\nEncrypted Message : " << cipherText << endl;
}
void decrypt2x2();

void encrypt3x3(){
    void encrypt3x3()
{
    string plainText;
    string cipherText = "";

    cout << "Enter the plaintext: ";
    cin.ignore();
    getline(cin, plainText);

    plainText = preprocessText(plainText, 3);

    int key[3][3];
    inputKey3x3(key);

    int det = determinant3x3(key);

    if (gcd(det, 26) != 1)
    {
        cout << "Invalid Key Matrix!" << endl;
        return;
    }

    int plain[3];
    int cipher[3];

    for (int i = 0; i < plainText.length(); i += 3)
    {
        plain[0] = plainText[i] - 'a';
        plain[1] = plainText[i + 1] - 'a';
        plain[2] = plainText[i + 2] - 'a';

        multiply3x3(key, plain, cipher);

        cipherText += (char)(cipher[0] + 'A');
        cipherText += (char)(cipher[1] + 'A');
        cipherText += (char)(cipher[2] + 'A');
    }

    cout << "\nEncrypted Message : " << cipherText << endl;
}
}
void decrypt3x3();

void inputKey2x2(int key[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter element" << i << " " << j << endl;
            cin >> key[i][j];
        }
    }
}
void inputKey3x3(int key[3][3]);

int determinant2x2(int key[2][2]){
    int det = key[0][0]*key[1][1] - key[0][1]*key[1][0] ;
    return det ;
}


int determinant3x3(int key[3][3]){
    int determinant3x3(int key[3][3])
{
    int det = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1])
            - key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0])
            + key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);

    return det;
}
}

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

int modInverse(int a);

bool inverseKey2x2(int key[2][2], int inverse[2][2]);
bool inverseKey3x3(int key[3][3], int inverse[3][3]);

string preprocessText(string text, int n)
{
    string temp = "";
    // Remove all special characters and keep only alphabets
    for (int i = 0; i < text.length(); ++i)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'A' && text[i] <= 'Z'))
        {
            temp = temp + text[i];
        }
    }

    text = temp;
    temp = "";

    // Convert all characters to lowercase
    for (auto x : text)
    {
        temp += (char)tolower(x);
    }
    text = temp;
    while (text.length() % n != 0)
    {
        text += 'x';
    }
    return text;
}

void multiply2x2(int key[2][2], int plain[2], int cipher[2])
{
    cipher[0] = (key[0][0] * plain[0] + key[0][1] * plain[1]) % 26;
    cipher[1] = (key[1][0] * plain[0] + key[1][1] * plain[1]) % 26;
}


void multiply3x3(int key[3][3], int plain[3], int cipher[3])
{
    cipher[0] = (key[0][0] * plain[0] +
                 key[0][1] * plain[1] +
                 key[0][2] * plain[2]) % 26;

    cipher[1] = (key[1][0] * plain[0] +
                 key[1][1] * plain[1] +
                 key[1][2] * plain[2]) % 26;

    cipher[2] = (key[2][0] * plain[0] +
                 key[2][1] * plain[1] +
                 key[2][2] * plain[2]) % 26;
}


int main()
{
    int choice;

    do
    {
        cout << "\nHill Cipher \n";
        cout << "1. Encryption (2 x 2)\n";
        cout << "2. Decryption (2 x 2)\n";
        cout << "3. Encryption (3 x 3)\n";
        cout << "4. Decryption (3 x 3)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            encrypt2x2();
            break;

        case 2:
            decrypt2x2();
            break;

        case 3:
            encrypt3x3();
            break;

        case 4:
            decrypt3x3();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
