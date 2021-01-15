Control node serial interface
=============================


Send and receive messages to the control node. Should be used with the code
from the [iot-lab-gateway](https://github.com/iot-lab/iot-lab-gateway)
repository.
Receive measures packets and errors messages from the control node.

Interactions are done through stdin and stdout.


Measures handling
-----------------

Current received measures types are deducted from commands sent before.
Handles packets decoding.


Compiling
=========

Install 'oml' as described in [OML.md](OML.md)

Testing
=======

Run `make test coverage`
