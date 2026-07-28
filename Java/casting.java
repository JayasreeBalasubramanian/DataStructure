public class casting {
    public static void main(String[] args) {
        int i = 300;

        byte b = (byte) i;
        short s = (short) i;
        char c = (char) i;

        System.out.println(" integer value: " + i);
        System.out.println("byte value: " + b);
        System.out.println("short value: " + s);
        System.out.println("char value: " + c);
        System.out.println("char as integer value: " + (int) c);
    }
}