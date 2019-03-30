
# zpkg
With zpkg you can install and use programs from other distributions


## Installation
```
$ curl --fail --location https://raw.githubusercontent.com/ihucos/zpkg/master/install.sh | sh
$ sudo apt install unionfs-fuse # you need python3 and unionfs-fuse
```

## Usage
```
USAGE
    zpkg [-g] {add,package,ls,clear,rm} ...

SUBCOMMANDS
    add [PKG] BUILD-ARGS   builds and adds a package
    clear                  clean build cache
    ls                     lists all installed packages
    package PKG FILE       creates an installabe package
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
## Built With

* [bchroot](https://github.com/ihucos/bchroot) - chroot like tool
* [plash](https://github.com/ihucos/plash) - Containerization tool

## Why?
There are too many package managers, so I wrote another one.

## How does it work
Sweet kittens are washed and dried with unicorn powder. Some glitter is added, but it should not reach a state of too much. Furthermore dolpins are asked for their magical wisdom and that input is fitted into the the food the kitten would usually eat. But it's actually only used to make them hungry and then you eat it yourself. By doing so you can get superpowers for exactly 10 seconds, so this procedure has to be repeated several times, many unicorns had to die.

## Limitations
It is unfailable. I rememeber some assumption that installed packages should not change files that existed before they where installed, because of hard linking layers to a unified root filesystem. Note that this whole thing is useful for programs that alter state in you home directory, the pixels in you screen or stuff with internet data. Something like "System Programs" may not work. As an example Libre Office, Firefox, Gimp or pylint work fine.
