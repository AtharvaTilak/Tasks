package org.example;

import com.google.gson.Gson;

public class Main {
    public static void main(String[] args) {
        serialize();
    }

    public static void serialize(){
        subjects[] arr = new subjects[2];
        arr[0] = new subjects("Physics", 66);
        arr[1] = new subjects("Maths", 78);
        students stu = new students("Atharva Sachin Tilak", 21, "Indore, MP", arr);
        Gson gson = new Gson();
        String json = gson.toJson(stu);
    }
}
