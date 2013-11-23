/*

QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: quantumLight.py

This program also calls the getWeatherclassification module from classify.py. 
This program communicates from computer to Arduino and turns the LED on/off 
depending on the classification obtained from a particular weather condition. 

*/

from classify import getWeatherClassification
import serial

tDict = getWeatherClassification('80001')
temp = tDict['tempType']

ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
ser.write(temp)

