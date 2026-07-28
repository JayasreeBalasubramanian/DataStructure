import java.util.Scanner;

class Library {
    int rollno;
    int fineday;
    int course;

    Library(int r, int f) {
        rollno = r;
        fineday = f;
    }
    Library() {
        rollno = 001;
        fineday = 10;
    }
    void getdetails() {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the roll no:");
        rollno = s.nextInt();

        System.out.print("Enter 1-UG, 2-PG, 3-Research scholar, 4-Faculty:");
        course = s.nextInt();

        switch (course) {
            case 1: {
                System.out.println("ug");
                break;
            }

            case 2: {
                System.out.println("pg");
                break;
            }

            case 3: {
                System.out.println("research scholar");
                break;
            }

            case 4: {
                System.out.println("faculty");
                break;
            }
        }
    }
    void ug(int fine) {
        int actualday = 15;

        if (fine >= actualday) {
            if ((fine - actualday) == 0) {
                System.out.println("no fine:");
            } 
            else if (((fine - actualday) >= 1) && ((fine - actualday) <= 10)) {
                System.out.println("Fine amount is:" + ((fine - actualday) * 5));
            } 
            else if (((fine - actualday) >= 11) && ((fine - actualday) <= 25)) {
                System.out.println("Fine amount is:" + ((fine - actualday) * 10));
            } 
            else {
                System.out.println("Fine amount is:" + ((fine - actualday) * 15));
            }
        }
    }

    void pg(int fine) {
        int actualday = 30;

        if (fine >= actualday) {
            if ((fine - actualday) == 0) {
                System.out.println("no fine:");
            } 
            else if (((fine - actualday) >= 1) && ((fine - actualday) <= 30)) {
                System.out.println("Fine amount is:" + ((fine - actualday) * 10));
            } 
            else {
                System.out.println("Fine amount is:" + ((fine - actualday) * 15));
            }
        }
    }

    void rs(int fine) {
        int actualday = 60;

        if (fine >= actualday) {
            if ((fine - actualday) == 0) {
                System.out.println("no fine:");
            } 
            else if (((fine - actualday) >= 1) && ((fine - actualday) <= 30)) {
                System.out.println("Fine amount is:" + ((fine - actualday) * 10));
            } 
            else {
                System.out.println("Fine amount is:" + ((fine - actualday) * 15));
            }
        }
    }

    void faculty(int fine) {
        int actualday = 180;

        if (fine >= actualday) {
            if ((fine - actualday) == 0) {
                System.out.println("no fine:");
            } 
            else {
                System.out.println("Fine amount is:" + ((fine - actualday) * 15));
            }
        }
    }
}

public class demo1 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        int n;

        System.out.println("Enter the number of students:");
        n = s.nextInt();

        Library lobj[] = new Library[n];

        for (int i = 0; i < n; i++) {
            lobj[i] = new Library();

            lobj[i].getdetails();

            System.out.print("Enter the number of days after borrowing the book:");
            int finedays = s.nextInt();

            switch (lobj[i].course) {
                case 1:
                    lobj[i].ug(finedays);
                    break;

                case 2:
                    lobj[i].pg(finedays);
                    break;

                case 3:
                    lobj[i].rs(finedays);
                    break;

                case 4:
                    lobj[i].faculty(finedays);
                    break;

                default:
                    System.out.println("Invalid course");
            }
        }
    }
}