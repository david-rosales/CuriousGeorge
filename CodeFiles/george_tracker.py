import numpy as np
import cv2
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import serial
from find_the_ball import track_ball

greenLower = (25, 66, 30)
greenUpper = (84, 255, 255)

ser = None

def setup():
  #connect()
  #communicate()
 
 main()

def findObject(frame, lastObjectLocation):
  #convert frame from BGR->HSV
  hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
  
  #create green mask
  mask = cv2.inRange(hsv, greenLower, greenUpper)
  mask = cv2.erode(mask, None, iterations=2)
  mask = cv2.dilate(mask, None, iterations=2)

  #find contours
  contours = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]

  #if a contour is found
  if len(contours) > 0:
    if(lastObjectLocation == (-1, -1)):
      contour = max(contours, key=cv2.contourArea)
    else:
      #contour = max(contours, key=cv2.contourArea)
      contour = max(contours, key=lambda x: (3*cv2.contourArea(x) - 10*abs(np.linalg.norm(np.array(lastObjectLocation) - np.array(cv2.minEnclosingCircle(x)[0]) ))**2 ))
    ((x, y), radius) = cv2.minEnclosingCircle(contour)
    print("RADIUS", radius)	

    #if the contour is big enough
    if radius > 10:
      # draw the circle and centroid on the frame,
      cv2.circle(frame, (int(x), int(y)), int(radius), (0, 255, 255), 2)
      return ((x, y), radius)
  return ((-1, -1), -1)

def main():
  cap = cv2.VideoCapture(1)
  height = 480
  width = 640
  centerY = 240
  centerX = 320
  lastObjectLocation = (-1, -1)
  while(cap.isOpened()):
    #frame starts in BGR
    ret, frame = cap.read()
    if ret:
      ((x, y), radius) = findObject(frame, lastObjectLocation)
      distance = 100.0/radius
      lastObjectLocation = (x, y)
      print(track_ball(distance, radius, x, y))
      cv2.imshow('feed', frame)
      if cv2.waitKey(1) == 27:
        break

  cap.release()
  cv2.destroyAllWindows()

def connect():
  ser = serial.Serial('/dev/cu.usbmodem1421', 9600)

def communicate():
  pass

setup()

