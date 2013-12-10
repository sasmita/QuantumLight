'''
QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: processSensorData.py

This program reading data from serial port and printing them in screen
'''

import serial
import time

ser = serial.Serial('/dev/tty.usbmodem1411', 9600, timeout = 1.0)
buffer = []

while True:
	val = ser.readline()
	buffer.append(val) 
	print(val)  
	print buffer
