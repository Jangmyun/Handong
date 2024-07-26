public class Rep03GradesGraphTest1
{
   public static void main(String[] args)
   {
      System.out.println();
      System.out.println("Test case 1: readInput() and writeOutput()");
      Rep03GradesGraph1 grades = new Rep03GradesGraph1();
      grades.readInput();
      System.out.println();
      System.out.println("Verify results with writeOutput():");
      grades.writeOutput();
      System.out.println("===============================");

      System.out.println();
      System.out.println("Test case 2:");
      grades.set(1, 2, 3, 4, 5);
      System.out.println("write (display) counts individually:");
      System.out.println();
      System.out.println("Use the method to change the grade value and verify that each grade value has changed.");
      System.out.println();
      grades.writeAcount();
      grades.writeBcount();
      grades.writeCcount();
      grades.writeDcount();
      grades.writeFcount();
      System.out.println("===============================");


      System.out.println();
      System.out.println("Test case 3:");
      grades.set(10, 4, 6, 2, 8);
      System.out.println("return counts individually:");
      System.out.println();
      System.out.println("Use the method to change the grade value and verify that each grade value has changed.");
      System.out.println();
      System.out.println("A count = " + grades.getAcount());
      System.out.println("B count = " + grades.getBcount());
      System.out.println("C count = " + grades.getCcount());
      System.out.println("D count = " + grades.getDcount());
      System.out.println("F count = " + grades.getFcount());
      System.out.println();
      System.out.println("===============================");
   }
}
