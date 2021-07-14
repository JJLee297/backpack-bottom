import java.util.ArrayList;
import java.util.List;

public class AddressBook
{
  
  private List<Address> addresses;

  public AddressBook() { 
	  addresses = new ArrayList<Address>(); 
  }

  public void add(Address store) {
	  addresses.add(store);
  }
  public List<String> onStreet(String st) {
	  ArrayList<String> result = new ArrayList<String>(); 
	  for (int i = 0; i < addresses.size(); ++i) {
		  if (addresses.get(i).getStreet() == st) {
			  result.add(addresses.get(i).getName()); 
		  }
	  }
	  return result;   
  }

  
  public int newBusiness(String nm, String st, int no) {
	  Address a = new Address(nm, st, no); 
	  for (int i = 0; i < addresses.size(); ++i) {
		  String name = addresses.get(i).getStreet();
		  int number = addresses.get(i).getNumber(); 
		  if (name == st && number == no) {
			  addresses.remove(i); 
			  addresses.add(i, a); 
			  return i; 
		  }
	
	  }
	  addresses.add(a);
	  return (addresses.size() - 1);
  }
}