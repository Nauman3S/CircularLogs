<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="temp/circularLogs.png" alt="Project logo"></a>
</p>

<h3 align="center">Circular Logs</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()


</div>

---


<p align="center"> Circular Logs
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Prerequisites](#deployment)
- [Installation and Config](#Installation_and_Config)
- [Test/Usage](#test)
- [Built Using](#built_using)
- [Authors](#authors)

## 🧐 About <a name = "about"></a>

This repo contains C program Circular Logs task.

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for testing.

### Prerequisites <a name = "Prerequisites"></a>

Things you need to install the program.

```
- Debain Based Distro(Ubuntu/Raspberry Pi OS etc.)
```

## Installation and Configuration <a name = "Installation_and_Config"></a>

A step by step series that covers how to get the program running.

### Installation

1.  Open the terminal in the root directory of this repo and execute the following command
   
    ```make install```
2. Now you can compile the program using

    ```make all```

## ⛏️ Testing/Usage <a name = "test"></a>

The program can be tested on any Debian based Linux distribution with gcc and make.

To run the program simply execute the following command in the root directory of this repo

``make run``

### Usage

You can enter any keys on the keyboard and they will get logged to an char array LogEntriesStr which has a default size of 500(can be changed in CircularLogs.h file). On pressing 'S' (capital S) key on keybaord a new log file with latest 100 log entries will be saved in the logs directory of this repository.

Once the LogEntriesStr fills out completely, the program starts overwriting the array from index 0 so that buffer overflow doesn't occur and the program should mimic limited flash memory scenario.

## Libraries Used

1.  ncurses(for getting the individual key presses from stdin){getc and other standard I/O fucntions waits until \n is pressed while getch of ncurses can read any key press event}
2.  stdio(for File realted operations)
3.  stdlib(for sizof and other related functions)
4.  cstring(for memcpy)
5.  time(for getting system clock time in ms)

## ⛏️ Demo <a name = "demo"></a>

A demo video is also provided in the root directory of this repository. The demo video shows the working of the program and how log files are generated.

## ⛏️ Built Using <a name = "built_using"></a>

- [C](#) - C Programming Language
- [gcc](#) - Standard C compiler
- [VSCode](#) - IDE

## ✍️ Authors <a name = "authors"></a>

- [@Nauman3S](https://github.com/Nauman3S) - Development