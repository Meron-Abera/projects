package com.ajstudios.easyattendance;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.widget.Toast;

public class SplashActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);
        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();

        try {
            /* New Handler to start the Menu-Activity
             * and close this Splash-Screen after some seconds.*/
            new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    Intent i = new Intent(SplashActivity.this, LoginActivity.class);
                    startActivity(i);
                    finish();
                }
            }, 3000);


        } catch (Exception ex) {
            Toast.makeText(getApplicationContext(), ex.getMessage(), Toast.LENGTH_LONG).show();
        }
    }
}