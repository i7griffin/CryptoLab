#ifndef FEISTAL_H
#define FEISTAL_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

//permutation s boxes

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

//permutation bos 

//key = input value 
//value = output value 

unordered_map<int, int> PBox = {

    {16,1}, {7,2},  {20,3}, {21,4},
    {29,5}, {12,6}, {28,7}, {17,8},

    {1,9},  {15,10}, {23,11}, {26,12},
    {5,13}, {18,14}, {31,15}, {10,16},

    {2,17}, {8,18}, {24,19}, {14,20},
    {32,21}, {27,22}, {3,23}, {9,24},

    {19,25}, {13,26}, {30,27}, {6,28},
    {22,29}, {11,30}, {4,31}, {25,32}
};


//initial permutation 
string initialPermutation(string plainText)
{
    string permutedString(64, '0');

    for (int inputPos = 1; inputPos <= 64; inputPos++)
    {
        int outputPos = InitialPermutation[inputPos];

        permutedString[outputPos - 1] =
            plainText[inputPos - 1];
    }

    return permutedString;
}


// inverse initial permutation 
string inverseInitialPermutation(string permuted)
{
    string original(64, '0');

    for (int inputPos = 1; inputPos <= 64; inputPos++)
    {
        int outputPos = InitialPermutation[inputPos];

        original[inputPos - 1] =
            permuted[outputPos - 1];
    }

    return original;
}


//getting the input and converting it to hex 

string inputHex()
{
    string hex;

    cout << "Enter the plainText" << endl;
    cin >> hex;

    return hex;
}


string inputKey()
{
    string key;

    cout << "Enter the Key" << endl;
    cin >> key;

    return key;
}


// converting hex to binary 

string bitStream(string input)
{
    string bitstream = "";

    for (char ch : input)
    {
        switch (toupper(ch))
        {
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

            default:
                break;
        }
    }

    return bitstream;
}


//expansion scheme 
void expansionScheme(
    string right,
    char (&postExpansionMatrix)[8][6])
{
    char preExpansionMatrix[8][4];

    int mover = 0;

    // Divide 32-bit input into 8 groups of 4 bits
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            preExpansionMatrix[i][j] =
                right[mover++];
        }
    }


    // Expanding every 4-bit group to 6 bits
    for (int i = 0; i < 8; i++)
    {
        int prev_row = (i - 1 + 8) % 8;
        int next_row = (i + 1) % 8;

        postExpansionMatrix[i][0] =
            preExpansionMatrix[prev_row][3];

        postExpansionMatrix[i][1] =
            preExpansionMatrix[i][0];

        postExpansionMatrix[i][2] =
            preExpansionMatrix[i][1];

        postExpansionMatrix[i][3] =
            preExpansionMatrix[i][2];

        postExpansionMatrix[i][4] =
            preExpansionMatrix[i][3];

        postExpansionMatrix[i][5] =
            preExpansionMatrix[next_row][0];
    }
}




string toBinary4(int value)
{
    string bits = "";

    for (int b = 3; b >= 0; b--)
    {
        bits += ((value >> b) & 1)
                    ? '1'
                    : '0';
    }

    return bits;
}


//s box substitution 

string s_box(char (&postExpansionMatrix)[8][6])
{
    string substitutedString = "";

    for (int i = 0; i < 8; i++)
    {
        string rowtemp = "";
        string coltemp = "";

        int row;
        int col;
        int value;


        //row is the ombination of first and last bit 

        rowtemp += postExpansionMatrix[i][0];
        rowtemp += postExpansionMatrix[i][5];

        row = stoi(rowtemp, nullptr, 2);


        // middle four bits are the column address 

        coltemp += postExpansionMatrix[i][1];
        coltemp += postExpansionMatrix[i][2];
        coltemp += postExpansionMatrix[i][3];
        coltemp += postExpansionMatrix[i][4];

        col = stoi(coltemp, nullptr, 2);


        //choosing s box 

        switch (i)
        {
            case 0:
                value = S1[row][col];
                break;

            case 1:
                value = S2[row][col];
                break;

            case 2:
                value = S3[row][col];
                break;

            case 3:
                value = S4[row][col];
                break;

            case 4:
                value = S5[row][col];
                break;

            case 5:
                value = S6[row][col];
                break;

            case 6:
                value = S7[row][col];
                break;

            case 7:
                value = S8[row][col];
                break;
        }


        // Convert 0-15 result to 4 bits
        substitutedString +=
            toBinary4(value);
    }

    return substitutedString;
}


// p box permutation 
string pBoxPermutation(string input)
{
    string output(32, '0');

    for (int inputPos = 1; inputPos <= 32; inputPos++)
    {
        int outputPos = PBox[inputPos];

        output[outputPos - 1] =
            input[inputPos - 1];
    }

    return output;
}


//des round key generation 

