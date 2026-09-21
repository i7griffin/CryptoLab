#ifndef AES_H
#define AES_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdint>

using namespace std;

//s-box 

const uint8_t SBox[16][16] = {

    {0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76},
    {0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0},
    {0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15},
    {0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75},
    {0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84},
    {0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF},
    {0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8},
    {0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2},
    {0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73},
    {0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB},
    {0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79},
    {0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08},
    {0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A},
    {0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E},
    {0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF},
    {0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16}
};


//inverse s-box 

const uint8_t inverseSBox[16][16] = {

    {0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB},
    {0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB},
    {0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E},
    {0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25},
    {0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92},
    {0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84},
    {0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06},
    {0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B},
    {0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73},
    {0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E},
    {0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B},
    {0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4},
    {0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F},
    {0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF},
    {0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61},
    {0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D}
};


//round constants 

/*Rcon is stored as a 32-bit word, with the calculated byte in the first position:
Round	Rcon word
1	01000000
2	02000000
3	04000000
4	08000000
5	10000000
6	20000000
7	40000000
8	80000000
9	1B000000
10  36000000
*/



const uint8_t Rcon[10] = {
    0x01,0x02,0x04,0x08,0x10,
    0x20,0x40,0x80,0x1B,0x36
};



//getting the input 
string inputHex()
{
    string input;
    cout << "Enter 16-byte plaintext or ciphertext (32 hex digits): ";
    cin >> input;
    return input;
}

//getting the input for key 
string inputKey()
{
    string key;
    cout << "Enter 16-byte AES key (32 hex digits): ";
    cin >> key;
    return key;
}


//hex to binary 
string bitStream(string input)
{
    string bits = "";

    for(char ch : input)
    {
        switch(toupper(static_cast<unsigned char>(ch)))
        {
            case '0': bits += "0000"; break;
            case '1': bits += "0001"; break;
            case '2': bits += "0010"; break;
            case '3': bits += "0011"; break;
            case '4': bits += "0100"; break;
            case '5': bits += "0101"; break;
            case '6': bits += "0110"; break;
            case '7': bits += "0111"; break;
            case '8': bits += "1000"; break;
            case '9': bits += "1001"; break;
            case 'A': bits += "1010"; break;
            case 'B': bits += "1011"; break;
            case 'C': bits += "1100"; break;
            case 'D': bits += "1101"; break;
            case 'E': bits += "1110"; break;
            case 'F': bits += "1111"; break;

            default:
                throw invalid_argument("Invalid hexadecimal character");
        }
    }
    return bits;
}

//hex ch to byte 
uint8_t hexByte(char high, char low)
{
    string temp;
    temp += high;
    temp += low;

    /*stoi means string to integer.
    The third argument, 16, tells C++ to interpret the string as base 16 (hexadecimal)*/

    /*uint8_t is an unsigned 8-bit integer type, capable of representing values from 0 to 255.*/
    return static_cast<uint8_t>(stoi(temp, nullptr, 16));
}


// creating the state matrix 
void inputToState(string input, uint8_t state[4][4])
{
    if(input.length() != 32)
        throw invalid_argument("Input must contain exactly 32 hex digits");

    bitStream(input); // Validate hexadecimal characters.

    int idx = 0;

    for(int col = 0; col < 4; col++)
    {
        for(int row = 0; row < 4; row++)
        {
            state[row][col] = hexByte(input[idx], input[idx + 1]);

            idx += 2;
        }
    }
}


//state matrix to hex 

string stateToHex(uint8_t state[4][4])
{
    stringstream ss;

    /*uppercase	                               Use uppercase letters A–F
      hex	                                   Display integers in hexadecimal
      setfill('0')	                           Pad unused width with zeros*/


    ss << uppercase << hex << setfill('0');

    for(int col = 0; col < 4; col++)
    {
        for(int row = 0; row < 4; row++)
        {
            ss << setw(2) << static_cast<int>(state[row][col]);
        }
    }

    return ss.str();
}


//printing the state matrix 

void printState(uint8_t state[4][4])
{
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            cout << uppercase << hex
                 << setw(2) << setfill('0')
                 << static_cast<int>(state[row][col])
                 << " ";
        }

        cout << endl;
    }

    cout << dec;
}


/*the process of add round key is the elements of the matrix is XORed with the state matrix */
void addRoundKey(
    uint8_t state[4][4],
    uint8_t roundKey[4][4])
{
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            state[row][col] ^= roundKey[row][col];
        }
    }
}


//sub bytes operation 
void subBytes(uint8_t state[4][4])
{
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            uint8_t value = state[row][col];

            //extracting the upper nibble (by shifting right first and then Xoring with 0000 1111)
            int high = (value >> 4) & 0x0F;

            //extracting the lower nibble (byXoring with 0000 1111)
            int low  = value & 0x0F;

            state[row][col] = SBox[high][low];
        }
    }
}


