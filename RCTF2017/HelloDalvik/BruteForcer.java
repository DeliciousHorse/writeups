package com.company;

public class BruteForcer {
    private static String[] hashes= new String[]{"6F50D5057EFB2B9411C1B237E7D8588D", "98DD67FE3789D499AB3AF3CD1055EB76", "10556D767F835C91A9B2BBCF98DDE4FE", "72AD4A98C3603EE1865407ACFA25C210"};
    private static String code = "a#s224kfuSaom=D469asSkOdhmP34!@-";
    private static String hexdigits = "0123456789ABCDEF";
    private static char[] codeCharArr;
    static {
        codeCharArr = code.toCharArray();
    }

    private static char[] processString1(String triple) {
        char[] resultHash = new char[32];
        char[] tripArr = triple.toCharArray();

        for(int i = 0; i < tripArr.length; i++) {
            tripArr[i] = (char)(tripArr[i] % 10);
        }
        int a,b,c,d,e,f,h;
        for(int i = 0; i < 32; ++i) {
            h = i % tripArr.length;
            b = i % codeCharArr.length;
            c = b + tripArr[h];
            d = c % codeCharArr[b];
            f = c * d;
            e = d ^ codeCharArr[h];
            a = f + e;
            resultHash[i] = (char)(a & 0xFF);
        }
        return resultHash;
    }

    private static String processString2(char[] hash, String triple) {
        String result = "";
        assert triple.length() == 32;

        char[] tripArr = triple.toCharArray();
        char[] hexes = hexdigits.toCharArray();

        for(int i = 0; i < tripArr.length; ++i) {
            tripArr[i] = (char)(tripArr[i] / 10 % 10);
        }
        for(int i = 0; i < 32; i++) {
            result += hexes[(tripArr[i % tripArr.length] + hash[i]) % 16];
        }
        return result;
    }

    private static String crackTriple(int hashIdx) {
        for(char a = (char)32; a < (char)127; a++)
            for(char b = (char)32; b < (char)127; b++)
                for(char c = (char)32; c < (char)127; c++) {
                    String triple = "" + a + b + c;
                    char[] tmp = processString1(triple);
                    String result = processString2(tmp, triple);
                    if (hashes[hashIdx].equals(result)) {
                        return triple;
                    }
                }
        return null;
    }

    public static void main(String[] args) {
        String flag = "";
        for(int i = 0; i < hashes.length; i++)
            flag += crackTriple(i);
        System.out.println(flag);
    }
}
