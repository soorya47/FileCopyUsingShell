import java.util.Scanner;

public class FileCopy {  
	   static {
	      System.loadLibrary("fileCopy"); 
	   }
	 
	   // Declare an instance native method sayHello() which receives no parameter and returns void
	   private native boolean copyFile(String s1,String s2);
	 
	   // Test Driver
	   public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		System.out.println("enter Path1");
		String s1=sc.nextLine();
		System.out.println("enter Path2");
		String s2=sc.nextLine();
		FileCopy obj= new FileCopy();
		boolean process= obj.copyFile(s1,s2);
		if(process)
			System.out.println("file copy success");
		else
			System.out.println("file copy failure");
	   }
	}