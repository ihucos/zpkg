
# zpkg
Is a meta package manager. Use any package manager in any Linux distribution.


### Getting started

```
$ curl --fail --location https://raw.githubusercontent.com/ihucos/zpkg/master/install.sh | sh
$ sudo apt install python3 unionfs-fuse # you need python3 and unionfs-fuse
$ zpkg add -A libreoffice
$ libreoffice
```

### Usage
```
usage: zpkg [-g] {add,package,ls,clear,rm} ...

Subcommands:
    add [PKG] BUILD-ARGS   Builds and adds a package
    clear                  Clean build cache
    ls                     Lists all installed packages
    package PKG FILE       Creates an installabe package
    rm PKG                 Uninstalls the given package

Global Arguments:
    --global, -g
        Affects the system globally

Some Build Arguments:
    --from, -f
        choose a base image
    --from-url
        use a tar file over http as base image
    --run, -x
        run any shell (/bin/sh) command
    --layer, -l
        adds a layer for build caching
    --from-github
        build according to instruction at github project
    --apt, --apk, --apt, --defpm, --dnf, --emerge, --npm, --pacman, --pip,
    --pip3, --yum
        Invokes the given tool with it's primary action
    -A  same as `--from alpine --apk`
    -C  same as `--from centos --yum`
    -D  same as `--from debian --apt`
    -F  same as `--from fedora --dnf`
    -G  same as `--from gentoo --emerge`
    -R  same as `--from archlinux --pacman`
    -U  same as `--from ubuntu --apt`

Example:
    $ zpkg add xeyes -U x11-apps
    $ zpkg add -A gimp # implicit command name
    $ zpkg ls
    gimp
    xeyes
    $ zpkg rm xeyes
    $ gimp
```
