import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

public class HolaMundo {

	public static void main(String[] args) {
		//print
		System.out.println("Hola Java!");
		
		
		//VAR
		
		String myString = "Numero";
		
		final String myConstant = "Cadena de texto constante";
		Integer numero = 66;
		numero++;
		System.out.printf("Mi Numero Favorito es el %s %d\n",myString, numero);
		Double numeroDouble = 0.0;
		numeroDouble += 7.27;
		System.out.printf("Tambien es el %.2f\n",numeroDouble);
		Float numeroFloat = 6.9f;
		System.out.printf("%-10s %9s","Posicion", "Numero\n");
		System.out.printf("%-10s %8s\n%-10s %8s\n%-10s %8s\n", "Primero: ", numeroFloat, "Segundo: ", numeroDouble, "Tercero: ", numero);
		//System.out.println("\nPrimero: " + numeroFloat + "\nSegundo: " + numeroDouble + "\nTercero: "+ numero);
		System.out.println(myConstant);

		
		Boolean myBool = true;
		myBool = false;
		System.out.println(myBool);
		
		myBool = null;
		System.out.println(myBool);
		
		numeroFloat = null;
		if (numeroFloat != null) {
			System.out.println(numeroFloat + 10);
			System.out.println("Numero Float es distinto de nulo");
		}else {
			System.out.println("Numero Float es nulo");
		}
		
		if (numero == 66) {
			System.out.println("Mi numero es 66");

		}else if (numero == 67) {
			System.out.println("Mi numero es six seven");

		}else {
			System.out.println("Mi numero no es 66 ni 67");

		}
		
		List myList = new ArrayList(); 
		myList.add(myString);
		myList.add(numero.toString());
		System.out.println(myList);

		Map<String, String>myMap = new HashMap();
		myMap.put("string", myString);
		myMap.put("int", numero.toString());
		System.out.println(myMap);
		//System.out.println(myMap.get("int"));
		
		for (int i = 0; i< myList.size(); i++) {
			myList.get(i);
			System.out.println(myList.get(i));
		}
		
		
		HolaMundo myMain = new HolaMundo();
		System.out.println(myMain.myFunction(60,7));
	}
	public int myFunction(int myFirstNumber, int mySecondNumber) {
		return myFirstNumber + mySecondNumber;
	}
}
