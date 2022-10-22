# Arduino Play Pokemon Go Plus
[![arduino](https://github.takahashi65.info/lib_badge/arduino-nano.svg)](https://www.arduino.cc/)
[![under_development](https://github.takahashi65.info/lib_badge/under_development.svg)](https://github.com/Suzhou65/Arduino-Play-PokemonGoPlus)
[![Size](https://img.shields.io/github/repo-size/Suzhou65/Arduino-Play-PokemonGoPlus.svg)](https://shields.io/category/size)

## Pokemon Go Plus Enhanced Solution
* Spinning Pokestops and catching Pokémon without manually !
  - You can let Arduino clicking Pokemon Go Plus while you were working.
  - Let Pokémon Go Plus become Pokéball Plus, or even batter.

## Compare with reference design and arduino code
* Design breakout board for Pokemon Go Plus
* Controller board enhanced
  - PCB miniaturization
  - Using ```Arduino Nano``` instead of ```Arduino Uno```
  - Replace ```Nokia 5110 LCD module``` with ```SSD1306 OLED display```
  - Adding ```manual press key```
  - Adding Tx/Rx pinout for future function
* Arduino code improvement
  - Adding random delay to prevent Niantic Anti-BOT system detect

## Contents
* ```arduino_code``` Arduino code
  - ```concept_reference.ino``` Clean copy from ```Johan von Konow```
  - ```concept_v1.ino``` 2022_06_07, concept
* ```bill_of_materials``` About PCB design, and bill of materials
  - ```arduino_2_pokemon_bom.md``` Bill of materials, for controller board
  - ```concept_bom.md``` Bill of materials, for concept board
  - ```pokemon_go_plus_bb_bom.md``` Bill of materials, for breakout board
* ```action_of_pokemon_go_plus.md``` Explane the mechanism of Pokemon Go Plus
* ```concept_develop.md``` Develop stage, take reference from Johan von Konow
* ```concept_gerber_arduino_nano_v1.zip``` Concept PCB design, For Arduino Nano
* ```concept_gerber_arduino_nano_v2.zip``` Enhanced concept PCB design
* ```concept_gerber_arduino_uno_v1.zip``` Concept PCB design, For Arduino Uno
* ```gerber_arduino_2_pokemon.zip``` Arduino Nano based controller board
* ```gerber_pokemongoplus_board.zip``` Pokemon Go Plus breakout board
* ```modify_pokemon_go_plus.md``` How to modify Pokemon Go Plus
* ```README.md```

## Resources and great thanks
Concept arduino code and circuit design reference from Johan von Konow  
[PokeBot – Catch Pokémon’s in your sleep (and at work) ](https://vonkonow.com/wordpress/pokebot-catch-pokemons-in-your-sleep-and-at-work/)
