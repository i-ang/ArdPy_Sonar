import serial

ser = serial.Serial(port='com3',baudrate=9600,bytesize=serial.EIGHTBITS,parity=serial.PARITY_NONE,timeout=2)

try:
	ser.isOpen()
	print("Serial port is open")
except:
	print("error")
	exit()

if(ser.isOpen()):
	try:
		while(1):
			x = int(ser.read())
			print(x)
	except Exception:
		print("error")
else:
	print("Cannot open serial port")
