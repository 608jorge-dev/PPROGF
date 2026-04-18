#!/usr/bin/env bash

# Recoger argumentos
FLAG=$1
CADENA=$2

# Validar que FLAG sea 0 o 1
if [ "$FLAG" != "0" ] && [ "$FLAG" != "1" ]; then
    echo "Error: el primer argumento debe ser 0 o 1"
    echo "Uso: $0 <0|1> [nombre_fichero_sin_extension]"
    exit 1
fi

if [ -z "$CADENA" ]; then

    for fichero in *_test.c; do
        nombre="${fichero%.c}"
        make "$nombre"

        if [ $? -ne 0 ]; then
            echo "Error al compilar $nombre"
            continue
        fi

        if [ "$FLAG" -eq 0 ]; then
            ./"$nombre"
        else
            valgrind --leak-check=full ./"$nombre"
        fi

    done

else

    make "$CADENA"

    if [ $? -ne 0 ]; then
        echo "Error al compilar $CADENA"
        exit 1
    fi

    if [ "$FLAG" -eq 0 ]; then
        ./"$CADENA"
    else
        valgrind --leak-check=full ./"$CADENA"
    fi

fi


