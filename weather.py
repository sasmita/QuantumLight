
'''
QuantumLight

JEANNE VICTOR
SISINTY SASMITA PATRA
SMITA KUNDARGI

FileName: weather.py

This program gets weather data from Internet using pywapi (weather api).

Examples:
yahooResult = pywapi.get_weather_from_yahoo(zipcode)
weatherResult = pywapi.get_weather_from_weather_com(zipcode)

'''

import pywapi
import string

"""
Funtion that retrieves weather information for the given zipcode;
    Currently, it returns temperature, humidity and wind information in a list
"""

def getWeatherInfo(zipcode):
    weatherList = []
    result = pywapi.get_weather_from_yahoo(zipcode)
    weatherList = [float(result['condition']['temp']), 
		   float(result['atmosphere']['humidity']), 
                   float(result['wind']['speed'])
                  ]

    return weatherList
    
