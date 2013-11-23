/*

QuantumLight
SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

This program allows us to communicate from computer to Arduino. 
This program also calls the serial module to display the LED depending on weather condition.

*/


from weather import getWeatherInfo
import serial

wList = getWeatherInfo('97229')

if (wList[0] < 10.0):
	temp = '1'
else:
	temp = '0'

print wList[0]
print 'class:', temp
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
ser.write(temp)

