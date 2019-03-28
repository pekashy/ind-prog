# Industrial Programming Course

## FizzBuzz
A simple program that reads number sequence from command line and substracts numbers for fizz if they dividable by 3, buzz if they are dividable by 5 and fizzbuzz if they are dividable by 15.

Also provided travis.ci integration

#### Example
```fizzbuzz.py 111 222 333```

## Obfs
### Simple C code obfuscator
Transforms your code into the beginning of Douglas Adamses "The Hitchhiker's Guide to the Galaxy" book using defines.
Alpha unstable version
#### Usage
`python obfs.py *yourfilename.c*`
#### Example 
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
```
## Errcode

Finding problems in code excersize
