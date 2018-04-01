import java.math.BigInteger;
import java.util.*;
import java.math.*;
import java.io.*;


/** Fonte: http://introcs.cs.princeton.edu/java/78crypto/Karatsuba.java.html **/

class fast {
    private final static BigInteger ZERO = new BigInteger("0");

    public static BigInteger karatsuba(BigInteger x, BigInteger y) {

        // cutoff to brute force
        int N = Math.max(x.bitLength(), y.bitLength());
        if (N <= 2000) return x.multiply(y);                // optimize this parameter

        // number of bits divided by 2, rounded up
        N = (N / 2) + (N % 2);

        // x = a + 2^N b,   y = c + 2^N d
        BigInteger b = x.shiftRight(N);
        BigInteger a = x.subtract(b.shiftLeft(N));
        BigInteger d = y.shiftRight(N);
        BigInteger c = y.subtract(d.shiftLeft(N));

        // compute sub-expressions
        BigInteger ac    = karatsuba(a, c);
        BigInteger bd    = karatsuba(b, d);
        BigInteger abcd  = karatsuba(a.add(b), c.add(d));

        return ac.add(abcd.subtract(ac).subtract(bd).shiftLeft(N)).add(bd.shiftLeft(2*N));
    }

 
    public static void main(String[] args) {
        long start, stop, elapsed;
        
        Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t>0){
			java.math.BigInteger a = in.nextBigInteger();
			java.math.BigInteger b = in.nextBigInteger();
			
			BigInteger c = karatsuba(a, b);
			System.out.println(c);
			
			t--;
		}
    }
}
