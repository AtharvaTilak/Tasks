package com.spring.Spring.controller;

import com.spring.Spring.services.StudentsService;
import jakarta.websocket.server.PathParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;


@RestController
@RequestMapping("/Students")
public class MyController {
    @Autowired
    private StudentsService studentsservice;
    @GetMapping("/home")
    public String home(){
        return this.studentsservice.home();
    }
    @GetMapping(value="/Student")
    public String getStudents(@RequestParam("n") String n){
        return this.studentsservice.getStudents(n);
    }
}
