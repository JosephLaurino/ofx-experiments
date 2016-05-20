#pragma once

#include "ofMain.h"

// ofLog is the way openframeworks applications output text to the console
// in a similar fashion to println() and print() in Processing
// http://openframeworks.cc/documentation/utils/ofLog/

class ofApp : public ofBaseApp
{
    
public:
    void setup()
    {
        
        // To print text to the console, place the desired output in quotes
        ofLog() << "Processing...";  // Prints "Processing..." to the console
        
        // To print the value of a variable, rather than its name,
        // donÕt put the name of the variable in quotes
        int x = 20;
        ofLog() << x; // Prints "20" to the console
    
        // chain multiple values and add a space in between
        int x2 = 20;
        int y2 = 80;
        ofLog() << x2 << " " << y2;  // Prints "20 80" to the console
        
        int x3 = 20;
        int y3 = 80;
        ofLog() << x3 << " and " << y3;  // Prints "20 and 80" to the console
        
    }
};





/*
    // To print text to the console, place the desired output in quotes
    println("Processing...");  // Prints "Processing..." to the console

    // To print the value of a variable, rather than its name, 
    // donÕt put the name of the variable in quotes
    int x = 20;
    println(x);  // Prints "20" to the console 

    // While println() moves to the next line after the text 
    // is output, print() does not
    print("10"); 
    println("20");  // Prints "1020" to the console
    println("30");  // Prints "30" to the console 

    // Use a comma inside println() to write more than one value
    int x2 = 20;
    int y2 = 80;
    println(x2, y2);  // Prints "20 80" to the console

    // Use the "+" operator to combine variables with 
    // custom text in between
    int x3 = 20;
    int y3 = 80;
    println(x3 + " and " + y3);  // Prints "20 and 80" to the console
*/