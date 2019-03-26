#!/bin/sh

set -eux

ALPINE_URL="http://dl-cdn.alpinelinux.org/alpine/v3.9/releases/x86_64/alpine-minirootfs-3.9.2-x86_64.tar.gz"

tmp="$(mktemp -d)"
mkdir --parents "$tmp/bin/rootfs"

curl -'#' --location --fail "https://github.com/ihucos/bchroot/releases/download/0.3/bchroot" > $tmp/bchroot
chmod 744 $tmp/bchroot

curl -'#' --location --fail $ALPINE_URL | tar -xzf - -C "$tmp/bin/rootfs"

# redunancy, bchroot already attempts and bind mount
rm -f $tmp/bin/rootfs/etc/resolv.conf
cp /etc/resolv.conf $tmp/bin/rootfs/etc/resolv.conf

echo "#/bin/sh
cd $tmp/bin/rootfs
find ./usr/local/bin ./usr/bin ./bin ./usr/local/sbin ./usr/sbin ./sbin 2> /dev/null \
| xargs -n 1 basename | sort | uniq \
| xargs -I{} sh -c \"ln -f $tmp/bchroot $tmp/bin/{}\"
" > "$tmp/bin/mypkg-update"
chmod +x "$tmp/bin/mypkg-update"
"$tmp/bin/mypkg-update"

# install plash dependencies
"$tmp/bin/apk" add python3 unionfs-fuse gnupg bash

# install plash
curl -Lf https://github.com/ihucos/plash/archive/master.tar.gz | "$tmp/bin/tar" -xzC / --strip-components=1

"$tmp/bin/mypkg-update"
