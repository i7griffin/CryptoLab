//Program to implement DES cipher 

#include <iostream>
#include <unordered_map>

using namespace std ;

//Initial permutation table
unordered_map<int, int> InitialPermutation = {
    {58,1}, {60,2}, {62,3}, {64,4},
    {57,5}, {59,6}, {61,7}, {63,8},

    {50,9}, {52,10}, {54,11}, {56,12},
    {49,13}, {51,14}, {53,15}, {55,16},

    {42,17}, {44,18}, {46,19}, {48,20},
    {41,21}, {43,22}, {45,23}, {47,24},

    {34,25}, {36,26}, {38,27}, {40,28},
    {33,29}, {35,30}, {37,31}, {39,32},

    {26,33}, {28,34}, {30,35}, {32,36},
    {25,37}, {27,38}, {29,39}, {31,40},

    {18,41}, {20,42}, {22,43}, {24,44},
    {17,45}, {19,46}, {21,47}, {23,48},

    {10,49}, {12,50}, {14,51}, {16,52},
    {9,53}, {11,54}, {13,55}, {15,56},

    {2,57}, {4,58}, {6,59}, {8,60},
    {1,61}, {3,62}, {5,63}, {7,64}
};

//this function permutates the plaintext by initial permutation 
string initialPermutation(string plainText){
    string permutedString = "" ;
    for (int i = 0 ; i < plainText.length() ; i++){
        permutedString[InitialPermutation[i]] = plainText[InitialPermutation[i]] ;
    }
}

//funtion to get input from the user 
string inputHex(){
    string hex ;
    cout << "Enter the plainText" << endl ;
    cin >> hex ;
    return hex ;
}


string bitStream(string input){
    string bitstream = "" ;
    for (char ch : input) {
        switch (toupper(ch)) {
            case '0': bitstream += "0000"; break;
            case '1': bitstream += "0001"; break;
            case '2': bitstream += "0010"; break;
            case '3': bitstream += "0011"; break;
            case '4': bitstream += "0100"; break;
            case '5': bitstream += "0101"; break;
            case '6': bitstream += "0110"; break;
            case '7': bitstream += "0111"; break;
            case '8': bitstream += "1000"; break;
            case '9': bitstream += "1001"; break;
            case 'A': bitstream += "1010"; break;
            case 'B': bitstream += "1011"; break;
            case 'C': bitstream += "1100"; break;
            case 'D': bitstream += "1101"; break;
            case 'E': bitstream += "1110"; break;
            case 'F': bitstream += "1111"; break;
            default : break ;
        }
    }
    return bitstream ;
}

void expansionScheme(string right , char (&postExpansionMatrix)[8][6])
{
    //This is the pre-expansion matrix of size 
    char preExpansionMatrix[8][4];
    int mover = 0;
    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            preExpansionMatrix[i][j] = right[mover++];
        }
    } 

    // 3. Populate the 8x6 Post-Expansion Matrix with correct DES indexing
    char postExpansionMatrix[8][6];
    for(int i = 0; i < 8; i++) {
        // Calculate circular wrapping for previous and next rows
        int prev_row = (i - 1 + 8) % 8;
        int next_row = (i + 1) % 8;

        // 0th index (1st element): Last bit (index 3) of the previous row
        postExpansionMatrix[i][0] = preExpansionMatrix[prev_row][3];

        // 1st to 4th index (2nd to 5th elements): The 4 original bits (indices 0 to 3)
        postExpansionMatrix[i][1] = preExpansionMatrix[i][0];
        postExpansionMatrix[i][2] = preExpansionMatrix[i][1];
        postExpansionMatrix[i][3] = preExpansionMatrix[i][2];
        postExpansionMatrix[i][4] = preExpansionMatrix[i][3];

        // 5th index (6th element): First bit (index 0) of the next row
        postExpansionMatrix[i][5] = preExpansionMatrix[next_row][0];
    }
}

void encryption(){
    //hex input is received and stored in the plainText 
    string input = inputHex() ;

    //now the hex input should be converted into 64bit byte stream
    string bitstream = bitStream(input) ;

    cout << "\nThis is the converted bitstream input\n" << endl ;
    cout << bitstream << endl ;

    //this permutes the bitstring
    string permutedString = initialPermutation(bitstream) ;

    //getting the left and right part of the string 
    string left = permutedString.substr(0,permutedString.length() / 2 ) ;
    string right = permutedString.substr(permutedString.length() / 2) ;

    char postExpansionMatrix[8][6];
    expansionScheme(right , postExpansionMatrix) ;

    s_box(postExpansionMatrix) ;

    


}

void decryption(){

}


int main()
{
    int choice;

    do
    {
        cout << "\n DES Cipher " << endl;
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
