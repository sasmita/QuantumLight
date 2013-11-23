from weather import getWeatherInfo

zipcode = '85003'

def getWeatherClassification(zipcode):
   wList = getWeatherInfo(zipcode)
  # classify temperature values
   print 'Temperature'
   if wList[0] <= 7:
      tempType = '0'
      print tempType
   elif (wList[0] > 7 and wList[0] <= 30):
      tempType = '1'
      print tempType
   else:
      tempType = '2'
      print tempType
   
   #Classify Humidity Values:
   print 'Humidity'
   if wList[1]<= 50:
      humidityType = '0'
      print humidityType
   elif (wList[1] > 50 and wList[1] <= 75):
      humidityType = '1'
      print humidityType
   else:
      humidityType = '2'
      print humidityType

   #Classify wind chill Values:
   print 'wind chill'
   if wList[2][0] <= 5:
      windChillType = '0'
      print windChillType
   elif (wList[2][0] > 5 and wList[2][0] <= 10):
      windChillType = '1'
      print windChillType
   else:
      windChillType = '2'
      print windChillType
   
   #Classify Wind Direction Values:
   print 'Wind Direction'
   if wList[2][1] <= 5:
      windDirectionType = '0'
      print windDirectionType
   elif (wList[2][1] > 5 and wList[2][1] <= 10):
      windDirectionType = '1'
      print windDirectionType
   else:
      windDirectionType = '2'
      print windDirectionType
   
   #Classify Wind Speed Values:
   print 'Wind Speed'
   if wList[2][2]<= 5:
      windSpeedType = '0'
      print windSpeedType
   elif (wList[2][2] > 5 and wList[2][2] <=10):
      windSpeedType = '1'
      print windSpeedType
   else:
      windSpeedType = '2'
      print windSpeedType

   #Put all the values in a dictionary    
   typeDict = {'tempType':tempType ,'humidityType':humidityType ,'windChillType':windChillType ,'windDirectionType':windDirectionType ,'windSpeedType':windSpeedType}
   return typeDict

#tDict = getWeatherClassification(zipcode)
#print tDict


      
