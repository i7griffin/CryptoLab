
//Program to implement Playfair cipher 
import java.util.HashMap;
import java.util.Scanner;

public class PlayFair {

    //This function is used to receive the positions of the characters 
    public static int[] findPosition(char[][] keyMatrix, char ch) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (keyMatrix[i][j] == ch) {
                    return new int[]{i, j};
                }
            }
        }

        return null;
    }

    public static void encryption(Scanner scan_obj) {
        String plainText;

        // Getting the plaintext from the user
        System.out.println("Enter a string: ");
        plainText = scan_obj.nextLine();

        plainText = plainText.replaceAll("[^A-Za-z]", "");
        plainText = plainText.toLowerCase();
        plainText = plainText.replaceAll("j", "i");

        // It is make the plain text encryptable with playfair regulations
        String finalPlainText = "";

        //this loop preprocessses the text to make it ready for encryption
        for (int i = 0; i < plainText.length(); i += 2) {
            if (i == plainText.length() - 1) {
                finalPlainText += plainText.charAt(i);
                break;
            }
            if (plainText.charAt(i) == plainText.charAt(i + 1)) {
                finalPlainText += plainText.charAt(i--);
                finalPlainText += 'x';
            } else {
                finalPlainText += plainText.charAt(i);
                finalPlainText += plainText.charAt(i + 1);
            }
        }

        if (finalPlainText.length() % 2 != 0) {
            finalPlainText += 'x';
        }

        System.out.println("Processed plaintext: " + finalPlainText);

        String keyString;

        // Getting the keyString  from the user
        System.out.println("Enter the keyString to encrypt with  ");
        keyString = scan_obj.nextLine();
        //1st argument is to select what to remove and 2nd argument is to choose what to replace it with
        //replaceAll preserves the order of the remaining characters 
        keyString = keyString.replaceAll("[^A-Za-z]", "");
        keyString = keyString.toLowerCase();

        //all j is swapped with i to make it into 5x5 matrix for encryption 
        keyString = keyString.replaceAll("j", "i");

        char[][] key = new char[5][5];
        HashMap<Character, Integer> map = new HashMap<>();
        int a = 0;
        int b = 0;

        //this collects unique letters from the key string 
        for (int i = 0; i < keyString.length(); i++) {
            if (!map.containsKey(keyString.charAt(i))) {
                map.put(keyString.charAt(i), 1);
                if (b == 5) {
                    a++;
                    b = 0;
                    key[a][b++] = keyString.charAt(i);
                } else {
                    key[a][b++] = keyString.charAt(i);
                }
            }
        }

        //this fills the remaining spaces with letters of the alphabet 
        //now the key matrix is ready for encryption 
        String alpha = "abcdefghiklmnopqrstuvwxyz";
        for (int i = 0; i < 25; i++) {
            System.out.println(i);
            if (!map.containsKey(alpha.charAt(i))) {
                map.put(alpha.charAt(i), 1);
                if (b == 5) {
                    a++;
                    b = 0;
                    key[a][b++] = alpha.charAt(i);
                } else {
                    key[a][b++] = alpha.charAt(i);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(key[i][j] + " ");
            }
            System.out.println();
        }

        String cryptoText = "";

        //now is the actual playfair encryption part
        for (int i = 0; i < finalPlainText.length(); i += 2) {
            //stroing th efirst character and second character 
            char first = finalPlainText.charAt(i);
            char second = finalPlainText.charAt(i + 1);

            //this function retuns the position of the respectic=ve letters in the keymatrix 
            int[] pos1 = findPosition(key, first);
            int[] pos2 = findPosition(key, second);

            int row1 = pos1[0];
            int col1 = pos1[1];

            int row2 = pos2[0];
            int col2 = pos2[1];

            //if two elements are in the same column
            if (col1 == col2) {
                cryptoText += key[(row1 + 1) % 5][col1];
                cryptoText += key[(row2 + 1) % 5][col2];
            } //if two elements are in the same row 
            else if (row1 == row2) {
                cryptoText += key[row1][(col1 + 1) % 5];
                cryptoText += key[row2][(col2 + 1) % 5];
            } else //else the elements will take the horizontal opposite corners of the rectangle they form 
            {
                cryptoText += key[row1][col2];
                cryptoText += key[row2][col1];

            }

        }

        System.out.println("\nEncrypted text\n");
        System.out.println(cryptoText);

    }

    public static void decryption(Scanner scan_obj) {
        String cryptoText;

        // Getting the cryptotext from the user
        System.out.println("Enter a string: ");
        cryptoText = scan_obj.nextLine();

        String keyString;
        // Getting the keyString  from the user
        System.out.println("Enter the keyString to encrypt with  ");
        keyString = scan_obj.nextLine();
        //1st argument is to select what to remove and 2nd argument is to choose what to replace it with
        //replaceAll preserves the order of the remaining characters 
        keyString = keyString.replaceAll("[^A-Za-z]", "");
        keyString = keyString.toLowerCase();

        //all j is swapped with i to make it into 5x5 matrix for encryption 
        keyString = keyString.replaceAll("j", "i");

        char[][] key = new char[5][5];
        HashMap<Character, Integer> map = new HashMap<>();
        int a = 0;
        int b = 0;

        //this collects unique letters from the key string 
        for (int i = 0; i < keyString.length(); i++) {
            if (!map.containsKey(keyString.charAt(i))) {
                map.put(keyString.charAt(i), 1);
                if (b == 5) {
                    a++;
                    b = 0;
                    key[a][b++] = keyString.charAt(i);
                } else {
                    key[a][b++] = keyString.charAt(i);
                }
            }
        }

        //this fills the remaining spaces with letters of the alphabet 
        //now the key matrix is ready for encryption 
        String alpha = "abcdefghiklmnopqrstuvwxyz";
        for (int i = 0; i < 25; i++) {
            System.out.println(i);
            if (!map.containsKey(alpha.charAt(i))) {
                map.put(alpha.charAt(i), 1);
                if (b == 5) {
                    a++;
                    b = 0;
                    key[a][b++] = alpha.charAt(i);
                } else {
                    key[a][b++] = alpha.charAt(i);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(key[i][j] + " ");
            }
            System.out.println();
        }

        String plainText = "";
        //now is the actual playfair decryption part
        for (int i = 0; i < cryptoText.length(); i += 2) {
            //stroing th efirst character and second character 
            char first = cryptoText.charAt(i);
            char second = cryptoText.charAt(i + 1);

            //this function retuns the position of the respectic=ve letters in the keymatrix 
            int[] pos1 = findPosition(key, first);
            int[] pos2 = findPosition(key, second);

            int row1 = pos1[0];
            int col1 = pos1[1];

            int row2 = pos2[0];
            int col2 = pos2[1];

            //if two elements are in the same column
            if (col1 == col2) {
                plainText += key[(row1 + 4) % 5][col1];
                plainText += key[(row2 + 4) % 5][col2];
            } //if two elements are in the same row 
            else if (row1 == row2) {
                plainText += key[row1][(col1 + 4) % 5];
                plainText += key[row2][(col2 + 4) % 5];
            } else //else the elements will take the horizontal opposite corners of the rectangle they form 
            {
                plainText += key[row1][col2];
                plainText += key[row2][col1];

            }

        }

        System.out.println("\nDecrypted text\n");
        System.out.println(plainText);

    }

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n Playfair cipher");
            System.out.println("1. Encryption");
            System.out.println("2. Decryption");
            System.out.println("3. Exit");
            System.out.println("Enter your choice: ");

            //Creating a scanner object 
            Scanner scan_obj = new Scanner(System.in);

            //function to get a integer input through scanner object
            choice = scan_obj.nextInt();
            scan_obj.nextLine();

            switch (choice) {
                case 1:
                    encryption(scan_obj);
                    break;

                case 2:
                    decryption(scan_obj);
                    break;

                case 3:
                    System.out.println("Exiting");
                    break;

                default:
                    System.out.println("Invalid Choice");
            }

        } while (choice != 3);
    }
}
