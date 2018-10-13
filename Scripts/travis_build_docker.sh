#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t utilforever/civilizationpp .
    docker run utilforever/civilizationpp
else
    docker build -f $1 -t utilforever/civilizationpp:$2 .
    docker run utilforever/civilizationpp:$2
fi