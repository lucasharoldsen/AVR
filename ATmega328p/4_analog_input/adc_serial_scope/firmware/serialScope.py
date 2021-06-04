

import serial 

def readValue(serialPort):
	return(ord(serialPort.read(1)))

def plotValue(value):
	leadingSpaces = " " * (value*(SCREEN_WIDTH-3) / 255)
	print "%s%3i" % (leadingSpaces, value)

def cheapScope(serialPort):
	while(1):
		newValue = readValue(serialPort)
		plotValue(newValue)


if __name__ == "__main__":

	PORT = '/dev/cu.usbserial-AD0JIMRU'
	BAUD_RATE = 9600
	TIMEOUT = None
	SCREEN_WIDTH = 80


	import sys
	if len(sys.argv) == 3:
		port = sys.argv[1]
		baudrate = int(sys.argv[2])

	else:
		print ("Optional arguments port, baudrate set to defaults")
		port, baudrate = (PORT, BAUD_RATE)

	serialPort = serial.Serial(port, baudrate, timeout=TIMEOUT)
	serialPort.flush()
	cheapScope(serialPort)