package com.example.hello_cmake

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        findViewById<TextView>(R.id.textView).text = stringFromJNI()

        val buttontime = findViewById<Button>(R.id.button2)
        val buttonlog = findViewById<Button>(R.id.button3)
        val resultsview = findViewById<TextView>(R.id.textView3)

        buttontime.setOnClickListener {
            /**
            Whats happend when click
             */
        }
        buttonlog.setOnClickListener {

        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}