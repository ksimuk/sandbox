# Gentoo Sandbox for Codio

We use the sandbox from [Gentoo] and compile it manually from the source in
in `sandbox-2.6.tar.xz`.

## Compiling

Same basic instructions on how to compile taken from the [Debian wiki].

Unpack the source using

```bash
$ tar -xfv sandbox-2.6.tar.xz
```
then go into the directory and `./configure`:

```bash
$ cd sandbox-2.6
$ ./configure
```

Look at the Output: Maybe you will find follow row:

```bash
checking for gawk... no
checking for mawk... mawk
```

sandbox can't compile with mawk, so you need gawk. If you see the rows above
you have to install gawk

```bash
$ apt-get install gawk
```

and then execute `./configure` again. Now, you should find this raw on output

```bash
checking for gawk... gawk
```

If you see this line, and no line with "mawk", everything is ok.

Since sandbox comes from gentoo, it want's to have its config in `/usr/etc`.
But debian-software have its config in `/etc/`, so we want to tell sandbox to use
its config on this place. There are 2 options:

* Use `/etc/` as config-dir. Then sandbox would have `/etc/sandbox.conf` as primary configfile
  and `/etc/sandbox.d/` as directory for additional configfiles.
* or we use `/etc/sandbox/` as config-dir. Than we have `/etc/sandbox/sandbox.conf` and `/etc/sandbox/sandbox.d/`

both would go with debian-conventions, so its your decission.

For the first way simply execute

```bash
$ ./configure --sysconfdir=/etc/
```

Now we are ready to build and install sandbox just type

```bash
$ make && make install
```
if the make-process is completed, you can use sandbox. When you type `sandbox`, it starts with a default-shell.
Also you can `sandbox [command]` if you want to start something other with sandbox.

## Configuration

`/var/log/sandbox` needs to be writable by everyone.


```bash
# config /etc/sandbox.d/00default

SANDBOX_READ="/bin:/lib:/lib64:/sbin:/sys:/usr:/var:/dev:/run:/etc/passwd:/etc/hosts:/etc/nsswitch.conf:/tmp/:/var/tmp/"
SANDBOX_READ="/proc:/etc/python2.7:/etc/mime.types:/etc/mailname:/etc/ssl:/etc/ssh:/etc/services:/etc/pkcs11"

SANDBOX_WRITE="${SANDBOX_ISOLATE}"
SANDBOX_READ="${SANDBOX_ISOLATE_READONLY}"
SANDBOX_READ="${SANDBOX_ISOLATE}"
SANDBOX_WRITE="/var/log/sandbox"
```

RPC sets the two environemnt variables `SANDBOX_ISOLATE` and `SANDBOX_ISOLATE_READONLY`.
By default RPC sets the working directory and the home direcotry for the command to be
writable and the directory with our scripts to be readable. All git commands have
to set the master branch to be writable even if it is not used because all
branches use symbolic links to master.

We have to use the wrapper for handling quoting issues. It's in `wrapper.sh`.

[Gentoo]: http://www.gentoo.org/
[Debian wiki]: https://wiki.debian.org/Sandbox
