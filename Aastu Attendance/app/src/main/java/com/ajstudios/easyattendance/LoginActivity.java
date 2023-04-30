package com.ajstudios.easyattendance;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends AppCompatActivity {

    private CheckBox ckRemember;
    private SharedPreferences pref;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);


        pref = getSharedPreferences("ACCOUNT_INFO", MODE_PRIVATE);

        final EditText etUsername = findViewById(R.id.etUsername);
        final EditText etPassword = findViewById(R.id.etPassword);

        ckRemember = findViewById(R.id.ckRemember);

        Button btGotoRegister = findViewById(R.id.btGotoRegister);
        btGotoRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(LoginActivity.this, RegisterActivity.class);
                startActivity(i);
            }
        });

        Button btLogin = findViewById(R.id.btLogin);
        btLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (etUsername.getText().toString().equals("") || etPassword.getText().toString().equals("")) {
                    return;
                }

                if (pref.getString("USERNAME", "").equalsIgnoreCase(String.valueOf(etUsername.getText().toString())) &&
                        pref.getString("PASSWORD", "").equals(etPassword.getText().toString())) {
                    Intent i = new Intent(LoginActivity.this, MainActivity.class);
                    startActivity(i);

                    updateAccountInfoPreference();
                } else {
                    Toast.makeText(LoginActivity.this, "Username and/or password is not correct", Toast.LENGTH_LONG).show();

                }

            }
        });

        // if Remember is checked then get username and password
        if (pref.getBoolean("REMEMBER", false)) {
            etUsername.setText(pref.getString("USERNAME", "").toString());
            etPassword.setText(pref.getString("PASSWORD", "").toString());
            ckRemember.setChecked(true);
        }
    }

    private void updateAccountInfoPreference() {
        SharedPreferences.Editor editor = pref.edit();
        editor.putBoolean("REMEMBER", ckRemember.isChecked());
        editor.apply();
    }
}