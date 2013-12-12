
'''
QuantumLight

SMITA KUNDARGI
SISINTY SASMITA PATRA
JEANNE VICTOR

FileName: classify.py

This program classifies the weather data into different categories by using getWeatherInfo module from weather.py
'''

from weather import getWeatherInfo
from sensor import getSensorData

def getWeatherClassification(zipcode, sensorData):

   if(sensorData):  
     wList = getSensorData()
   else: 
     wList = getWeatherInfo(zipcode)

   print '[temp, humidity, wind]'
   print wList

   # classify temperature values
   if wList[0] <= 10:
      tempType = 0
   elif (wList[0] > 10 and wList[0] <= 20):
      tempType = 1
   else:
      tempType = 2
   
   #Classify Humidity Values:
   if wList[1]<= 50:
      humidityType = 0
   elif (wList[1] > 50 and wList[1] <= 75):
      humidityType = 1
   else:
      humidityType = 2

   #Classify Wind Speed Values:
   if wList[2]<= 5:
      windType = 0
   elif (wList[2] > 5 and wList[2] <=10):
      windType = 1
   else:
      windType = 2

   typeDict = {'t':tempType ,'h':humidityType ,'ws':windType}
   return typeDict

#tDict = getWeatherClassification('97229', 1)
#print tDict
      
