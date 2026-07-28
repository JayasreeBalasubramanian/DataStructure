import java.util.Scanner;
public class binary{
    public static void main(String args[]){
            Scanner s=new Scanner(System.in);
            int a=s.nextInt();
            int binary=0;
            while (a > 0)
            {
            int rem = a % 2;      
            binary = rem + binary; 
            a = a / 2;
            }
          System.out.println(binary);
}
}