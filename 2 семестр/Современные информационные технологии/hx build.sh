#!/bin/sh

case"$1" in
    build)
    gcc main.c add.c
    ;;
    run)
    ./a.out
    ;;
    clean)
    rm a.out ./*.o
    ;;
    *)
    ;;
esac