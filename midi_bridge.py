###                                                                     ###
###         Created : 05/08/26                  Author : Rayane         ###
###                                                                     ###
import mido
import serial

import serial.tools.list_ports

Note_names = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']


def note_name(note):

    octave = (note // 12) - 1 #get octave note
    name = Note_names[note % 12] #get note name
    return f"{name}{octave}"



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





i = 0
port_mcu = serial.tools.list_ports.comports()

print("Choose your microcontroller device : ")

for p in port_mcu :
    i += 1
    print( i ,p.device, p.description ) 


while True:
    try:

        choice = int(input("Choice : "))
        mcu_device = port_mcu[choice-1].device

        try:
            mcu_serial = serial.Serial(mcu_device, 115200)
            print("Listening... press Ctrl+C to stop")

            break

        except serial.SerialException as error:
            print(f"Could not open port: {error}")

    except ValueError:
        print("Please enter a number")

    except IndexError:
        print("Invalid choice")




with mido.open_input(midi_device) as port:
    for msg in port:
        if msg.type == 'note_on':
            mcu_serial.write(bytes([0x90, msg.note, msg.velocity]))
            print(f"Note ON: {note_name(msg.note)} {msg.note}")
        elif msg.type == 'note_off':
            mcu_serial.write(bytes([0x80, msg.note, 0]))
            print(f"Note OFF: {note_name(msg.note)} {msg.note}")



