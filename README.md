![1](https://user-images.githubusercontent.com/106225286/178461232-8d297263-611c-4818-afe6-dddb137c4bf9.png)

Raspberry Pi Pico Piano – Part 1 (88-key piano with only 14 buttons)

Most musical instruments are portable, but have you ever thought about taking your piano to a picnic or even camping? You might say it's impossible. There's no way to get that giant instrument outside, even if it's just for class. But I suppose you might be wrong this time, and I made a portable piano with complete 88-keys piano by using a Raspberry Pi Pico 

There are many foldable digital pianos in the market, and some can fold one time, some can fold two times, but they are still cumbersome. In my design, I will only place one octave(12-buttons) on the circuit and use two buttons to adjust the octave.

I tried to use DesignSpark PCB to draw the schematic diagram and translate it to PCB, it worked very well. But there are some components that the DesignSpark library doesn't have, then I went to SnapEDA to download and it was easy to import into DesignSpark PCB.

PCB Design
![2](https://user-images.githubusercontent.com/106225286/178461240-fdebca2a-bb3f-4c2f-b267-b503d07583e4.png)
![3](https://user-images.githubusercontent.com/106225286/178461242-57e9bcb4-deb0-4748-a59c-1ea99d01d18b.png)
![4](https://user-images.githubusercontent.com/106225286/178461247-ae4a035d-efdb-4ae7-a5a6-dc486e913b11.png)

Raspberry Pi Pico Piano – Part 2 (Play two notes simultaneously)

In this sharing, I will only focus on how to make a piano that can play two notes simultaneously in one octave. If you want to know how to make it on an 88-key piano, you can go back to “Raspberry Pi Pico Piano”, which simply shares how to make an 88-key piano. In order for the piano to play two notes at the same time, this is demonstrated in the video below, on how to make the buzzer have two sounds.

The circuit and the connection you can also refer to "Raspberry Pi Pico Piano – Part 1".

The difference with “Raspberry Pi Pico Piano – Part 1”, is the tones.h library isn’t defining the notes in frequency. I define notes in units of time. The reason why I defined in units of time I will explain later. To covert the notes in units of frequency to time is simple. Take an example on Notes “A4”, f=1/t, 440=1/t, t=2273us. Then, we can first convert all notes into units of time.
