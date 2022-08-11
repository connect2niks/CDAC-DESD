import java.util.Scanner;
public class emp
{
	int empno;
	String empname;
	String designation;
	String dept;
	float salary;
	
       public static void main(String[] args)
       {
	         emp e1 = new emp();

		 System.out.println("enter e1 data");
		 e1.readEmpData();

		 e1.displayEmpData();
		
       }

	 void readEmpData()
	 {
		 Scanner s = new Scanner(System.in);
		 System.out.println("Enter Employee Number");
		 empno =s.nextInt();
		  System.out.println("Enter Employee Name");
		 empname = s.next();
		  System.out.println("Enter Employee Designation");
		 designation =s.next();
		  System.out.println("Enter Employee Department");
		 dept =s.next();	 
		  System.out.println("Enter Employee Salary");
		 salary = s.nextFloat();
	 }

	 void displayEmpData()
	 {
		 System.out.println("\n\n #####Employee Details#####");

		 System.out.println(empno);
		 System.out.println(empname);
		 System.out.println(salary);
		 System.out.println(designation);
		 System.out.println(dept);

	 }
	
}
