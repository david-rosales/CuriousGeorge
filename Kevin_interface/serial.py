import serial
#this port need to be modified on the actual machine
ser = serial.Serial('/dev/cu.usbmodem1411',9600)

def sendCommand(command):
    ser.write(command.encode())

while True:
    a = input()
    sendCommand(a)
    #if you want to send a number
    # var = int(input())
    # letter = chr(max(ord('@'),ord('@')+var))
    # b = bytes(strToSend, 'utf-8')
    # ser.write(b'%s' %b)
    # ser.write(strToSend.encode())