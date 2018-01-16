#!/bin/bash
# hi_low a simple number guessing game

BIGGEST=10
GUESS=0
GUESSES=0
NUMBER=$(( $$ % $BIGGEST ))

while [ $GUESS -ne $NUMBER ] ; do
	echo -n "Guess?  "; read GUESS
	if [ "$GUESS" -lt $NUMBER ] ; then
		echo ". . . bigger!"
	elif [ "$GUESS" -gt $NUMBER ] ; then
		echo ". . . smaller!"
	fi
	GUESSES=$(( $GUESSES + 1 ))
done

echo "Right!! Guessed $NUMBER in $GUESSES guesses."

exit 0
