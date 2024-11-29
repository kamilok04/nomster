# nomster
### Please don't run this on others' computers without their prior approval, that's mean :(

A silly Win32 app that swaps your keyboard's N and M keys. That's it.

## How do I stop it?
This thing is basic and doesn't even have a window, so you'll need to kill the process.

*for experienced ppl*:

- run the command `taskkill /f /im nomster_xAA_X.Y.Z.exe` (`AA` is your bitness `X.Y.Z` is the version number) via any kind of command prompt. Your keys are probably swapped though.

*for everyone else*:
- use a Task Manager (Start Menu → Task Manager) (or <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>Esc</kbd> if feeling fancy)
- navigate to `Details` tab, you should see a big ol' list of processes. Find one named

  **nomster_`some random numbers`.exe** 

  and click the `End Task` button, should be in the lower right corner.
- confirm whatever pops up, you're a professional IT now.

## How do I start it?
Run the `nomster.exe` thingy - make sure you get the correct version (probably `x64`).

## How do I build it?
Use whatever you want, as long as it compiles C, is C89-compliant or better and can make Windows binaries.

`gcc -c nomster.c -o nomster.exe -mwindows` is good enough. (the `-mwindows` makes it so that GCC doesn't wrap the program around a command prompt, we don't need one)

## Issues
Keys like `ń` or `ñ` are still mapped to the correct keys. This app took like 30 minutes to make, whaddya expect?

--- 
<p align="center">
  <img width="480" height="480" src="https://github.com/user-attachments/assets/31411fc3-179b-4326-9f5d-d57ebac27c4e"><br>
<i>Inspired by this post</i>
</p>
