This program is designed for one of the data transmission options that I am most likely to choose later for the "SunFlower" project. DC voltages will be transmitted via a "Conductive Slip Ring," while signals—probably not through brushes this time :D. I also considered Bluetooth, WiFi, and GSM modules that could transmit signals from the "Spinning Head" to the stationary column part, but that would be a rather poor choice for several reasons, the main ones being reliability, durability, and signal transmission quality (especially when data would need to be sent through a grounded, closed ~7–12 mm thick steel structure).

2025-01-21 Update: A YouTube video demonstrated a setup where a photodiode and LED are directly aligned with each other. Today, I tried making a simple rotating optical coupler using whatever I had on hand. New wiring circuit (Firmware changes: the USART baud rate was changed from 0.25 Mbps to 0.5 Mbps.):
![New circuit](https://github.com/user-attachments/assets/1bfd5152-9d49-45c0-9684-0f8d50351033)

Testing breadboard on Video:
![original breadboard](https://github.com/user-attachments/assets/b2b4c17c-9368-484e-af6b-5a8b4e6a4118)

Updated breadboard:
![updated breadboard](https://github.com/user-attachments/assets/e3b95407-a2cf-466c-98c8-f7849bb07b1b)

Also rottating optocoupler and MT6701 case:
![optical coupler and mt6701 case ](https://github.com/user-attachments/assets/52325bdb-6c96-49b2-bcec-4038b9f224db)
![dissasembled optocoupler](https://github.com/user-attachments/assets/faaab7e1-05e1-421a-8fdb-034708ccfe64)
![ir led illumination](https://github.com/user-attachments/assets/f466614a-7d3a-49eb-8825-5ebd937e4900)

Transsmit speed confirmation:
![500kbps reading](https://github.com/user-attachments/assets/a5f82a0f-8984-47af-8faf-e9b4ea007466)

Signal delay is about ~2.3us (yellow signal at AVR64DD32 RX pin, and blue signal on TX LED pin):
![delay](https://github.com/user-attachments/assets/a62518a8-2c48-40ba-a879-a0749a46dc91)


It seems that this rotating optocoupler works perfectly for my requirements, so I will focus on improving it further. I might even use an optical fiber to replace the current 1.3-meter (4x 65 cm) wires, which would allow for even higher speeds.

Grabcad models: 
Optocoupler:
https://grabcad.com/library/dye-rotating-optocoupler-1
MT6701 Case:
https://grabcad.com/library/mt6701-shells-or-case-or-frame-d-1
