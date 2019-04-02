
# zpkg
With zpkg you can install and use programs from other distributions


## Install
```
$ curl -Lf https://github.com/ihucos/zpkg/releases/download/0.1/zpkg.zpkg | tar -xJf - -C ~/.local   # user
$ curl -Lf https://github.com/ihucos/zpkg/releases/download/0.1/zpkg.zpkg | tar -xJf - -C /usr/local # global
```

## Usage
```
USAGE
    zpkg [-g] {add,package,ls,clear,rm} ...

SUBCOMMANDS
    add [PKG] BUILD-ARGS   builds and adds a package
    clear                  clean build cache
    ls                     lists all installed packages
    package PKG FILE       creates an universal package
    rm PKG                 uninstalls the given package

ARGUMENTS
    --global, -g
        affects the system globally

BUILD ARGUMENTS
    --from, -f
        choose a base image
    --run, -x
        run any shell (/bin/sh) command
    --layer, -l
        adds a layer for build caching
    --from-github
        build according to instructions at GitHub project
    --add-apt-repository, --apt, --apk, --apt, --dnf, --emerge, --npm,
    --pacman, --pip, --pip3, --yum
        Invokes the given tool with it's primary action
    -A  same as `--from alpine --apk`
    -C  same as `--from centos --yum`
    -D  same as `--from debian --apt`
    -F  same as `--from fedora --dnf`
    -G  same as `--from gentoo --emerge`
    -R  same as `--from archlinux --pacman`
    -U  same as `--from ubuntu --apt`

EXAMPLE
    zpkg add xeyes -U x11-apps
    zpkg add -A gimp
    zpkg add -A py3-pip --pip3 yapf
    zpkg rm yapf
```

## Use cases
* Using applications from other distributions
* Installing applications with unprivileged users
* Distribute applications (zpkg package)
* Deploy applications (zpkg package)
* Having distribution independent application in your home folder (e.G. for a USB stick)

## Limitations
There is the assumption, that installed packages should not change files that existed before they where installed, because of hard linking layers to an unified root file system on a per package basis. Note that something like "System Programs" may not work. As an example: Bash, synaptic, apt, or gnome-tweak-tool may not work as desired. LibreOffice, Firefox, Gimp or pylint work fine. So this is mainly for something like end user programs.

## How stable?
Beta

## How dos it work
The heavy lifting is done by [plash](https://github.com/ihucos/plash).

## Installing Ubuntu/Debian packages is not working
`apt` needs setuid/setgid support. For this to work for unprivileged users, you need to install newuidmap/newguidmap (possibly a package named `uidmap`). And have `/etc/subuid` and `/etc/subgid` with some subuids and subgids for your user (already there on Ubuntu)

## Why?
There are too many package managers, so I wrote another one.

## Enjoy
![jumping man](https://user-images.githubusercontent.com/2066372/55283225-018fb980-5356-11e9-895e-f65965f5ccbd.jpg)
