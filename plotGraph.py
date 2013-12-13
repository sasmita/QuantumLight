'''
QuantumLight

JEANNE VICTOR
SISINTY SASMITA PATRA
SMITA KUNDARGI

FileName: plotGraph.py

This program retrieves the collected data from csv file and plots the
graph using pygal.

'''

import csv
import pygal
import string
from collections import defaultdict

myTemp = []
myHumidity = []
myWspeed = []
myLoc = []
myDate = []

#Oregon_Dec6info.csv is the csv file that contains weather data collected
#for Dec 6th 2013

ifile = open('Oregon_Dec6info.csv', "rt")
reader = csv.reader(ifile)

"""
Function for plotting graph: Temperature Vs Time
"""
def createTempVsTime():   
    bar_chart1 = pygal.Bar(x_label_rotation=30, rounded_bars=20)
    bar_chart1.title = "Temperature Vs Time"    
    bar_chart1.x_labels = (myDate)
    bar_chart1.x_labels_major = (myDate)
    bar_chart1.add('#Temperature',myTemp)    
    bar_chart1.render_to_file('TempTimeChart.svg')

"""
Function for plotting graph: Winspeed Vs Time
"""
def createwSpeedVsTime():   
    bar_chart1 = pygal.Bar(x_label_rotation=30, rounded_bars=20)
    bar_chart1.title = "WindSpeed Vs Time"    
    bar_chart1.x_labels = (myDate)
    bar_chart1.x_labels_major = (myDate)
    bar_chart1.add('#WindSpeed',myWspeed)    
    bar_chart1.render_to_file('WindSpeedTimeChart.svg')
    

"""
Function for plotting graph: Multiple Data Temp, Winspeed Vs Time
"""
def createTempwSpeedVsTime():   
    bar_chart1 = pygal.Bar(x_label_rotation=90)
    bar_chart1.title = "Temp WindSpeed Vs Time"    
    bar_chart1.x_labels = (myDate)
    bar_chart1.x_labels_major = (myDate)
    bar_chart1.add('#Temperature',myTemp)
    bar_chart1.add('#WindSpeed',myWspeed)    
    bar_chart1.render_to_file('TempWindSpeedTimeChart.svg')


for i, row in enumerate(reader):
    if not i or not row:
        continue
    
    loc, date, temp, humidity, wChill, wDirection, wSpeed = row
    myTemp.append(float(temp))
    
    myHumidity.append(int(humidity))
    myWspeed.append(float(wSpeed))
    
    myLoc.append(loc)
    myDate.append(date)


createTempVsTime()
createwSpeedVsTime()
createTempwSpeedVsTime()
