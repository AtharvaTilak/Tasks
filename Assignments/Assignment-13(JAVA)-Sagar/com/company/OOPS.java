class about {
    String name = "Atharva Sachin Tilak";
    private int Age = 21;
    char Gender = 'M';

    public int age(){
        return Age;
    }
} //Class Concept

abstract class car { // Abstract class example
    abstract void supra();
    void gtr(){
        System.out.println("Vrooooom");
    }
}

class sound extends car {
    void supra() {
        System.out.println("Stututututututu");
    }
}

class poly {
    void add(int x){ //This function increments the argument by 1
        System.out.println(x+1);
    }

    void add(int x, int y){ // This function adds both of the integer arguments
        System.out.println(x+y);
    }

    void add(double x, double y){ // This function adds both of the double arguments
        System.out.println(x + y);
    }
} // This class represents Polymorphism

// Classes hi and bye show examples of a strong coupling
class hi {
    bye b = new bye();
    void print() {
        b.non();
    }
}

class bye {
    void non() {
        System.out.println("Bye");
    }
}

public class OOPS extends about{
    String company = "FortyTwo Labs";
    int salary = 15000; //Example of Inheritance
    public static void main(String[] args) {
        //Objects Concept
        OOPS obj = new OOPS();
        System.out.println(obj.name + " has a salary of Rs. " + obj.salary + " in " + obj.company);
        
        //Following code is used for polymorphism
        poly object = new poly();
        object.add(7);
        object.add(2.1500, 13.165);
        object.add(5, 6);
        
        // Abstraction Concept
        sound s = new sound();
        s.supra();
        s.gtr();

        // Encapsulation Concept
        System.out.println(obj.age());
    }
    
}

