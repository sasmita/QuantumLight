QuantumLight
============

Quantifying the input data and displaying various LED patterns based on quantification.

Our focus: Quantifying weather data

Load qL\qL.ino sketch.

Update the sensorData (to specify if you want to collect the data from sensor or internet). If internet, specify the zipcode.

Run quantumLight.py 

quantumLight.py connects to arduino via serial port. 

Setup instructions:


1. Clone or download the Zip. Load qL.ino arduino sketch. Run quantumLight.py.

2. Install weather API
   a. Download Weather API (pywapi) library from: 
      http://python-weather-api.googlecode.com/files/pywapi-0.3.6.tar.gz
   b. Untar it and install it using:
      $ python setup.py build
      $ python setup.py install

3. Install PySerial

4. Install OneWire Arduino library

5. Install Adafruit-Neopixel library 
