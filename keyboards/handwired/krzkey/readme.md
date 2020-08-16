# krzkey handwired

Custom handwired two-key keyboard.

Keyboard Maintainer: [spydon](https://github.com/spydon)  
Hardware Supported: Custom handwired two-key keyboard  
Hardware Availability:

Columns must be connected to pin C6 and C7, and the row to B6. 

Compile example for this keyboard (after setting up your build environment):

    qmk compile -kb handwired/krzkey -km default

And to flash:

    sudo qmk flash -kb handwired/krzkey -km default
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
