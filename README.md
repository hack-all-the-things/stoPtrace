# stoPtrace
A basic C library that can disable / enable the ptrace function globally


* To install (requires root):

  make all
  
  make install



* To re-enable debugging:

  user@host $ sudo touch /etc/allow-debug

* To disable debugging again:

  user@host $ sudo rm -vf /etc/allow-debug


Note: It requires root access to disable/enable debugging globally.


# Todo
* Add an initialization hook for processes to register a signal handler for SIGTRAP and SIGSTOP
* Create configurable blacklists/whitelists for debugging configuration
