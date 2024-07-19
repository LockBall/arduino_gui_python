# arduino nano on COM 3 - system dependent, implement autoscan for this ?
# pip3 install <customtkinter, pyserial>  # not an actual command
# python -m serial.tools.list_ports
# https://www.youtube.com/watch?v=a0MVOloNLB4 

import customtkinter as ctk
import serial
from config import *

try:
    arduino = serial.Serial(com_port, baud)
except Exception as exc:
    message = "Error creating arduino serial connection object."
    print(message)

root = ctk.CTk()  # create CTk window
root.geometry("300x150")
root.title(device_name)
ctk.set_appearance_mode("System")  # Modes: system (default), light, dark
ctk.set_default_color_theme("blue")  # Themes: blue (default), dark-blue, green
switch_var = ctk.StringVar(value="0")


def switch_event():
    print("switch toggled, current value:", switch_var.get()) # str
    arduino.write(switch_var.get().encode())

# ****************************************************************