package com.ajstudios.easyattendance;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.regex.Pattern;

public class RegisterActivity extends AppCompatActivity {

    EditText etFullName, etEmail, etUsername, etPassword, etConfirmPassword;
    RadioButton rbMale, rbFemale;
    Spinner spDepartment, spCollege;
    Button btRegister;

    private static final Pattern PASSWORD_PATTERN =
            Pattern.compile("^" +
                    "(?=.*[@#$%^&+=])" +     // at least 1 special character
                    "(?=\\S+$)" +            // no white spaces
                    ".{4,}" +                // at least 4 characters
                    "$");
    private static final Pattern Email_PATTERN =
            Pattern.compile("[a-zA-Z0-9._-]+@[a-z]+\\.+[a-z]+");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        etFullName = findViewById(R.id.etFull_name);
        etEmail = findViewById(R.id.etEmail);
        etUsername = findViewById(R.id.etUsername);
        etPassword = findViewById(R.id.etPassword);
        etConfirmPassword = findViewById(R.id.etConfirmPassword);

        rbMale = findViewById(R.id.rbMale);
        rbFemale = findViewById(R.id.rbFemale);

        spDepartment = findViewById(R.id.spDepartment);
        spCollege = findViewById(R.id.spCollege);

        btRegister = findViewById(R.id.btRegister);

        btRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                View focusView = null;

                String pass=etPassword.getText().toString();
                String cpass=etConfirmPassword.getText().toString();
                String email = etEmail.getText().toString();

                if (etFullName.getText().toString().equals("")) {
                    etFullName.setError(getString(R.string.error_field_required));
                    focusView = etFullName;
                    focusView.requestFocus();
                } else if (!Email_PATTERN.matcher(email).matches()) {
                    etEmail.setError("Invalid email address");
                    focusView = etEmail;
                    focusView.requestFocus();
                } else if (etUsername.getText().toString().equals("")) {
                    etUsername.setError(getString(R.string.error_field_required));
                    focusView = etUsername;
                    focusView.requestFocus();
                } else if (etPassword.getText().toString().equals("")) {
                    etPassword.setError(getString(R.string.error_field_required));
                    focusView = etPassword;
                    focusView.requestFocus();
                }
                else if (!PASSWORD_PATTERN.matcher(pass).matches()) {
                    etPassword.setError("Password is too weak");
                    focusView = etPassword;
                    focusView.requestFocus();
                }
                else if (!pass.equals(cpass)) {
                    etConfirmPassword.setError("Password is not match");
                    focusView = etConfirmPassword;
                    focusView.requestFocus();
                }
                else {

                    SharedPreferences pref = getSharedPreferences("ACCOUNT_INFO", MODE_PRIVATE);
                    SharedPreferences.Editor editor = pref.edit();
                    editor.putString("FULL_NAME", etFullName.getText().toString());
                    editor.putString("EMAIL", etEmail.getText().toString());
                    editor.putString("SEX", rbMale.isChecked() ? "Male" : "Female");
                    editor.putString("COLLEGE", spCollege.getSelectedItem().toString());
                    editor.putString("DEPARTMENT", spDepartment.getSelectedItem().toString());
                    editor.putString("USERNAME", etUsername.getText().toString());
                    editor.putString("PASSWORD", etPassword.getText().toString());
                    editor.apply();

                    Toast.makeText(RegisterActivity.this, "Registered Successfully", Toast.LENGTH_LONG).show();
                    Intent i = new Intent(RegisterActivity.this, LoginActivity.class);
                    startActivity(i);
                }
            }
        });

    }
}