import time
import RPi.GPIO as GPIO

LEDRED = 17
RBUTTON = 2
LEDGREEN = 3
GBUTTON = 12

GPIO.setmode(GPIO.BCM)

GPIO.setup(LEDRED, GPIO.OUT)
GPIO.setup(LEDGREEN, GPIO.OUT)

GPIO.setup(RBUTTON, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
GPIO.setup(GBUTTON, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)

while True:
    redstate = GPIO.input(RBUTTON)
    if redstate == GPIO.LOW:
        GPIO.output(LEDRED, GPIO.HIGH)
    else:
        GPIO.output(LEDRED, GPIO.LOW)
    
    gstate = GPIO.input(GBUTTON)
    if gstate == GPIO.LOW:
        GPIO.output(LEDGREEN, GPIO.HIGH)
    else:
        GPIO.output(LEDGREEN, GPIO.LOW)
        
GPIO.cleanup()