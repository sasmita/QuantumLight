'''
QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: processSensorData.py

This program reading data from serial port and printing them in screen
'''

import serial

ser = serial.Serial('/dev/tty.usbmodem1411', 9600)

data = []
#def getSensorData():
while True:
	val = ser.readline()
	# removing last two unnecessary characters ('\r\n')
	#val = val[:4]
	#valFloat = float(val);
	data = [val, 0, 0]
	print val,
	print data,
