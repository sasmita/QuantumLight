
'''
QuantumLight

SMITA KUNDARGI
SISINTY SASMITA PATRA
JEANNE VICTOR

FileName: classify.py

This program classifies the weather data into different categories by using 
getWeatherInfo module from weather.py
'''

from weather import getWeatherInfo

def getWeatherClassification(zipcode):
   wList = getWeatherInfo(zipcode)
   print '[temp, humidity, Wind {Chill, direction, speed}]'
   print wList

   # classify temperature values
   if wList[0] <= 7:
      tempType = '0'
   elif (wList[0] > 7 and wList[0] <= 30):
      tempType = '1'
   else:
      tempType = '2'
   
   #Classify Humidity Values:
   if wList[1]<= 50:
      humidityType = '0'
   elif (wList[1] > 50 and wList[1] <= 75):
      humidityType = '1'
   else:
      humidityType = '2'

   #Classify wind chill Values:
   if wList[2][0] <= 5:
      windChillType = '0'
   elif (wList[2][0] > 5 and wList[2][0] <= 10):
      windChillType = '1'
   else:
      windChillType = '2'
   
   #Classify Wind Direction Values:
   if wList[2][1] <= 5:
      windDirectionType = '0'
   elif (wList[2][1] > 5 and wList[2][1] <= 10):
      windDirectionType = '1'
   else:
      windDirectionType = '2'
   
   #Classify Wind Speed Values:
   if wList[2][2]<= 5:
      windSpeedType = '0'
   elif (wList[2][2] > 5 and wList[2][2] <=10):
      windSpeedType = '1'
   else:
      windSpeedType = '2'

   #Put all the values in a dictionary    
   typeDict = {'tempType':tempType ,'humidityType':humidityType ,'windChillType':windChillType ,'windDirectionType':windDirectionType ,'windSpeedType':windSpeedType}
   return typeDict

#tDict = getWeatherClassification(zipcode)
#print tDict


      
