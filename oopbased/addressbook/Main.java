import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Address test = new Address("Justin", "Guernsey Lane", 7); 
		Address test1 = new Address("Bob", "Guernsey Lane", 8); 
		Address test2 = new Address("Justin", "Guernsey", 9); 
		Address test3 = new Address("Tyler", "Guernsey Lane", 5); 
		AddressBook Book = new AddressBook(); 
		Book.add(test);
		Book.add(test1);
		Book.add(test2);
		Book.add(test3);
		System.out.println(Book.newBusiness("New Bob", "Guernsey Lane", 8));
		
		for (int i = 0; i < Book.onStreet("Guernsey Lane").size(); ++i) {
			System.out.println(Book.onStreet("Guernsey Lane").get(i)); 
		}	
	}
	
}
	 
