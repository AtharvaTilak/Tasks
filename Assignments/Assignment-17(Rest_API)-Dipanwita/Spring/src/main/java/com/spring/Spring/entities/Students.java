package com.spring.Spring.entities;

public class Students {
    private String name;
    private int age;
    private String address;
    private Subjects[] subjects;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public Subjects[] getSubjects() {
        return subjects;
    }

    public void setSubjects(Subjects[] subjects) {
        this.subjects = subjects;
    }

    public Students(String name, int age, String address, Subjects[] subject) {
        super();
        this.name = name;
        this.age = age;
        this.address = address;
        this.subjects = subject;
    }
}
