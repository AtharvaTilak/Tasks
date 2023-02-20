import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        ////////////////////////////////////////////// ArrayList //////////////////////////////////////////////
        // Example of ArrayList
        ArrayList<Integer> al = new ArrayList<Integer>();

        // Creating a ArrayList
        for(int i = 5; i >= 0; i--){
            al.add(i);
        }
        System.out.println(al);

        // Adding a element in between
        al.add(1, 5);
        System.out.println(al);

        // Removing a element
        al.remove(0);
        System.out.println(al);

        // Sorting the ArrayList
        Collections.sort(al);
        System.out.println(al);

        ////////////////////////////////////////////// LinkedList //////////////////////////////////////////////
        //Examples of LinkedList
        LinkedList<Integer> ll = new LinkedList<Integer>();
        for(int i = 5; i >= 0; i--){
            ll.add(i);
        }


        ll.addLast(6);
        ll.addFirst(7);
        Collections.sort(ll);
        System.out.println(ll);

        ////////////////////////////////////////////// Vector //////////////////////////////////////////////
        // Examples of Vector
        Vector v = new Vector();
        v.add("Vector");
        v.add(42);

        Iterator i = v.iterator();
        while(i.hasNext()){
            System.out.println(i.next() + " ");
        }
        System.out.println(v);

        ////////////////////////////////////////////// Stack //////////////////////////////////////////////
        Stack s = new Stack();
        s.add(25);
        s.push(35);
        s.push(45);
        s.push(55);
        s.pop();
        s.peek();


        System.out.println(s);
        System.out.println(s.size());
        if(!s.isEmpty()){
            System.out.println("Not Empty");
        }else {
            System.out.println("Empty");
        }

        ////////////////////////////////////////////// ArrayDeque //////////////////////////////////////////////
        ArrayDeque<Integer> ad = new ArrayDeque<Integer>();
        ad.add(5);
        ad.add(10);
        ad.addFirst(0);
        ad.addLast(15);
        ad.push(-5);
        ad.remove();
        ad.removeLast();

        System.out.println(ad.getFirst());
        System.out.println(ad.getLast());
        System.out.println(ad);

        ////////////////////////////////////////////// HashSet //////////////////////////////////////////////
        HashSet<Integer> hs = new HashSet<>();
        hs.add(1);
        hs.add(2);
        hs.add(3);
        hs.add(4);
        hs.add(5);
        if(hs.contains(2)){
            System.out.println("True");
        }
        System.out.println(s.size());

        System.out.println(hs);

        ////////////////////////////////////////////// LinkedHashSet //////////////////////////////////////////////
        LinkedHashSet<Integer> lhs = new LinkedHashSet<>();
        lhs.add(11);
        lhs.add(12);
        lhs.add(33);
        lhs.add(44);
        lhs.add(55);

        System.out.println(lhs);

        ////////////////////////////////////////////// HashSet //////////////////////////////////////////////





    }
}