//inverse sub bytes operation 
void inverseSubBytes(uint8_t state[4][4])
{
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            uint8_t value = state[row][col];

            //extracting the upper nibble (by shifting right first and then Xoring with 0000 1111)
            int high = (value >> 4) & 0x0F;

            //extracting the lower nibble (byXoring with 0000 1111)
            int low  = value & 0x0F;

            state[row][col] = inverseSBox[high][low];
        }
    }
}


//shift rows operation 
void shiftRows(uint8_t state[4][4])
{
    uint8_t temp[4][4];

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            temp[row][col] = state[row][(col + row) % 4];
        }
    }

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            state[row][col] = temp[row][col];
        }
    }
}


//inverse shift rows

void inverseShiftRows(uint8_t state[4][4])
{
    uint8_t temp[4][4];

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            temp[row][col] =
                state[row][(col - row + 4) % 4];
        }
    }

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            state[row][col] = temp[row][col];
        }
    }
}


// MULTIPLY BY 2 IN GF(2^8)
uint8_t xtime(uint8_t value)
{
    uint8_t result = value << 1;

    if(value & 0x80) 
    result ^= 0x1B;

    return result;
}


// GENERAL GF(2^8) MULTIPLICATION
/*xtime(b)
- If MSB = 0: shift left and keep 8 bits.
- If MSB = 1: shift left, keep 8 bits, then XOR with 1B.*/

uint8_t galoisMultiply(uint8_t a, uint8_t b)
{
    uint8_t result = 0;

    while(b)
    {
        if(b & 1)
            result ^= a;

        a = xtime(a);
        b >>= 1;
    }

    return result;
}


//mix column operation 

void mixColumns(uint8_t state[4][4])
{
    for(int col = 0; col < 4; col++)
    {
        uint8_t a0 = state[0][col];
        uint8_t a1 = state[1][col];
        uint8_t a2 = state[2][col];
        uint8_t a3 = state[3][col];

        state[0][col] = galoisMultiply(a0, 2) ^ galoisMultiply(a1, 3) ^ a2 ^ a3;

        state[1][col] = a0 ^ galoisMultiply(a1, 2) ^ galoisMultiply(a2, 3) ^ a3;

        state[2][col] = a0 ^ a1 ^ galoisMultiply(a2, 2) ^ galoisMultiply(a3, 3);

        state[3][col] = galoisMultiply(a0, 3) ^ a1 ^ a2 ^ galoisMultiply(a3, 2);
    }
}


//inverse mix column operation 

void inverseMixColumns(uint8_t state[4][4])
{
    for(int col = 0; col < 4; col++)
    {
        uint8_t a0 = state[0][col];
        uint8_t a1 = state[1][col];
        uint8_t a2 = state[2][col];
        uint8_t a3 = state[3][col];

        state[0][col] =
            galoisMultiply(a0, 0x0E) ^
            galoisMultiply(a1, 0x0B) ^
            galoisMultiply(a2, 0x0D) ^
            galoisMultiply(a3, 0x09);

        state[1][col] =
            galoisMultiply(a0, 0x09) ^
            galoisMultiply(a1, 0x0E) ^
            galoisMultiply(a2, 0x0B) ^
            galoisMultiply(a3, 0x0D);

        state[2][col] =
            galoisMultiply(a0, 0x0D) ^
            galoisMultiply(a1, 0x09) ^
            galoisMultiply(a2, 0x0E) ^
            galoisMultiply(a3, 0x0B);

        state[3][col] =
            galoisMultiply(a0, 0x0B) ^
            galoisMultiply(a1, 0x0D) ^
            galoisMultiply(a2, 0x09) ^
            galoisMultiply(a3, 0x0E);
    }
}


// rotation word operation 

void rotWord(uint8_t word[4])
{
    uint8_t temp = word[0];

    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}


//sub word 
void subWord(uint8_t word[4])
{
    for(int i = 0; i < 4; i++)
    {
        uint8_t value = word[i];

        word[i] =  SBox[(value >> 4) & 0x0F][value & 0x0F];
    }
}


//key expansion preocess to generate round keys
vector<uint8_t> generateRoundKeys(string key)
{
    if(key.length() != 32)
        throw invalid_argument("AES-128 key must be 32 hex digits");

    bitStream(key); // Validate hexadecimal characters.

    vector<uint8_t> expandedKey(176);

    int idx = 0;

    //converting original key to 16 bytes 

    for(int i = 0; i < 32; i += 2)
    {
        expandedKey[idx++] =
            hexByte(key[i], key[i + 1]);
    }

    //generating remaing words for the keystream

    int generated = 16;
    int rconIndex = 0;

    uint8_t temp[4];

    while(generated < 176)
    {
        // Copy previous word
        for(int i = 0; i < 4; i++)
        {
            temp[i] =
                expandedKey[generated - 4 + i];
        }

        // Every 16 bytes:
        // RotWord  ----- SubWord ------ XOR Rcon

        if(generated % 16 == 0)
        {
            rotWord(temp);
            subWord(temp);

            temp[0] ^= Rcon[rconIndex++];
        }

        // XOR with word 4 positions earlier

        for(int i = 0; i < 4; i++)
        {
            expandedKey[generated] =
                expandedKey[generated - 16] ^ temp[i];

            generated++;
        }
    }

    return expandedKey;
}


