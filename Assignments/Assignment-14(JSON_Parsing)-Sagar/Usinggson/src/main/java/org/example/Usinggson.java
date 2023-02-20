package org.example;

import com.google.gson.Gson;


class students {
    String Name = "Atharva Sachin Tilak";
    int rollno = 19;
    String Branch = "PCM";
    public subjects Subjects;
    public students(String Name, int rollno, String Branch, subjects Subjects) {
        this.Name = Name;
        this.Subjects = Subjects;
        this.Branch = Branch;
        this.rollno = rollno;
    }
}

class subjects {
    int Maths = 45;
    int Physics = 33;
    int Chemistry = 78;

    public subjects(int Maths, int Physics, int Chemistry) {
        this.Maths = Maths;
        this.Physics = Physics;
        this.Chemistry = Chemistry;
    }
}
class job {}


public class Usinggson
{
    public static void main( String[] args )
    {
        //javatojson();
        jsontojava();
    }
    // Below example shows Java to JSON
    private static void javatojson(){
        subjects sub = new subjects(45, 33, 78);
        students stu = new students("Atharva Sachin Tilak", 19, "PCM", sub);
        Gson gson = new Gson();
        String Json = gson.toJson(stu);
        System.out.println(Json);
    }
    // This example shows JSON to JAVA
    private static void jsontojava() {
        String json = "{'Name':'Atharva Sachin Tilak','rollno':19,'Branch':'PCM','Subjects':{'Maths':45,'Physics':33,'Chemistry':78}}";
        Gson gson = new Gson();
        students Students = gson.fromJson(json, students.class);
        System.out.println(Students);
    }
}