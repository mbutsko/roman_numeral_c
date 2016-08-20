Roman Numeral Arithmetic
========================

This is a simple implementation of roman numeral addition and subtraction.

### Usage ###
roman_math takes three arguments in an infix order; an operand, followed by an 
operator, followed by a second operand.


Development
-----------

### Build ###
> make

### Test ###
Tests are generated with checkmk, which you will need to have available. The 
easiest way is to use the dockerfile, then inside of your container run:
> make test
