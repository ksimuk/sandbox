#!/bin/bash

# A wrapper around the sandbox command that resolves all
# quoting issues when passing a command like `git commit -a -m "long message"
# to the sandbox command.
#
# Usage: ./wrapper <command that should be executed safely>

# This will hold the escaped command
command=""

# Iterate through all the passed in arguments
for arg in "$@"
do
    # Escape single quotes
    val=$(printf "%s" "$arg" | sed -e "s/'/'\"'\"'/g")
    # Wrap into single quotes and escape
    val=$(printf "%q" "'$val'")
    # Append to the other commands
    command="$command$val "
done

# Prefix with `sandbox`
command="sandbox $command"

# Execute
eval "$command"
