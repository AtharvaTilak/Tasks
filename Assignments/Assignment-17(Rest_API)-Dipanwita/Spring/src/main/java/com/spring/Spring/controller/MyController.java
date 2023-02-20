package com.spring.Spring.controller;

import com.spring.Spring.services.StudentsService;
import jakarta.websocket.server.PathParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

//import javax.ws.rs.GET;
//import javax.ws.rs.Path;
//import javax.ws.rs.QueryParam;

@RestController
public class MyController {
    @Autowired
    private StudentsService studentsservice;
    @GetMapping("/home")
    public String home(){
        return this.studentsservice.home();
    }
    @GetMapping("/Students/{n}")
    public String getStudents(@PathVariable("n") String n){
        return this.studentsservice.getStudents(n);
    }
}
