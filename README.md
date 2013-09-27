# Gentoo Sandbox for Codio

We use sandbox from gentoo, compiled manually that can be found in `sandbox-2.6.tar.xz`.
Some info about compiling it: https://wiki.debian.org/Sandbox
(don’t forget to install gawk for compiling)

`/var/log/sandbox` needs to be writable by everyone.


```bash
#config /etc/sandbox.d/00default

SANDBOX_READ="/bin:/lib:/lib64:/sbin:/sys:/usr:/var:/dev:/run:/etc/passwd:/etc/hosts:/etc/nsswitch.conf:/tmp/:/var/tmp/"
SANDBOX_READ="/proc:/etc/python2.7:/etc/mime.types:/etc/mailname:/etc/ssl:/etc/ssh:/etc/services:/etc/pkcs11"

SANDBOX_WRITE="${SANDBOX_ISOLATE}"
SANDBOX_READ="${SANDBOX_ISOLATE_READONLY}"
SANDBOX_READ="${SANDBOX_ISOLATE}"
SANDBOX_WRITE="/var/log/sandbox"

```

RPC sets `SANDBOX_ISOLATE` and `SANDBOX_ISOLATE_READONLY`.
By default RPC sets working directory and home dir for the command to be writable and the directory with
our scripts to be readable. All git commands have to set master branch to be writable even if it is not used because all
branches use symbolic links to master.

We have to use the wrapper for handling quoting issues. It's in `wrapper.sh`.

