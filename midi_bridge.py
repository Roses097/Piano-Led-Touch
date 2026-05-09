###                                                                     ###
###         Created : 05/08/26                  Author : Rayane         ###
###                                                                     ###
import mido
import serial

import serial.tools.list_ports

i = 0
port_mcu = serial.tools.list_ports.comports()

print("Choose your microcontroller device : ")
for p in port_mcu :
    i += 1
    print( i ,p.device, p.description ) 

while True:
    try :
        choice = int(input("Choice : "))
        mcu_device = port_mcu[choice-1].device

        break

    except ValueError:
        print("Please enter a number")

    except IndexError:
        print("Invalid choice")




i = 0
port_midi = mido.get_input_names()

print("Choose your MIDI device : ")
for p in port_midi :
    i += 1
    print(i ,p)


while True:
    try :
        choice = int(input("Choice : "))
        midi_device = port_midi[choice-1]
        break

    except ValueError:
        print("Please enter a number")

    except IndexError:
        print("Invalid choice")




mcu_serial = serial.Serial(mcu_device, 115200)
print("Listening... press Ctrl+C to stop")

with mido.open_input(midi_device) as port:
    for msg in port:
        if msg.type == 'note_on':
            mcu_serial.write(bytes([0x90, msg.note, msg.velocity]))
            print(f"Note ON: {msg.note}")
        elif msg.type == 'note_off':
            mcu_serial.write(bytes([0x80, msg.note, 0]))
            print(f"Note OFF: {msg.note}")



