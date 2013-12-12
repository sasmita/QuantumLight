'''
QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: processSensorData.py

This program reading data from serial port and printing them in screen
'''

import serial



def getSensorData():
    # connecting arduino via serial port
    srl = serial.Serial('/dev/tty.usbmodem1411', 9600)

    data = []
    # reading from arduino via serial port
    val = srl.readline()
    # removing last two unnecessary characters ('\r\n')
    val = val[:5]
    data = [float(val), 0.0, 0.0]
    #print data
    srl.close()

    return data

