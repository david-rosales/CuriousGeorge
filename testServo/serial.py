import serial
ser = serial.Serial('/dev/cu.usbmodem1411',9600)

while True:
    var = int(input())
    letter = chr(max(ord('@'),ord('@')+var))
    b = bytes(letter, 'utf-8')
    ser.write(b'%s' %b)
