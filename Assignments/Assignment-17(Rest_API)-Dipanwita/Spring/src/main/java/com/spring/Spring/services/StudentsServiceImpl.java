package com.spring.Spring.services;

import com.google.gson.Gson;
import com.spring.Spring.entities.Students;
import com.spring.Spring.entities.Subjects;
import org.springframework.stereotype.Service;
import java.util.Objects;

@Service
public class StudentsServiceImpl implements StudentsService{

    @Override
    public String getStudents(String n) {
        Gson gson = new Gson();
        //Student 1
        Subjects[] arr = new Subjects[3];
        arr[0] = new Subjects("Physics", 66);
        arr[1] = new Subjects("Chemistry", 78);
        arr[2] = new Subjects("Maths", 64);
        Students stu1 = new Students("Atharva", 21, "Indore, MP", arr);
        String student1 = gson.toJson(stu1);

        //Student 2
        Subjects[] arr2 = new Subjects[3];
        arr2[0] = new Subjects("Physics", 79);
        arr2[1] = new Subjects("Chemistry", 87);
        arr2[2] = new Subjects("Maths", 97);
        Students stu2 = new Students("Koustub", 21, "Mumbai, MH", arr2);
        String student2 = gson.toJson(stu2);

        //Student 3
        Subjects[] arr3 = new Subjects[3];
        arr3[0] = new Subjects("Physics", 87);
        arr3[1] = new Subjects("Chemistry", 67);
        arr3[2] = new Subjects("Maths", 91);
        Students stu3 = new Students("Utkarsh", 21, "Bhopal, MP", arr3);
        String student3 = gson.toJson(stu3);

        String student;
        if(Objects.equals(n, stu1.getName())){
            student = student1;
        }
        else if(Objects.equals(n, stu2.getName())){
            student = student2;
        } else if (Objects.equals(n, stu3.getName())) {
            student = student3;
        }
        else {
            student = "Not Found";
        }
        return student;
    }

    @Override
    public String home(){
        return "Home Page";
    }
}
