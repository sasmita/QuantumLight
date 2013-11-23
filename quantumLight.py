from classify import getWeatherClassification
import serial

tDict = getWeatherClassification('80001')
temp = tDict['tempType']

ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
ser.write(temp)

