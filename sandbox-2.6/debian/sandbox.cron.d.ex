#
# Regular cron jobs for the sandbox package
#
0 4	* * *	root	[ -x /usr/bin/sandbox_maintenance ] && /usr/bin/sandbox_maintenance
