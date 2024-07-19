#Created by John Lutz 30mar2024  edited 30mar2024
import shutil
import datetime
import os
from config import *

# Specify the file path to delete
current_dir = os.getcwd()
file_path = current_dir + '\\' + 'gui_use.py'
print(file_path)
my_now = datetime.datetime.now().strftime("%d-%b-%Y_%H:%M:%S")

# Check if the file exists before attempting to delete
if os.path.exists(file_path):
  try:
    os.remove(file_path)  # Attempt to delete the file
    print("gui_use.py File deleted successfully!")
  except OSError as error:
    print("Error deleting file gui_use.py:", error)
else:
  print("gui_use.py File not found.")
# ********
  
# Use shutil.copyfileobj to efficiently copy the file contents
source_file = "gui_base.py"
destination_file = "gui_use.py"
with open(source_file, "rb") as src, open(destination_file, "wb") as dst:
    shutil.copyfileobj(src, dst)

print("File copied successfully!")
# ********


# Open the file in append mode ('a') and use print with the file object
with open(destination_file, "a") as f:
  
    print('\n# What follows was appended to base file on: ' + str(my_now) + '\n', file=f)

       
    for key in pin_out_dict :
        switch_block = 'switch_' + key + '=' + 'ctk.CTkSwitch(master=root, text="' + key + '", ' + 'command=switch_event, ' \
            + '\n    variable=switch_var, ' + 'onvalue="' + str(pin_out_dict[key]) + '", ' + 'offvalue="' + str(pin_out_dict[key]) + '", ' \
            + '\n    fg_color="red", ' + 'progress_color="green"' \
            + '\n)'
        
        print(str(switch_block), file=f)
        print('switch_' + key +'.pack(padx=20, pady=10)\n\n', file=f)

    
    print("root.mainloop()", file=f)


