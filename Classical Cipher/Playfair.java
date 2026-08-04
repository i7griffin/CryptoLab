
//Program to implement Playfair cipher 
import java.util.Scanner ; 
public class PlayFair {

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
}
