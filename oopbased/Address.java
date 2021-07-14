public class Address
{
  /** The name of the business */
  private String name;

  /** The name of the street the business is on */
  private String street;

  /** The street number of the business */
  private int number;

  /** Constructs an Address that represents a business with name nm, at number no on the
   * the street st.
   */
  public Address(String nm, String st, int no)
  {
    name = nm;
    street = st;
    number = no;
  }

  /** Returns the name of the business */
  public String getName()
  { return name;  }

  /** Returns the name of the street on which the business is located */
  public String getStreet()
  { return street;  }

  /** Returns the street number of the business */
  public int getNumber()
  { return number;  }
}