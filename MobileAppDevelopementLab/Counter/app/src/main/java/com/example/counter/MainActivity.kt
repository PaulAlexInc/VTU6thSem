package com.example.counter

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {

    lateinit var counter : TextView
    lateinit var startbutton : Button
    lateinit var stopbutton : Button

    var timer = mycounter(1000000,1000)
    var countervalue : Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        counter = findViewById(R.id.counter_value)
        startbutton = findViewById(R.id.start_button)
        stopbutton = findViewById(R.id.stop_button)
        stopbutton.isEnabled=false
        startbutton.setOnClickListener {
            timer.start();
            startbutton.isEnabled=false
            stopbutton.isEnabled=true
        }
        stopbutton.setOnClickListener {
            timer.cancel();
            stopbutton.isEnabled=false
            startbutton.isEnabled=true
        }
    }
    inner class mycounter(x: Long,y : Long) : CountDownTimer(x,y)
    {
        override fun onFinish() {
            counter.text = "Done with Timer"
        }
        override fun onTick(millisUntilFinished: Long) {
            countervalue++
            counter.text = (countervalue).toString()
        }


    }
}