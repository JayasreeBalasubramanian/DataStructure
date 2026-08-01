import java.util.Scanner;

public class BowlStacking {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        System.out.print("Enter the number of bowls: ");
        int n = s.nextInt();
        
        int[][] bowls = new int[n][2];
        
        for (int i = 0; i < n; i++) {
            System.out.print("Enter length and depth for bowl " + (i + 1) + ": ");
            bowls[i][0] = s.nextInt();
            bowls[i][1] = s.nextInt();
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (bowls[j][0] > bowls[j + 1][0] || (bowls[j][0] == bowls[j + 1][0] && bowls[j][1] < bowls[j + 1][1])) {
                    int[] temp = bowls[j];
                    bowls[j] = bowls[j + 1];
                    bowls[j + 1] = temp;
                }
            }
        }
        
        int[] dp = new int[n];
        int maxBowls = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (bowls[i][0] > bowls[j][0] && bowls[i][1] > bowls[j][1]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > maxBowls) {
                maxBowls = dp[i];
            }
        }
        
        System.out.println("Output: " + maxBowls);
        
       
    }
}