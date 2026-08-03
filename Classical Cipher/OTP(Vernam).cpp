// Program to implement OTP(Vernam) cipher encryption
#include <iostream>
#include <random>
#include <string>


using namespace std;


// generating the key to match the plainText size
string generateKey(int length )
{
    
    /* This asks the computer motherboard to generate the a 32 bit unsinged integer 
    that is based on the thermal noise of the hardware and highs and lows of the voltage */
    random_device rd; 
    
    //we feed the random noise into a high speed mathematical engine to generate a truy random key 
    mt19937 gen(rd()); 
    
    //this datatype segregates any huge number into requires number of buckets and truncates the unwanted part at the end 
    uniform_int_distribution<int> dist(0, 25); 

    //this is the key we will generate finally and use to encrypt the text 
    string key ;

    for (int i = 0; i < length; ++i) {
        //dist(gen) returns random bucket number between 0 to 25 
        key += (char)('A' + dist(gen));
    }
    cout << "Key generated" << endl ;
    cout << key << endl ;
    
    return key;
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
    key = generateKey(plainText.length());

    string cryptoText ;

    for ( int i = 0 ; i < key.size() ; i++){
        int value = (( ( static_cast<int>(plainText[i]) - 'a' ) + ( static_cast<int>(key[i])) - 'A'  ) % 26 ) + 65 ;
        cryptoText += static_cast<char>(value) ;
    }

    cout << "\nEncrypted text" << endl ;
    cout << cryptoText << endl ;
}




void decryption()
{
    string cryptoText;
    string temp = "";

    // Getting the cryptotext from the user
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin,cryptoText);

    string key ;
    cout << "Enter the key to decrypt the cryptoText" << endl ;
    getline(cin,key) ;

    
    if (cryptoText.length() != key.length()) {
        cout << "The key length must exactly match the cipher length for one time pad" << endl;
        return; 
}


    string plainText ;

    for ( int i = 0 ; i < key.size() ; i++){
        int value = ((( ( static_cast<int>(cryptoText[i]) - 'A' ) - ( static_cast<int>(key[i]) - 'A' ) ) + 26) % 26 ) + 97 ;
        plainText += static_cast<char>(value) ;
    }

    cout << "\nDecrypted text" << endl ;
    cout << plainText << endl ;

}

int main() {
    int choice;

    do
    {
        cout << "\n OTP Cipher " << endl;
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

