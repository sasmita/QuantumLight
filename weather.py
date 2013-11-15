import pywapi
import string

zipcode = '97006'

"""
yahooResult = pywapi.get_weather_from_yahoo(zipcode)
weatherResult = pywapi.get_weather_from_weather_com(zipcode)

"""
""" Funtion that retrieves weather information for the given zipcode;
    Currently, it returns temperature, humidity and wind information in a list"""
def getWeatherInfo(zipcode):
    weatherList = []
    windList = []
    yahooResult = pywapi.get_weather_from_yahoo(zipcode)
    #WindList[Chill, Direction, Speed]
    windList = [int(yahooResult['wind']['chill']), int(yahooResult['wind']['direction']), int(yahooResult['wind']['speed'])] 
    #weatherList[temperature, Humidity, windList];
    weatherList = [int(yahooResult['condition']['temp']), int(yahooResult['atmosphere']['humidity']), windList ]
    #print weatherList
    return weatherList
    
wList = []
wList = getWeatherInfo('97006')
print '[temp, humidity, Wind {Chill, direction, speed}]'
print wList
