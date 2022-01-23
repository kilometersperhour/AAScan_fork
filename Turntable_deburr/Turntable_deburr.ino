// AAScan: Open source, minimalist, fully automated 3D scanner based on Arduino and Android!

// Arduino program - To be uploaded to Arduino

// Copyright (C) 2020 redditNewUser2017
// Check out my page https://www.reddit.com/user/redditNewUser2017 and my subreddit https://www.reddit.com/r/Simulations/

//     This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/agpl-3.0.en.html>. 

#include <Stepper.h>
const int motorPin1=8;  // 1st input to Darlington array
const int motorPin2=10; // 2nd input "                   "
const int motorPin3=9;  // 3rd input "                   "
const int motorPin4=11; // 4th input "                   "
const int stepsPerRevolution = 2048; // number of steps per revolution
const int gearRatio = 50/10; // quotient of large teeth divided by small teeth
Stepper stepper1(stepsPerRevolution, motorPin1,motorPin3,motorPin2,motorPin4); // steps/rev, motor pins 1 2 3 4

int numSteps=180;
const int stepsPerGo = gearRatio*stepsPerRevolution/numSteps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setSpeed(5);
}

void loop() {
  // put your main code here, to run repeatedly:
 stepper1.step(stepsPerGo);
}
