
# zpkg
Is a meta package manager. Use any package manager in any Linux distribution.


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


## Why does it work
yadda yadda
