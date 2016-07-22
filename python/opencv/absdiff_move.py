#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import cv2
import numpy as np

camera = cv2.VideoCapture(0)
gray = None
while True:
    ret, frame = camera.read()
    if ret is False:
        print("Camera open failed")
        break
    newgray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    display_img = newgray
    if gray is not None:
        #display_img =cv2.absdiff(newgray, gray)
        """
        diff two picture, movement will be detected
        """
        display_img =np.where(newgray > gray, newgray - gray, gray - newgray)

    gray = newgray
    cv2.imshow('hello', display_img)

    if cv2.waitKey(1) == ord('q'):
        break

camera.release()
