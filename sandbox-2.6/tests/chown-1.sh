#!/bin/sh
# make sure symlinks with chown() work properly

addwrite $PWD

rm -rf deny link
(
set -e
mkdir deny
touch deny/file
ln -s deny/file link
) || exit 1

# this *should not* trigger a sandbox violation
chown-0 0 link ${SB_UID} ${SB_GID} || exit 1

# this *should* trigger a sandbox violation
adddeny $PWD/deny
chown-0 -1 link ${SB_UID} ${SB_GID} || exit 1
test -s sandbox.log
