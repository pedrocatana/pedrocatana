import serial
import webbrowser
import os
import pyautogui

ser = serial.Serial('COM7', 9600)
while True:
    command = ser.readline().decode()
    os.system(command)

                                        