//getting round key for particular round 

void getRoundKey(
    vector<uint8_t> &expandedKey,
    int round,
    uint8_t roundKey[4][4])
{
    int idx = round * 16;

    for(int col = 0; col < 4; col++)
    {
        for(int row = 0; row < 4; row++)
        {
            roundKey[row][col] =
                expandedKey[idx++];
        }
    }
}


//printing round key 

void printRoundKey(
    vector<uint8_t> &expandedKey,
    int round)
{
    uint8_t roundKey[4][4];

    getRoundKey(expandedKey, round, roundKey);

    cout << "Round Key " << round << ": "
         << stateToHex(roundKey) << endl;
}


//Aes encryption process 

void aesRound(
    uint8_t state[4][4],
    uint8_t roundKey[4][4],
    bool finalRound = false)
{
    // STEP 1: SubBytes
    subBytes(state);

    // STEP 2: ShiftRows
    shiftRows(state);

    // STEP 3: MixColumns
    // Not performed in round 10
    if(!finalRound)
        mixColumns(state);

    // STEP 4: AddRoundKey
    addRoundKey(state, roundKey);
}


//aes decryption 

void inverseAesRound(
    uint8_t state[4][4],
    uint8_t roundKey[4][4],
    bool finalRound = false)
{
    // STEP 1: Inverse ShiftRows
    inverseShiftRows(state);

    // STEP 2: Inverse SubBytes
    inverseSubBytes(state);

    // STEP 3: AddRoundKey
    addRoundKey(state, roundKey);

    // STEP 4: Inverse MixColumns
    // Not performed in the final inverse round
    if(!finalRound)
        inverseMixColumns(state);
}




string encryption(string plaintext, string key)
{
    uint8_t state[4][4];

    inputToState(plaintext, state);

    vector<uint8_t> expandedKey =
        generateRoundKeys(key);

    cout << "\nAES ENCRYPTION\n";

    cout << "\nInitial State:\n";
    printState(state);

    // initial ARK 

    uint8_t roundKey[4][4];

    getRoundKey(expandedKey, 0, roundKey);

    addRoundKey(state, roundKey);

    cout << "\nAfter Initial AddRoundKey:\n";
    printState(state);

    //10 aes fiestal rounds 

    for(int round = 1; round <= 10; round++)
    {
        getRoundKey(expandedKey, round, roundKey);

        bool finalRound = (round == 10);

        aesRound(state, roundKey, finalRound);

        cout << "\nRound " << round << endl;

        cout << "State:\n";
        printState(state);

        cout << "Round Key: "
             << stateToHex(roundKey) << endl;
    }

    cout << "\nCiphertext: "
         << stateToHex(state) << endl;

    return stateToHex(state);
}


//decryption 

string decryption(string ciphertext, string key)
{
    uint8_t state[4][4];

    inputToState(ciphertext, state);

    vector<uint8_t> expandedKey =
        generateRoundKeys(key);

    cout << "\nAES DECRYPTION\n";

    cout << "\nInitial Ciphertext State:\n";
    printState(state);

    uint8_t roundKey[4][4];

    //initial ARK (with K10)


    getRoundKey(expandedKey, 10, roundKey);

    addRoundKey(state, roundKey);

    cout << "\nAfter Initial AddRoundKey :\n";
    printState(state);

    // aes fiestal rounds 9 to 1 

    for(int round = 9; round >= 1; round--)
    {
        getRoundKey(expandedKey, round, roundKey);

        inverseAesRound(state, roundKey);

        cout << "\nInverse Round " << round << endl;

        cout << "State:\n";
        printState(state);

        cout << "Round Key: "
             << stateToHex(roundKey) << endl;
    }

    //inverse aes round 

    getRoundKey(expandedKey, 0, roundKey);

    inverseAesRound(state, roundKey, true);

    cout << "\nFinal Inverse Round 0:\n";
    printState(state);

    cout << "\nDecrypted Plaintext: "
         << stateToHex(state) << endl;

    return stateToHex(state);
}




void encryption()
{
    string plaintext = inputHex();
    string key = inputKey();

    encryption(plaintext, key);
}


void decryption()
{
    string ciphertext = inputHex();
    string key = inputKey();

    decryption(ciphertext, key);
}


#endif
