
'''
QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: quantumLight.py

This program display different LED patterns depending on the weather classification.

This program calls the getWeatherclassification module from classify.py. Once we get the classification, we communicate that to Arduino to display the led pattern accordingly.
'''

import classify
import serial

# 
tDict = classify.getWeatherClassification('85003')

temperatureClass = tDict['tempType']

# 
ser = serial.Serial('/dev/tty.usbmodem1411', 9600)

#
ser.write('2') 
#ser.write(temperatureClass)
