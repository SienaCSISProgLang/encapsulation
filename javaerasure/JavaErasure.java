/*
  Example showing how erasure in Java generics can lead to a run-time
  error.

  Jim Teresco, The College of Saint Rose, CSC 433, Fall 2014

  Similar examples exist in many places, this is based on an example at 
  http://code.stephenmorley.org/articles/java-generics-type-erasure/

*/

import java.util.ArrayList;

public class JavaErasure {

    public static void main(String args[]) {

	// create an ArrayList of String, which at run time will
	// be seen as an ArrayList (with the type parameter erased)
	ArrayList<String> someStrings = new ArrayList<String>();

	someStrings.add("Java Erasure!");

	// and I can get values out without a cast - yay generics
	String whatIPutIn = someStrings.get(0);

	// nothing says we can't refer to this in a non-parameterized
	// ArrayList variable...  Not so much as a compiler warning
	ArrayList plain = someStrings;

	// But now I can add anything I want to this ArrayList!
	// but when this is here, we do get a warning about unchecked
	// or unsafe operations
	plain.add(new Integer(23));

	System.out.println("My ArrayList has " + someStrings.size() +
			   " elements");

	// but we see that a run-time error can now occur...
	// the generics implementation puts in an implicit cast here
	// to make sure the thing coming out is in fact still a
	// String, which it's not, hence a ClassCastException
	String whatElseIPut = someStrings.get(1);

    }

}
