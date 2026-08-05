
//Program to implement Playfair cipher 
import java.util.Scanner ; 
public class Playfair {

    public static void encryption(Scanner scan_obj){
    String plainText;

    // Getting the plaintext from the user
    System.out.println("Enter a string: ");
    plainText= scan_obj.nextLine() ;
    
    plainText = plainText.replaceAll("[^A-Za-z]","") ;
    plainText = plainText.toLowerCase() ;


    String key;

    // Getting the plaintext from the user
    System.out.println("Enter the key to encrypt with  ");
    key= scan_obj.nextLine() ;
    //1st argument is to select what to remove and 2nd argument is to choose what to replace it with
    //replaceAll preserves the order of the remaining characters 
    key = key.replaceAll("[^A-Za-z]","") ;
    key = key.toLowerCase() ;
    

    }

    public static void main(String[] args){
        int choice;

    do
    {   
    System.out.println("\n Playfair cipher");
    System.out.println("1. Encryption");
    System.out.println("2. Decryption");
    System.out.println("3. Exit");
    System.out.println("Enter your choice: ");

    //Creating a scanner object 
    Scanner scan_obj = new Scanner(System.in) ;

    //function to get a integer input through scanner object
    choice = scan_obj.nextInt() ;

        switch (choice)
        {
        case 1:
            encryption(scan_obj);
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
}
