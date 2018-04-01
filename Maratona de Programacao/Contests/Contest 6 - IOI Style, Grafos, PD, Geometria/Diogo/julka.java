import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception{
    //public static void main(String[] args){
	Scanner scan = new Scanner(System.in);
	int t = 10;
	while(t!=0){
		java.math.BigInteger todas = scan.nextBigInteger();
		java.math.BigInteger klaudiamais = scan.nextBigInteger();


		//BigInteger klaudiamais = BigInteger.valueOf(scan.nextInt());
		BigInteger x = todas.add(klaudiamais);
		BigInteger y = todas.subtract(klaudiamais);
		BigInteger dois = new BigInteger("2");
		System.out.println(x.divide(dois));
		System.out.println(y.divide(dois));		
		
		t--;
	}

    }
}
