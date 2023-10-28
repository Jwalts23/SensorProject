#include "Ultrasonic.h"

        Ultrasonic::Ultrasonic(uint8_t TrigPin, uint8_t EchoPin){
            trigPin = TrigPin;
            echoPin = EchoPin;

        }

        void Ultrasonic::init(){
            pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
            pinMode(echoPin, INPUT); // Sets the echoPin as an Input
        }
        
        float Ultrasonic::distanceINcm(){
            float duration;
            // Clears the trigPin
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            // Sets the trigPin on HIGH state for 10 micro seconds
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            // Reads the echoPin, returns the sound wave travel time in microseconds
            duration = pulseIn(echoPin, HIGH);
            // Calculating the distance
            return duration * 0.034 / 2;

        }

        float Ultrasonic::distanceINinches(){
            return distanceINcm()/2.54;
        }
        