package com.example.texttospeech

import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.speech.tts.TextToSpeech
import android.util.Log
import android.widget.Button
import android.widget.EditText
import androidx.annotation.RequiresApi
import androidx.appcompat.widget.ButtonBarLayout
import java.util.*

class MainActivity : AppCompatActivity(), TextToSpeech.OnInitListener {

    var texttospeech : TextToSpeech? = null
    lateinit var tspeechbutton : Button
    lateinit var tspeechtext : EditText


    @RequiresApi(Build.VERSION_CODES.LOLLIPOP)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        tspeechbutton = findViewById(R.id.ttospeechbutton)
        tspeechtext = findViewById(R.id.editTextTextPersonName)
        tspeechbutton!!.isEnabled = false
        texttospeech = TextToSpeech(this, this)
        tspeechbutton.setOnClickListener{
            converttospeech()
        }
    }

    @RequiresApi(Build.VERSION_CODES.LOLLIPOP)
    private fun converttospeech(){
        val textresult = tspeechtext!!.text.toString()
        texttospeech!!.speak(textresult, TextToSpeech.QUEUE_FLUSH, null,"")

    }
    override fun onDestroy(){
        if(texttospeech!=null)
        {
            texttospeech!!.stop()
            texttospeech!!.shutdown()
        }
        super.onDestroy()
    }

    override fun onInit(status: Int) {
        if(status==TextToSpeech.SUCCESS)
        {
            val result = texttospeech!!.setLanguage(Locale.US)
            if(result == TextToSpeech.LANG_MISSING_DATA || result == TextToSpeech.LANG_NOT_SUPPORTED)
            {
                Log.e("TTS","Language not supported")
            }
            else
            {
                tspeechbutton!!.isEnabled = true
            }
        }
        else
        {
            Log.e("TTS","Failed")
        }
    }


}