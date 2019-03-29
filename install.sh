#!/bin/sh

set -eux

HOME=~
INSTALL_TO="$HOME/.local"
tmp=$(mktemp -d)
mkdir -p "$tmp/bin" "$tmp/lib/zpkg"
curl -Lf https://github.com/ihucos/plash/archive/master.tar.gz | tar -xzC          $tmp/lib/zpkg plash-master/opt/plash --strip-components=2
curl -Lf https://github.com/ihucos/bchroot/releases/download/0.3/bchroot >         $tmp/lib/zpkg/bchroot
curl -Lf https://raw.githubusercontent.com/ihucos/zpkg/master/zpkg >               $tmp/lib/zpkg/zpkg
curl -Lf https://raw.githubusercontent.com/ihucos/zpkg/master/bootstrap.sh >       $tmp/lib/zpkg/bootstrap.sh
chmod +x $tmp/lib/zpkg/bchroot
chmod +x $tmp/lib/zpkg/zpkg
chmod +x $tmp/lib/zpkg/bootstrap.sh
ln -s  "$INSTALL_TO/lib/zpkg/zpkg/zpkg" $tmp/bin/zpkg
echo $tmp

mkdir -p $INSTALL_TO/lib/zpkg/zpkg $INSTALL_TO/bin

rm -rf $INSTALL_TO/lib/zpkg/zpkg
mv $tmp/lib/zpkg $INSTALL_TO/lib/zpkg/zpkg
mv $tmp/bin/zpkg $INSTALL_TO/bin/zpkg
