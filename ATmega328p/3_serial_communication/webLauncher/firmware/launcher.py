##Simple demo of launching the website from AVR


SITE = "http://www.yasunaga.work"

SERIAL_PORT = "/dev/cu.usbserial-AD0JIMRU"
BAUD_RATE = 9600

import serial 
import webbrowser

sp = serial.Serial(SERIAL_PORT, BAUD_RATE , timeout = 5)
sp.flush()

while(1):
	responce = sp.read(1)
	if responce == "O":
		print "Got OK byte.  Waiting for button press"
	elif responce == "X":
		print "WEBSITE!!"
		webbrowser.open(SITE)

	else:
		print "Got nothing.  Still waiting"