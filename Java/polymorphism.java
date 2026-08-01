import java.util.Scanner;
class Student{
    int rollno;
    void getdetails()
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the roll no:");
        rollno=s.nextInt();
    }
}
class Fulltime extends Student{
    int assess1;
    int ca;
    int endsem;
    void getdetails()
    {
       super.getdetails();
       Scanner s=new Scanner(System.in);
       System.out.println("Enter assess1 mark:");
       assess1=s.nextInt();
       System.out.println("Enter ca mark:");
       ca=s.nextInt();
       System.out.println("Enter endsem mark:");
       endsem=s.nextInt();
    }
    void total(int assess1,int ca,int endsem)
    {
        float a=assess1*0.2f;
        float b=ca*0.4f;
        float c=endsem*0.4f;
        float total=a+b+c;
        System.out.println("Total is:"+total);
    }
}
class Parttime extends Student{
    int assess1;
    int assess2;
    int ca;
    int endsem;
    void getdetails()
    {
       super.getdetails();
       Scanner s=new Scanner(System.in);
       System.out.println("Enter assess1 mark:");
       assess1=s.nextInt();
       System.out.println("Enter assess2 mark:");
       assess2=s.nextInt();
       System.out.println("Enter ca mark:");
       ca=s.nextInt();
       System.out.println("Enter endsem mark:");
       endsem=s.nextInt();
    }
    void total(int assess1,int assess2,int ca,int endsem)
    {
        float a=assess1*0.2f;
        float b=ca*0.2f;
        float c=endsem*0.2f;
        float d=assess2*0.4f;
        float total=a+b+c+d;
        System.out.println("Total is:"+total);
    }
}
public class polymorphism
{
    public static void main(String args[])
    {
      Scanner s=new Scanner(System.in);
      int n,choice;
      System.out.println("Enter number of students:");
      n=s.nextInt();
      for(int i=0;i<n;i++)
      {
        System.out.println("Enter choice 1-Parttime and 2-Fulltime:");
      choice=s.nextInt();
        if(choice==1)
        {
        Fulltime ft[]= new Fulltime[n];
        ft[i]=new Fulltime();
        ft[i].getdetails();
        ft[i].total(ft[i].assess1, ft[i].ca, ft[i].endsem);
        }
        else if(choice==2)
        {
        Parttime pt[] = new Parttime[n];
        pt[i]=new Parttime();
        pt[i].getdetails();
        pt[i].total(pt[i].assess1, pt[i].assess2, pt[i].ca, pt[i].endsem);

        }
      }
    }
}