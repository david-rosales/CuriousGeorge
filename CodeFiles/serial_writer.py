import serial
#this port need to be modified on the actual machine
#ser = serial.Serial('/dev/ttyACM0',9600)

def sendCommand(command):
    print("sending", command)
    #ser.write((command+"\n").encode())