public class Main {
    public static void main(String[] args) throws Exception{
        int read;
        int[] codepoint = new int[200];

        int test = 0;
        while ((read = System.in.read()) != 10) test = (test * 10) + (read - 48);

        int idx;
        for (int i = 0; i < test; i++){
            idx = 0;
            while ((read = System.in.read()) != 32) codepoint[idx++] = read;
            java.math.BigInteger b = new java.math.BigInteger(new String(codepoint, 0, idx));

            idx = 0;
            while ((read = System.in.read()) != 32) codepoint[idx++] = read;
            java.math.BigInteger c = new java.math.BigInteger(new String(codepoint, 0, idx));

            idx = 0;
            while ((read = System.in.read()) != 10) codepoint[idx++] = read;
            java.math.BigInteger d = new java.math.BigInteger(new String(codepoint, 0, idx));

            System.out.println(c.subtract(b).add(c.subtract(d)));
        }
    }
}