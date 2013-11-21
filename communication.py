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

