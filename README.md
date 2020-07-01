
<img style="float: right;" src="www/files/placa2.jpg">

xinu-avr is a Xinu operating system subset, modified to run on an AVR atmega328p microcontroller. At present, the core pieces of Xinu are working, 
and thus intended to be integrated in the development of multi tasking embedded systems (you will also need any bare AVR MCU, or Arduino board, of course).

The source code is comprise of:

1. The **Xinu OS** for AVR atmega328p (microkernel)
2. Basic examples (**apps**) of how to use Xinu
3. A complete example: **The Xinu shell** and ultra tiny versions of several **UNIX-like utilities** for AVR atmega328p: an editor, a basic interpreter, ps, kill, free, and some more


<a name="whatisxinu"></a>
### What is Xinu?

Xinu is a small, elegant, and easy to understand operating system, originally developed by Douglas Comer for instructional purposes at Purdue University in the 1980s. Since then it has been ported to many architectures and hardware platforms.
Xinu uses powerful primitives to provides all the componentes and the same functionality many conventional operating sytems supply. Since the whole source code size is small, Xinu is suitable for embedded systems.

<strong>The Xinu Operating System includes</strong>: dynamic process creation, dynamic memory allocation, real-time clock management, process coordination and synchronization, local and remote file systems, a shell, and device-independent I/O functions.  

Xinu is documented in the book:
[D. Comer, Operating System Design - The Xinu Approach, Second Edition CRC Press, 2015. ISBN 9781498712439](https://xinu.cs.purdue.edu/#textbook)

**IMPORTANT**: many sites defines Xinu as a free Unix system, or similar statements. It is not. Xinu differs completely from the internal structure of Unix (or Linux). For academic purposes Xinu is smaller, elegant, and easier to understand. Applications written for one system will not run on the other without modification. ** Xinu is not Unix **.

#### History

Xinu originally ran on Digital Equipment Corporation LSI 11's with only 64K bytes of memory, at the end of 1979 and the inning of 1980. Over the years Xinu versions Xinu have been expanded and ported to a wide variety of architectures and platforms, including: IBM PC, Macintosh, Digital Equipment Corporation VAX and DECStation 3100, Sun Microsystems Sun 2, Sun 3 and Sparcstations, and for several ARM, MIPS and x86 embedded boards. It has been used as the basis for many research projects. Furthermore, Xinu has been used as an embedded system in products by companies such as Motorola, Mitsubishi, Hewlett-Packard, and Lexmark. There is a full TCP/IP stack, and even the original version of Xinu (for the PDP-11) supported arbitrary processes and network I/O.

There are current versions of Xinu for Galileo Intel boards, ARM Beagle Boards, several MIPS platforms, and for x86 PC hardware and virtual machines.

<a name="code"></a>
### Xinu for AVR atmega328p available for download:

There is just one git repository, and it has everything. The list below is just for convenience:

* <a href="https://github.com/zrafa/xinu-avr">The Xinu OS for AVR atmega328p</a>
* <a href="https://github.com/zrafa/xinu-avr/apps">example apps</a>
* <a href="https://github.com/zrafa/xinu-avr/apps/shell">The xinu shell and tiny UNIX-like utilities (editor, basic interpreter, ps, kill, echo, uptime, sleep, etc)</a>
* <a href="https://xinu.cs.purdue.edu/">The official Xinu Page and Code</a>

<a name="authors"></a>
**Authors**:

* Xinu OS Copyright (c) 2012, 2015
  Douglas E. Comer and CRC Press, Inc.
* This version for AVR atmega328p v0.1 (c) 2020
  Rafael Ignacio Zurita <rafa@fi.uncoma.edu.ar>


<a name="xinuavr"></a>
### Xinu OS for AVR atmega328p

Current official Xinu versions are designed for ARM, MIPS and x86 architectures . The hardware differences between those and the ultra small AVR microcontroller required changes to some low-level data structures of Xinu, mainly using the FLASH memory in the AVR MCU, for keeping several read only data structures, previously in RAM. Also, several limits were imposed so those data structures fits into the SRAM AVR memory. The Xinu version for AVR atmega328p has the core functionality of Xinu, and provides some extensions, including an eeprom file system and several UNIX like utilities for the Xinu shell.


This MCU has just 2KB of SRAM, 32KB of FLASH memory, and 1KB of EEPROM. The Xinu version for AVR uses 17KB of FLASH and 0.9KB of RAM, so there is still room (SRAM and FLASH) for the embedded application running on Xinu (concurrent processes).

So this project might be stimulating and very fun for lovers of embedded systems development and operating system internals.

Notes about the port:

1. Max. number of processes (4 to 8)
2. main process is now the embedded application process
3. Max. number of semaphores (2 to 6) (the size of the table of process queues depends on this)
4. Max. number of devices (4 to 5)
4. The clkhandler() wakeup() a process (preemption) for CPU every 100ms
5. Several limits for buffers: 32bytes for tty input, 16bytes for names of devices, 1byte for the queues keys, and the list continues
6. sleepms() is now delay sleep100ms()
7. Many vars in data structures have a smaller size (e.g. before:int32, now:char)
8. sleep sleeps max. 20 seconds (date type)
9. most of the libc are from avr-libc
10. init (load bss and data from flash to ram) from avr-libc
11. shell manages max. 6 tokens
12. date and time is managed by a little lib. No NTP or RTC
13. Most of the const char in source code was moved to FLASH (program space) via __flash directive from gcc, or PROGMEM from avr-libc

**Acknowledgments**

* Michael M. Minor: he is the author of another AVR port os Xinu (<a href="https://sites.google.com/site/avrxinu/">avrxinu</a>. We use his context switch code, the addargs in Xinu shell, and a few lines more. His port is for bigger AVR microcontrollers (16KB+ of RAM), and he used an old version of Xinu (from the 1st book edition).
 

<a name="douglas"></a>
### Douglas Comer

Douglas Comer is a Professor of Computer Science at Purdue University who
was inducted into the Internet Hall of Fame on September, 2019.

[Douglas Comer Page](https://www.cs.purdue.edu/homes/comer/)

[Internet Hall of Fame](https://www.cs.purdue.edu/news/articles/2019/comer_ihof.html)

As one of the earliest TCP/IP and internetworking researchers, Comer wrote the first series of textbooks explaining the scientific principles underlying the design of the Internet and its communications protocols, providing some of the earliest formal guidance for building efficient networks and applications that use the Internet. 

Comer's three-volume textbook series, Internetworking with TCP/IP, written in 1987, is widely considered to be the authoritative reference for Internet protocols. The series played a key role in popularizing Internet protocols by making them more understandable to a new generation of engineers and IT professionals.




<a name="lab"></a>
### Getting started
Xinu is easy of understand, so a developer can obtain a copy 
of the system to examine, modify, instrument, measure, extend, or transport it to another architecture.

