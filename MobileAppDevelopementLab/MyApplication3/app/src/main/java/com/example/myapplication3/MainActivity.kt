package com.example.myapplication3

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import net.objecthunter.exp4j.ExpressionBuilder

class MainActivity : AppCompatActivity() {

    lateinit var one: TextView
    lateinit var two: TextView
    lateinit var three: TextView
    lateinit var four: TextView
    lateinit var five: TextView
    lateinit var six: TextView
    lateinit var seven: TextView
    lateinit var eight: TextView
    lateinit var nine: TextView
    lateinit var zero: TextView
    lateinit var point: TextView
    lateinit var addition: TextView
    lateinit var subtraction: TextView
    lateinit var multiplication: TextView
    lateinit var division: TextView
    lateinit var result: TextView
    lateinit var expression: TextView
    lateinit var equal: TextView
    lateinit var clear: TextView


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        zero = findViewById(R.id.zero)
        one = findViewById(R.id.one)
        two = findViewById(R.id.two)
        three = findViewById(R.id.three)
        four = findViewById(R.id.four)
        five = findViewById(R.id.five)
        six = findViewById(R.id.six)
        seven = findViewById(R.id.seven)
        eight = findViewById(R.id.eight)
        nine = findViewById(R.id.nine)

        addition = findViewById(R.id.addition)
        subtraction = findViewById(R.id.subtraction)
        multiplication = findViewById(R.id.multiplication)
        division = findViewById(R.id.division)

        result = findViewById(R.id.result)
        expression = findViewById(R.id.expression)
        point = findViewById(R.id.point)
        equal = findViewById(R.id.equal)
        clear = findViewById(R.id.clear)

        zero.setOnClickListener {
            pressbutton("0", true)
        }
        one.setOnClickListener {
            pressbutton("1", true)
        }
        two.setOnClickListener {
            pressbutton("2", true)
        }
        three.setOnClickListener {
            pressbutton("3", true)
        }
        four.setOnClickListener {
            pressbutton("4", true)
        }
        five.setOnClickListener {
            pressbutton("5", true)
        }
        six.setOnClickListener {
            pressbutton("6", true)
        }
        seven.setOnClickListener {
            pressbutton("7", true)
        }
        eight.setOnClickListener {
            pressbutton("8", true)
        }
        nine.setOnClickListener {
            pressbutton("9", true)
        }
        point.setOnClickListener {
            pressbutton(".", true)
        }
        addition.setOnClickListener {
            pressbutton("+", true)
        }
        subtraction.setOnClickListener {
            pressbutton("-", true)
        }
        multiplication.setOnClickListener {
            pressbutton("*", true)
        }
        division.setOnClickListener {
            pressbutton("/", true)
        }
        clear.setOnClickListener {
            result.text = ""
            expression.text = ""
        }
        equal.setOnClickListener {
            val text = expression.text.toString()
            val expression = ExpressionBuilder(text).build()
            val expResult = expression.evaluate()
            val longResult = expResult.toLong()
            if (expResult == longResult.toDouble()) {
                result.text = longResult.toString()
            } else {
                result.text = expResult.toString()
            }

        }
    }

    private fun pressbutton(s: String, b: Boolean) {
        if (b) {
            result.text = ""
            expression.append(s)
        }
    }
}