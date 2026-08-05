
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
        for (int i = 0; i < plainText.length(); i += 2) {

            if (plainText.charAt(i) == plainText.charAt(i + 1)) {
                finalPlainText += plainText.charAt(i--);
                finalPlainText += 'x';
            } else {
                finalPlainText += plainText.charAt(i);
                if (i < plainText.length()) {
                    finalPlainText += plainText.charAt(i + 1);
                }
            }
        }

        String keyString;

        // Getting the keyString  from the user
        System.out.println("Enter the keyString to encrypt with  ");
        keyString = scan_obj.nextLine();
        //1st argument is to select what to remove and 2nd argument is to choose what to replace it with
        //replaceAll preserves the order of the remaining characters 
        keyString = keyString.replaceAll("[^A-Za-z]", "");
        keyString = keyString.toLowerCase();
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
        String alpha = "abcdefghiklmnopqrstuwxyz";
        for (int i = 0; i < alpha.length(); i++) {
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

            switch (choice) {
                case 1:
                    encryption(scan_obj);
                    break;

                case 2:
                    decryption();
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
