import java.util.Scanner;

public class evenarray {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int size;
        System.out.print("Enter array size: ");
        size = s.nextInt();
        
        int a[] = new int[size];
        int b[] = new int[size];
        int c[] = new int[2 * size];
        int k = 0; 
        
        System.out.println("Elements of array1:");
        for(int i = 0; i < size; i++){
            a[i] = s.nextInt();
        }
        
        System.out.println("Elements of array2:");
        for(int j = 0; j < size; j++){
            b[j] = s.nextInt();
        }
        
        for(int i = 0; i < size; i++){
            if(a[i] % 2 == 0){
                c[k] = a[i];
                k++;
            }
        }
        
        for(int j = 0; j < size; j++){
            if(b[j] % 2 == 0){
                c[k] = b[j];
                k++;
            }
        }
        
        System.out.println("Elements of array3:");
        for(int i = 0; i < k; i++){
            System.out.print(c[i] + " ");
        }
        System.out.println();
        
        s.close();
    }
}