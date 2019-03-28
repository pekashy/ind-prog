# Simple C code obfuscator
Transforms your code into the beginning of Duglas Adamses "The Hitchhiker's Guide to the Galaxy" book using defines.
Alpha unstable version
## Usage
`python obfs.py *yourfilename.c*`
## Example 
`python obfs.py alg2.c`

Gives us:

main.c:
```#include "out.h"
#include <stdio.h>
the hitch hikers guide to galaxy douglas adams c restaurant at end of universe life and...
```

and out.h:
```
#define unhappyand ideathis
#define backwaters clare
#define thisgod toget
#define remained wasnt
#define since happened
...
`

