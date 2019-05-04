import serial

# This was used to test writing data to the Arduino 
# from Python

arduinoData = serial.Serial('com3', 9600)

def led_on():
	arduinoData.write(b'1') 

def led_off():
	arduinoData.write(b'0')
	
while True:

	x = input("what")

	if (x == '1'):
		# arduinoData.write(b'1')
		# print(x)
		led_on()
		
	elif(x == '0'):
		# arduinoData.write(b'0')
		# print(x)
		led_off()