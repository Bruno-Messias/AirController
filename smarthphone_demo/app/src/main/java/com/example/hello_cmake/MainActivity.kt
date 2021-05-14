package com.example.hello_cmake

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main) //Adding created layout

        // Example of a call to a native method
        findViewById<TextView>(R.id.textView).text = stringFromJNI()

        val buttontime = findViewById<Button>(R.id.button2) //Adding variables for a easy controler
        val buttonlog = findViewById<Button>(R.id.button3)
        val resultsview = findViewById<TextView>(R.id.textView3)

        resultsview.text = " " //Clear textview

        //When button time pressed execute the function
        buttontime.setOnClickListener {
            resultsview.text = totalTime()
        }
        //When button log pressed execute the function
        buttonlog.setOnClickListener {
            resultsview.text = listEvents()
        }
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String //Adding JNI for NDK functions
    external fun listEvents(): String
    external fun totalTime(): String


    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib") //Import native lib with jni calls
        }
    }
}