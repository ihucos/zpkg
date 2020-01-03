#!/bin/sh
set -xeu
. /etc/os-release

case $ID in

alpine)
  apk add ttf-freefont
  ;;

esac
