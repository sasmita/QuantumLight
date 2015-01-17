'''
QuantumLight

SISINTY SASMITA PATRA

FileName: weather.py

This program gets weather data from Internet using pywapi (weather api).

Examples:
yahooResult = pywapi.get_weather_from_yahoo(zipcode)
weatherResult = pywapi.get_weather_from_weather_com(zipcode)

'''

import pywapi
import string
import csv

zipcode = '97006'
zipcodeAlas = '99501'
zipcodeLV = '89110'

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

"""
Funtion that retrieves weather information and appends the data to the CSV file;

Params:
zipcode - zipcode of the city for which weather info has to be retrieved
filename - the csv filename to which the data has to be appended
"""

def getWeatherInfoInCSV(zipcode, filename):
    wList = []
    result = pywapi.get_weather_from_yahoo(zipcode)
    wList = [result['condition']['title'],
                   result['condition']['date'],
                   int(result['condition']['temp']),
                   float(result['atmosphere']['humidity']),
                   int(result['wind']['chill']),
                   int(result['wind']['direction']),
                   float(result['wind']['speed']) ]
    fd = open('%s.csv' % filename,'ab')
    writer = csv.writer(fd)
    writer.writerow((wList)) 
    fd.close()
    return wList



getWeatherInfoInCSV(zipcode,"SampleDataForOR")