vector<string> generateRoundKeys(string key)
{

    int PC1[56] = {

        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,

        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };


    
    int PC2[48] = {

        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,

        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    };


    

    int shifts[16] = {

        1, 1, 2, 2,
        2, 2, 2, 2,
        1, 2, 2, 2,
        2, 2, 2, 1
    };


    // Convert hexadecimal key -> 64 bits
    string binaryKey = bitStream(key);


    

    string permutedKey = "";

    for (int i = 0; i < 56; i++)
    {
        permutedKey +=
            binaryKey[PC1[i] - 1];
    }


    

    string C =
        permutedKey.substr(0, 28);

    string D =
        permutedKey.substr(28, 28);


    vector<string> roundKeys;


    // --------------------------------------------------------
    // Generate K1 ... K16
    // --------------------------------------------------------

    for (int round = 0; round < 16; round++)
    {
        // Circular LEFT shift C
        for (int i = 0; i < shifts[round]; i++)
        {
            C =
                C.substr(1) + C[0];
        }


        // Circular LEFT shift D
        for (int i = 0; i < shifts[round]; i++)
        {
            D =
                D.substr(1) + D[0];
        }


        // Combine C and D
        string CD = C + D;


        // ----------------------------------------------------
        // Apply PC-2
        // ----------------------------------------------------

        string roundKey = "";

        for (int i = 0; i < 48; i++)
        {
            roundKey +=
                CD[PC2[i] - 1];
        }


        roundKeys.push_back(roundKey);
    }

    return roundKeys;
}


// ============================================================
// FEISTEL ROUND
// ============================================================

void feistelRound(
    string &left,
    string &right,
    string roundKey)
{
    // --------------------------------------------------------
    // STEP 1
    // Expand R from 32 -> 48 bits
    // --------------------------------------------------------

    char postExpansionMatrix[8][6];

    expansionScheme(
        right,
        postExpansionMatrix);


    // --------------------------------------------------------
    // STEP 2
    // XOR expanded R with round key
    // --------------------------------------------------------

    int idx = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            char keyBit =
                roundKey[idx];

            postExpansionMatrix[i][j] =
                (
                    (
                        postExpansionMatrix[i][j] - '0'
                    )
                    ^
                    (
                        keyBit - '0'
                    )
                )
                + '0';

            idx++;
        }
    }


    // --------------------------------------------------------
    // STEP 3
    // S-BOX
    // 48 -> 32 bits
    // --------------------------------------------------------

    string substitutedString =
        s_box(postExpansionMatrix);


    // --------------------------------------------------------
    // STEP 4
    // P-BOX
    // 32 -> 32 bits
    // --------------------------------------------------------

    string pboxString =
        pBoxPermutation(substitutedString);


    // --------------------------------------------------------
    // STEP 5
    // XOR with LEFT
    // --------------------------------------------------------

    string newRight = "";

    for (int i = 0; i < 32; i++)
    {
        newRight +=
            (
                (
                    left[i] - '0'
                )
                ^
                (
                    pboxString[i] - '0'
                )
            )
            + '0';
    }


    

    left = right;

    right = newRight;
}





string hexStream(string bits)
{
    string hexDigits =
        "0123456789ABCDEF";

    string hexStr = "";

    for (size_t i = 0;
         i + 4 <= bits.length();
         i += 4)
    {
        int val =
            stoi(
                bits.substr(i, 4),
                nullptr,
                2
            );

        hexStr +=
            hexDigits[val];
    }

    return hexStr;
}




void encryption()
{
=

    string input =
        inputHex();

    string bitstream =
        bitStream(input);


    cout << "\nThis is the converted bitstream input\n"
         << endl;

    cout << bitstream << endl;




    string permutedString =
        initialPermutation(bitstream);


    

    string left =
        permutedString.substr(0, 32);

    string right =
        permutedString.substr(32, 32);


   

    string key =
        inputKey();

    vector<string> roundKeys =
        generateRoundKeys(key);



    for (int round = 0;
         round < 16;
         round++)
    {
        feistelRound(
            left,
            right,
            roundKeys[round]
        );

        cout << "\nRound "
             << round + 1
             << " -> L: "
             << left
             << " R: "
             << right
             << endl;
    }



    string cipherTextBeforeFinalPermutation =
        right + left;


    cout << "\nCipher text before final permutation\n"
         << endl;

    cout << cipherTextBeforeFinalPermutation
         << endl;



    string cipherTextBits =
        inverseInitialPermutation(
            cipherTextBeforeFinalPermutation
        );


    cout << "\nCipher text after final permutation\n"
         << endl;

    cout << cipherTextBits << endl;


    // Binary -> Hexadecimal
    cout << "\nCipher Text (HEX): "
         << hexStream(cipherTextBits)
         << endl;
}




void decryption()
{


    string input =
        inputHex();

    string bitstream =
        bitStream(input);


    cout << "\nThis is the converted bitstream input\n"
         << endl;

    cout << bitstream << endl;


 

    string permutedString =
        initialPermutation(bitstream);



    string left =
        permutedString.substr(0, 32);

    string right =
        permutedString.substr(32, 32);


    

    string key =
        inputKey();

    vector<string> roundKeys =
        generateRoundKeys(key);




    for (int round = 15;
         round >= 0;
         round--)
    {
        feistelRound(
            left,
            right,
            roundKeys[round]
        );

        cout << "\nRound "
             << (16 - round)
             << " -> L: "
             << left
             << " R: "
             << right
             << endl;
    }



    string permutedPlain =
        right + left;



    string originalBitstream =
        inverseInitialPermutation(
            permutedPlain
        );


    cout << "\nDecrypted plaintext\n"
         << endl;

    cout << originalBitstream
         << endl;


    // Binary -> HEX
    cout << "\nPlaintext (HEX): "
         << hexStream(originalBitstream)
         << endl;
}


#endif
