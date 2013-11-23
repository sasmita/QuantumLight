/*

QuantumLight

SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

FileName: weather.py

This program gets weather data from Internet 
such as temperature, humidity, wind etc.

*/

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

    windList = [float(yahooResult['wind']['chill']), float(yahooResult['wind']['direction']), float(yahooResult['wind']['speed'])] 
    #weatherList[temperature, Humidity, windList];
    weatherList = [float(yahooResult['condition']['temp']), float(yahooResult['atmosphere']['humidity']), windList ]
    #print weatherList
    return weatherList
    
wList = []
wList = getWeatherInfo(zipcode)
print '[temp, humidity, Wind {Chill, direction, speed}]'
print wList

#wDict = {'temp':wList[0] , 'humidity':wList[1], 'w_chill':wList[2][0], 'w_direction':wList[2][1], 'w_speed':wList[2][2]}
#print wDict



