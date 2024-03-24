# arduino nano on COM 3 - system dependent, implement autoscan for this ?
# pip3 install <customtkinter, pyserial>  # not an actual command
# python -m serial.tools.list_ports

import customtkinter as ctk
import serial
from config import *

arduino = serial.Serial(com_port, baud)

root = ctk.CTk()  # create CTk window
root.geometry("400x240")
root.title(device)
ctk.set_appearance_mode("System")  # Modes: system (default), light, dark
ctk.set_default_color_theme("blue")  # Themes: blue (default), dark-blue, green


#def button_function(): # do the thing
#    print("button pressed")

#button = ctk.CTkButton(master=root, text="DIO_2", command=button_function)
#button.place(relx=0.5, rely=0.5, anchor=ctk.CENTER)


switch_var = ctk.StringVar(value="0")

def switch_event():
    print("switch toggled, current value:", switch_var.get()) # str
    arduino.write(switch_var.get().encode())


switch_1 = ctk.CTkSwitch(master=root, text="DIO_13\nLED_builtin", command=switch_event,
                        variable=switch_var, onvalue="13", offvalue="13")
switch_1.pack(padx=20, pady=10)


switch_2 = ctk.CTkSwitch(master=root, text="DIO_14\nLED_builtin", command=switch_event,
                        variable=switch_var, onvalue="14", offvalue="14")
switch_2.pack(padx=20, pady=10)


root.mainloop()