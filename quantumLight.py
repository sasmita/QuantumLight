
'''
QuantumLight

SISINTY SASMITA PATRA

FileName: quantumLight.py

This program display different LED patterns depending on the weather classification.

This program calls the getWeatherclassification module from classify.py. Once we get the classification, we communicate that to Arduino to display the led pattern accordingly.
'''

import classify
import serial
import time

#
#sensorData = 1 
sensorData = 0
 
#zipcode = '97201'#psu
zipcode = '60007' #chicago
#zipcode = '97229'#home

if(sensorData):
  print "Getting data from sensor"
else:
  print "Getting data from: ", zipcode

def getPattern(t, w):
  #temperature is cold
  if (t == 0 and w == 0):
    #
    pattern = '0'
  elif(t == 0 and w == 1):
    #
    pattern = '1'
  elif(t == 0 and w == 2):
    pattern = '2'

  #temperature is normal
  elif(t == 1 and w == 0):
    pattern = '3'
  elif(t == 1 and w == 1):
    pattern = '4'
  elif(t == 1 and w == 2):
    pattern = '5'

  #temperature is hot
  elif(t == 2 and w == 0):
    pattern = '6'
  elif(t == 2 and w == 1):
    pattern = '7'
  elif(t == 2 and w == 2):
    pattern = '8'

  return pattern
#end def getPattern


while(1):
  srl = serial.Serial('/dev/tty.usbmodem1411', 9600)
  # Keep tracking current weather data
  tDict = classify.getWeatherClassification(zipcode,sensorData)

  print tDict

  pattern = getPattern(tDict['t'], tDict['ws']);

  print 'pattern: ', pattern
  srl.write(pattern) 

  srl.close()
  time.sleep(5)
