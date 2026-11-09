Blob Wars: Metal Blob Solid for AmigaOS 3.x
===========================================

Blob Wars: Metal Blob Solid 2.00 (Parallel Realities; upstream
https://github.com/perpendicular-dimensions/blobwars, commit
1622ca7486227c8993dab2657837de51f09bad94; code and graphics GPL 2 or
later, music and sounds under the free licences doc/readme lists), the
2D platform shooter, for AmigaOS 3.x on a 68040 or 68060 with an FPU and
an RTG screen, on OpenGPU's SDL 2.

Branch team2/blobwars-amiga.

Status: lab-tested (Instance-45, an emulated 68040 with an FPU, RTG,
6 November 2026): the GPL notice, the intro story, the title, a new game
(slot, difficulty), the hub map, the Grasslands stage (Bob walking and
shooting, the HUD, the music credit), the pause menu and "Quit to Title
Screen", and closing the window back to the Shell. Pictures:
docs/screenshots/.

Known from that run: on the title menu the cursor keys did not move the
highlight in the lab (they did in the pause menu, and Ctrl and the mouse
work on both); to be checked with a real keyboard.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- OpenGPU 0.6 or later: opengpu.library and LIBS:OpenGPU/SDL2.module,
  SDL2_image.module, SDL2_mixer.module, SDL2_ttf.module and
  SDL2_net.module (installed by OpenUp).
- About 85 MB of disk (the music is 60 MB of Ogg Vorbis).


How to play
-----------

Open the BlobWars drawer and double-click BlobWars. The settings, the
saved games and the replays are kept in the drawer's user/ (made the first
time). The manual is doc/manual.html.



Standard keys
-------------

Every AmiCradle game has the same keys on Right Amiga (GFOpenUp's
SDL2.module, after 0.8.26):

- Right Amiga + F: window or full screen, remembered for next time
- Right Amiga + P: pause (Right Amiga + P again goes on)
- Right Amiga + Q: quit
- Right Amiga + M: free the mouse pointer, or let the game take it again
- Right Amiga + S: a screenshot in the drawer's Screenshots
- Help: this game's keys (the drawer's Controls file)
- Right Amiga + F1, F2: F11, F12; Right Amiga + cursor keys: Page Up,
  Page Down, Home, End

The FULLSCREEN tooltype on the game's icon (take the brackets off) starts
it full screen.


Building
--------

GFOpenAmigaGCC 16.2.0-open4 or later, the OpenGPU developer kit and the
Team's static zlib:

    make -f amiga/Makefile.amigaos -j2 dist \
         STOVE=/path/to/openamigagcc-16.2.0-open4 \
         NDK=/path/to/OpenNDK/Include_H SDL2KIT=/path/to/opengpu-sdk \
         DEPS=/path/to/m68k-amigaos

Meson is not run: amiga/Makefile.amigaos has the game's source list and
definitions, and amiga/gen_defines.py makes src/defines.cpp as
tools/makedefs.sh would. fmt 10.2.1 and yaml-cpp 0.8.0 (both MIT) are
compiled in from amiga/deps. Output: build/amigaos/BlobWars (stripped;
.debug beside it); 'dist' makes dist/BlobWars/ and dist/BlobWars.info.


What was changed
----------------

- src/headers.h: no gettext on the Amiga (the game is in English); unistd.h
  for chdir() and access().
- src/init.cpp: the user's files go in the drawer's user/, not in
  $HOME/.parallelrealities/blobwars.
- src/main.cpp: main() first moves into the drawer (amiga/amiga_start.c)
  and closes at exit the screens SDL2.module 0.6 can leave
  (amiga/amiga_screens.c); no install directory to change to
  (PAKLOCATION is empty). amiga/stack.c: 512 KB of stack.
- The game's 8-bit RGB PNGs are stored as RGBA in the drawer
  (amiga/tools/png_rgba.py): OpenGPU's SDL2_image.module 0.6 damages the
  host's heap decoding some of them.
- src/loadSave.cpp, src/CConfig.cpp: a file that isn't there is noticed
  (!file, not file.bad(): a failed open sets failbit only). Upstream read
  the missing save slots, joystick.cfg and keyboard.cfg as if they were
  there; on Linux the struct happened to be zeros, here the save slots
  showed garbage.
- Built with -std=gnu++17 (upstream: c++17), -lsocket for SDL2_net, and
  -lpthread/-latomic for C++ threads and 64-bit atomics.


Licences
--------

Blob Wars' code and graphics: GPL 2 or later (COPYING.txt in the drawer).
Its music and sounds: CC BY-SA 3.0, CC BY 3.0, LGPL 2.1, BSD or GPL 2, per
file, as doc/readme lists. fmt and yaml-cpp: MIT (amiga/deps). The amiga/
files are the AmiCradle Team's, GPL 2 or later.
