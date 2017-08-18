# ft_p 

This project is about creating a client and a FTP server (File Transfer Protocol) that
allows you to send and receive files between one or many clients and the server.

## Getting Started

To use the server and client for learning or use clone it locally.

### Prerequisites

What things you need to install the software and how to install them

```
gcc or clang compiler
```

### Installing

Installing just requires a clone or download


```
git clone https://github.com/afullstopdot/ft_p.git on terminal or download the zip straight from here.
```

## Compiling the library

For use

### Break down into end to end tests

Compile the library for use, using the Makefile

```
make all
```

Remove the object files

```
make clean
```

Remove the libft library

```
make fclean
```

Remove the library and recompile

```
make re
```

Additionally, for checking WeThinkCode_ / 42 norm

```
make norm
```

## Server usage

```
./server port &
```

Where “port” is the port number.

## Client usage

```
./client server port
```

Where “server” is the name of the hosting machine on which your server is, and “port” the port number.

### The client understands the following commands

```
ls : list in the current server’s directory
```
```
cd : change the current server’s directory
```
```
get _file_ : download the file _file_ from the server to the client
```
```
put _file_ : upload the file _file_ from the client to the server
```
```
pwd : display the path of the current server’s directory
```
```
quit : cuts the connection + exit the program
```

## Authors

* **Andre Marques** - *All* - [afullstopdot](https://github.com/afullstopdot)
* **goisetsi** - *All* - [goisetsi](goisetsi)
* **** - *All* - [afullstopdot](https://github.com/afullstopdot)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Disclaimer

This message pertains to the students of 42 and WTC (WeThinkCode_).

Copying this work as is, without understanding and being able to implement your own work defeats the pedagogy and subsequently is cheating.

Goodluck!
