package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private void toast(String text){
        Toast.makeText(this, text, Toast.LENGTH_SHORT).show();
    }
    String number;
    String password;
    EditText inputNumber;
    EditText inputPassword;
    Button checkbox;
    Button submit;
    TextView nprint;
    TextView pprint;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        inputNumber = findViewById(R.id.inputNumber);
        inputPassword = findViewById(R.id.inputPassword);
        checkbox = findViewById(R.id.checkbox);
        submit = findViewById(R.id.submit);
        nprint = findViewById(R.id.nprint);
        pprint = findViewById(R.id.pprint);

        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                number = inputNumber.getText().toString();
                password = inputPassword.getText().toString();
                if(password.isEmpty()){
                    toast("Please enter a password");
                }
                else if(inputNumber.getText().toString().isEmpty()){
                    toast("Please enter your mobile number");
                }
                nprint.setText(number);
                pprint.setText(password);
            }
        });

    }
}