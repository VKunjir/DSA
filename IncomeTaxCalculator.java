import java.util.* ;
public class IncomeTaxCalculator {
int Emp_ID, Age ;
String Emp_name ;
double salary ;
public static void main(String[] args) {
IncomeTaxCalculator obj = new IncomeTaxCalculator() ;
obj.inputData(obj);
System.out.println(obj.Emp_name+" pay an income tax " + obj.IncomeTax(obj));
obj.diplay(obj);

}
public void inputData(IncomeTaxCalculator obj)
{
Scanner sc = new Scanner(System.in) ;
System.out.print("Enter employee ID : ");
obj.Emp_ID = sc.nextInt() ;
System.out.print("Enter employee name : ");
obj.Emp_name = sc.next() ;
System.out.print("Enter employee Age : ");
obj.Age = sc.nextInt() ;
System.out.print("Enter employee salary : ");
obj.salary = sc.nextDouble() ;
}
public double IncomeTax(IncomeTaxCalculator obj)
{
if(obj.salary <=500000)
return 0;
else if(obj.salary >500000 && obj.salary<=1000000)
return (obj.salary/10.00) ;
else if(obj.salary>1000000 && obj.salary <=5000000)
return (obj.salary/5) ;
else
return ((3*(obj.salary))/10) ;
}
public void diplay(IncomeTaxCalculator obj)
{
System.out.print("Employee ID : " + obj.Emp_ID);
System.out.println();
System.out.print("Employee name : " + obj.Emp_name );
System.out.println();
System.out.print("Employee Age : " + obj.Age) ;
System.out.println();
System.out.print("Employee salary : " + obj.salary);
System.out.println();
}
}