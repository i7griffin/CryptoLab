//Program to implement DES cipher 

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std ;


//All eight substitution tables 

//These tables are used after the expansion scheme 
vector<vector<int>> S1 = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

vector<vector<int>> S2 = {
    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
};

vector<vector<int>> S3 = {
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
};

vector<vector<int>> S4 = {
    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
};

vector<vector<int>> S5 = {
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
};

vector<vector<int>> S6 = {
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
};

vector<vector<int>> S7 = {
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
    {6, 1, 4, 10, 7, 13, 9, 5, 0, 15, 14, 2, 3, 12, 8, 11}
};

vector<vector<int>> S8 = {
    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
    {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
    {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
    {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
};

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

//End permutation table
unordered_map<int, int> InversePermutation = {
    {16, 1}, {7, 2},  {20, 3}, {21, 4},
    {29, 5}, {12, 6}, {28, 7}, {17, 8},

    {1, 9},  {15, 10}, {23, 11}, {26, 12},
    {5, 13}, {18, 14}, {31, 15}, {10, 16},

    {2, 17}, {8, 18}, {24, 19}, {14, 20},
    {32, 21}, {27, 22}, {3, 23}, {9, 24},

    {19, 25}, {13, 26}, {30, 27}, {6, 28},
    {22, 29}, {11, 30}, {4, 31}, {25, 32}
};


//this function permutates the plaintext by initial permutation 
string initialPermutation(string plainText){
    string permutedString = "" ;
    for (int i = 0 ; i < plainText.length() ; i++){
        permutedString[InitialPermutation[i]] = plainText[i] ;
    }
    return permutedString ;
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

//substitution process
string s_box( char (&postExpansionMatrix)[8][6])
{
    string substitutedString = "" ;
    string rowtemp ;
    string coltemp ;
    int row , col ;
    //The first bit and the last bit of the each row is combined to produce the row address
    for (int i = 0 ; i < 8 ; i++){
    rowtemp += postExpansionMatrix[i][0];
    rowtemp += postExpansionMatrix[i][5];

    row = stoi(rowtemp, nullptr, 2);

    coltemp += postExpansionMatrix[i][1];
    coltemp += postExpansionMatrix[i][2];
    coltemp += postExpansionMatrix[i][3];
    coltemp += postExpansionMatrix[i][4];

    col = stoi(coltemp, nullptr, 2);

    switch(i){
        case 0 :substitutedString += S1[row][col] ; break;
        case 1 :substitutedString += S1[row][col] ; break;
        case 2 :substitutedString += S1[row][col] ; break;
        case 3 :substitutedString += S1[row][col] ; break;
        case 4 :substitutedString += S1[row][col] ; break;
        case 5 :substitutedString += S1[row][col] ; break;
        case 6 :substitutedString += S1[row][col] ; break;
        case 7 :substitutedString += S1[row][col] ; break;

    }
    rowtemp = "" ;
    coltemp = "" ;
    
    }

    return substitutedString ;

}

string inversePermutation(string plainText)
{
    string permutedString(plainText.length(), ' ');

    for (int i = 0; i < plainText.length(); i++)
    {
        if (InversePermutation.find(i) != InversePermutation.end())
        {
            permutedString[InversePermutation[i]] =
                plainText[i];
        }
    }

    return permutedString;
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

    string substitutedString = s_box(postExpansionMatrix) ;

    //inverse permutation process
    string inversepermutedstring = inversePermutation(substitutedString) ;

    


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
