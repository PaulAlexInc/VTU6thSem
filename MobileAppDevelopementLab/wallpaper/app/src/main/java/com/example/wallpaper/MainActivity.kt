package com.example.wallpaper

import android.app.WallpaperManager
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.widget.Button


class MainActivity : AppCompatActivity() {

    lateinit var changewallpaper : Button
    val wallpaperlist = arrayOf(R.drawable.image_1,R.drawable.image_2,R.drawable.image_3,R.drawable.image_4,R.drawable.image_5)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        changewallpaper = findViewById(R.id.wallpaper_value)

        changewallpaper.setOnClickListener { setWallpaper() }
    }
    private fun setWallpaper(){
        Handler().postDelayed({
            for (i in wallpaperlist)
            {
                val bitmap = BitmapFactory.decodeResource(resources,i)
                val manager = WallpaperManager.getInstance(baseContext)
                manager.setBitmap(bitmap)
            }
        },100)
    }
}