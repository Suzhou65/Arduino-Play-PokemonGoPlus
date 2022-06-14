# Develop stage
[![arduino](https://github.takahashi65.info/lib_badge/arduino-nano.svg)](https://www.arduino.cc/)
[![arduino](https://github.takahashi65.info/lib_badge/arduino-uno.svg)](https://www.arduino.cc/)
[![no_maintenance](https://github.takahashi65.info/lib_badge/no_maintenance.svg)](https://unmaintained.tech/)

Concept PokemonGo Plus modify and Arduino controller board.
## Contents
- [Develop stage](#develop_stage)
  * [Contents](#contents)
  * [WARNING](#warning)
  * [Files and folders](#files-and-folders)
  * [Circuit diagram and PCB design](#circuit-diagram-and-pcb-design)
  * [Teardown Pokemon Go Plus](#teardown-pokemon-go-plus)
  * [Pirated version Pokemon Go Plus](#pirated-version-pokemon-go-plus)
  * [Modify Pokemon Go Plus](#modify-pokemon-go-plus)
  * [Soldering components on control board](#soldering-components-on-control-board)
  * [Connecting cable for Pokemon Go Plus](#connecting-cable-for-pokemon-go-plus)
  * [Compile Arduino code and upload](#compile-arduino-code-and-upload)
  * [Demo video](#demo-video)
  * [Bill of materials](#bill-of-materials)
  * [Tips](#tips)
  * [Required tools](#required-tools)
  * [Copyright clearance](#copyright-clearance)
  * [Resources and great thanks](#resources-and-great-thanks)

## WARNING
```diff
- Concept only, not recommended for new builders anymore.
- Modify PGP could be damage, or lead to unrecoverable damage.
```
```diff
+ Please make sure you have required tools and sufficient knowledge about electronics
```

## Files and folders
* ```arduino_code```
  - ```concept_reference.ino``` Clean copy from ```Johan von Konow```
* ```bill_of_materials```
  - ```concept_bom.pdf``` About PCB design, and bill of materials
* ```action_of_pokemon_go_plus.md``` Explane the mechanism of Pokemon Go Plus
* ```concept_gerber_arduino_nano_v1.zip``` Concept PCB design for Arduino Nano
* ```concept_gerber_arduino_nano_v2.zip``` Enhanced concept PCB design
* ```concept_gerber_arduino_uno_v1.zip``` Concept PCB for Arduino Uno

## Circuit diagram and PCB design
* Circuit diagram
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_circuit.webp)
* Concept PCB design for Arduino Nano
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_pcb_front.webp)
* Enhanced version  
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_enhanced_pcb_front.webp)
* For Arduino Uno
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_uno_pcb_front.webp)

## Teardown Pokemon Go Plus
* Remove CR2032 battery from Pokemon Go Plus
![](https://github.takahashi65.info/lib_img/github_pokemon_battery.webp)
* Using Y00 triwing tripoint screwdriver to
![](https://github.takahashi65.info/lib_img/github_pokemon_teardwon.webp)
* Desoldering vibration motor
![](https://github.takahashi65.info/lib_img/github_pokemon_vob.webp)
+ Figure out pinout.
![](https://github.takahashi65.info/lib_img/github_pokemon_led_pin.webp)

## Pirated version Pokemon Go Plus
* Unfortunately, after teardown more Pokemon Go Plus, I thought that I bought pirated version.
![](https://github.takahashi65.info/lib_img/github_pokemon_compare.webp)
* Fortunately, the pirated version pinout is same as genuine version.
![](https://github.takahashi65.info/lib_img/github_pokemon_led_pin_origin.webp)

## Modify Pokemon Go Plus
* Soldering 30AWG wire wrapping wire, it should stretch seven connect wires, then fixed the wire.
![](https://github.takahashi65.info/lib_img/github_pokemon_wire.webp)
* Cutting Pokemon Go Plus case, for setting pin connector.
![](https://github.takahashi65.info/lib_img/github_pokemon_case_cut.webp)
* Connecting Circuit from Pokemon Go Plus to pin connector.
![](https://github.takahashi65.info/lib_img/github_pokemon_pinconnect.webp)
* Pinout and circuit rule as follows.
![](https://github.takahashi65.info/lib_img/github_pokemon_pinout.webp)
* Fixed the pin connector, then put everything back, without vibration motor.
![](https://github.takahashi65.info/lib_img/github_pokemon_reassembly.webp)

## Soldering components on control board
Download Gerber file, Upload to PCB prototype manufacturer, or PCB fabrication manufacturer.
* Get PCB from PCB fabrication manufacturer, or PCB prototype manufacturer.
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_pcb.webp)
* Soldering electronic components, including pin header, capacitor, slide switch and micro USB breakout board.
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_assembly.webp)
* Checking Nokia 5110 LCD Board pinout, make sure it can directly connect to board or need wire.
![](https://github.takahashi65.info/lib_img/github_nokia_5110.webp)
* If the backlight circuit already has resistors, ```Resistors R9_D9``` don't need to install, soldering as jumper.
* Soldering Nokia 5110 LCD Board, or using pin header and pin connector
* Soldering Arduino Nano, or you can soldering pin socket, so you can remove it easily.
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_complete.webp)

## Connecting cable for Pokemon Go Plus
* Making Pokemon Go Plus connect cable.
![](https://github.takahashi65.info/lib_img/github_arduinoplaypokemon_wire.webp)
* Pinout and circuit rule as follows.
![](https://github.takahashi65.info/lib_img/github_pokemon_connect_wire.webp)

## Compile Arduino code and upload
* Plug Arduino USB cable, compile and upload program.
* Power on the Board, Connect Pokemon Go Plus.
* Pray that everything goes well
![](https://github.takahashi65.info/lib_img/github_pokemon_running.webp)
* Now, enjoy  
![](https://github.takahashi65.info/lib_img/github_pokemon_complete.webp)

## Demo video
[![Actual Operation demo on YouTube](https://github.takahashi65.info/lib_img/github_pokemon_youtube.webp)](https://youtu.be/61VY3UylwxM)

## Bill of materials
* ```bill_of_materials/concept_bom.md```

## Tips
* Using ```ML2032``` rechargeable coin battery replace ```CR2032```, Then it can be charge by Arduino.
* Make a simple board including battery, and DIP Switch that can short-circuit VOB_GND and Switch, ```Auto Click !```.

## Required tools
* Y00 triwing tripoint screwdriver ( teardown Pokemon Go Plus )
* Pin clamping pliers
* Soldering iron
* Liquid soldering flux
* 30AWG wire wrapping wire ( silver plated wire ), or enamelled wire
* 24AWG stranded conductors wire
* Super glue or UV light glue
* Hot glue gun

## Copyright clearance
Arduino code was copy from ```Johan von Konow``` wbsite.

## Resources and great thanks
Concept arduino code and circuit design reference from Johan von Konow  
[PokeBot – Catch Pokémon’s in your sleep (and at work) ](https://vonkonow.com/wordpress/2017/08/pokebot-catch-pokemons-in-your-sleep-and-at-work/) **Written by Johan von Konow**
