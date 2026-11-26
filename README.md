# Tarea 2 - Creacion de un hilo con pthread

Programa en C que crea un hilo con la biblioteca POSIX `pthread`.
El hilo principal imprime del 1 al 10,000 y el hilo secundario del 10,000 al 1.

- `hilos.c`: codigo fuente
- `salida.txt`: salida de la ejecucion en Debian 13 (Trixie)

Compilar: `gcc -Wall -Wextra -pthread -o hilos hilos.c`

Ejecutar: `./hilos > salida.txt`
