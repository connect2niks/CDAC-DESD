import java.util.Scanner;
public class student
{
	int id;
	String name;
	float marks;
	String res;

	void display()
	{
		System.out.println("\n\n**********Student details with result**********");
		System.out.println(id);
		System.out.println(name);
		System.out.println(marks);
	}

	void read()
	{
		Scanner s =new Scanner(System.in);
		System.out.println("Enter ID:");
			id=s.nextInt();
			System.out.println("Enter name:");
			name=s.next();
			System.out.println("Enter marks");
			marks=s.nextInt();
	}

	void result()
	{
		if(marks>33)
			System.out.println("PASS");
		else
			System.out.println("FAIL");
	}

	public static void main(String[] args)
	{
		student s1= new student();
		student s2= new student();
		System.out.println("\n\nEnter the details of first student");
		s1.read();
		System.out.println("\n\nEnter the details of second student");
		s2.read();
		
		s1.display();
		s1.result();
                
		s2.display();
		s2.result();

	}
}
