
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
import processSensorData


#
sensorData = 0 
zipcode = '85003'
print zipcode

tDict = classify.getWeatherClassification(zipcode,sensorData)

print tDict

t = tDict['t']
w = tDict['ws']

# 
srl = serial.Serial('/dev/tty.usbmodem1411', 9600)

#
pattern = '-1'

#
if (t == 0 and w == 0):
   #
   pattern = '0'
elif(t == 0 and w == 1):
   #
   pattern = '1'
elif(t == 0 and w == 2):
   pattern = '2'
#
elif(t == 1 and w == 0):
   pattern = '3'
elif(t == 1 and w == 1):
   pattern = '4'
elif(t == 1 and w == 2):
   pattern = '5'

#
elif(t == 2 and w == 0):
   pattern = '6'
elif(t == 2 and w == 1):
   pattern = '7'
elif(t == 2 and w == 2):
   pattern = '8'

print 'pattern: ', pattern
srl.write('6')
#srl.write(pattern) 
