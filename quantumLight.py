/*

QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: quantumLight.py

This program also calls the getWeatherclassification module from classify.py. 
<<<<<<< HEAD
This program communicates from computer to Arduino and turns the LED on/off depending on the classification obtained from a particular weather condition. 
=======
This program communicates from computer to Arduino and turns the LED on/off 
depending on the classification obtained from a particular weather condition. 
>>>>>>> 09a3f2ae632a939e3f44fc699a0a15eb05df325e

*/

from classify import getWeatherClassification
import serial

tDict = getWeatherClassification('80001')
temp = tDict['tempType']

ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
ser.write(temp)

